#ifndef __IPC_QUEUE_HPP
#define __IPC_QUEUE_HPP

#include "status.hpp"
#include <list>
#include <string>
#include <unordered_map>
#include <thallium/serialization/stl/string.hpp>
#include <thallium.hpp>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std::placeholders;

//#define __DEBUG
#include "common/debug.hpp"

namespace veloc_ipc {
	namespace tl =thallium;

	typedef std::function<void (int)> completion_t;
	//add the cleanup
	inline void cleanup() {

	}


	template <class T> class shm_queue_t: public tl::provider<shm_queue_t<T>> {
		static const size_t MAX_SIZE = 1 << 20;
		struct container_t {
			typedef std::list<T> list_t;
			int status = VELOC_SUCCESS;
			list_t pending, progress;
			container_t() : pending(), progress() { }



		};
		typedef typename container_t::list_t::iterator list_iterator_t;

		std::unordered_map<std::string,container_t> segment;
		std::mutex mutex_;
		std::condition_variable cond_;
		container_t *find_non_empty_pending() {
			for (auto it = segment.begin(); it != segment.end(); ++it) {
				container_t *result = &it->second;
				if (!result->pending.empty())
					return result;
			}
			return NULL;
		}
		bool check_completion(string id) {
			// this is a predicate intended to be used for condition variables only
			return segment.find(id)->second.pending.empty() && segment.find(id)->second.progress.empty();
		}
		void set_completion(container_t *q, const list_iterator_t  &it, int status) {
			// delete the element from the progress queue and notify the producer
			DBG("completed element " << *it);
			q->progress.erase(it);
			if (q->status < 0 || status < 0)
				q->status = std::min(q->status, status);
			else
				q->status = std::max(q->status, status);
		}
		void enqueue(const T &e,string id) {
			// enqueue an element and notify the consumer
			container_t data;
			std::unique_lock<std::mutex> mlock(mutex_);
			(data.pending).push_back(e);
			//std::make_pair<std::string, container_t>(string(id), data)
			segment.emplace(id,data);
			mlock.unlock();
			cond_.notify_one();
			DBG("enqueued element " << e);
		}
		public:    
		shm_queue_t(tl::engine& e, uint16_t provider_id=22) : 
			tl::provider<shm_queue_t<T>>(e,provider_id),segment()	{

				this-> define("enqueue",&shm_queue_t::enqueue,tl::ignore_return_value());
				this-> define("wait_completion",&shm_queue_t::wait_completion);

			}
		int wait_completion(bool reset_status, std::string id) {
			while (!check_completion(id));
			int ret;
			auto best=segment.find(id);
			container_t tt=(container_t)best->second;
			ret= tt.status;
			if (reset_status)
				tt.status = VELOC_SUCCESS;
			return ret;
		}

		completion_t dequeue_any(T &e) {
			// wait until at least one pending queue has at least one element
			std::unique_lock<std::mutex> mlock(mutex_);
			container_t *first_found;
			while(segment.empty()||
			(first_found = find_non_empty_pending())==NULL){
				cond_.wait(mlock);
			}
			e = first_found->pending.front();
			first_found->pending.pop_front();
			first_found->progress.push_back(e);
			DBG("dequeued element " << e);
			return std::bind(&shm_queue_t<T>::set_completion, this, first_found, std::prev(first_found->progress.end()), _1);
		}
		size_t get_num_queues() {
			return segment.size();
		}
	};

};

#endif // __IPC_QUEUE_HPP
