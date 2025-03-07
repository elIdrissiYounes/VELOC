#ifndef __CLIENT_HPP
#define __CLIENT_HPP

#include "common/config.hpp"
#include "common/command.hpp"
#include "modules/module_manager.hpp"

#include <unordered_map>
#include <map>
#include <set>
#include <deque>
namespace tl=thallium;
class veloc_client_t {
	config_t cfg;
	MPI_Comm comm;
	bool collective, ec_active;
	int max_versions;
	typedef std::pair <void *, size_t> region_t;
	typedef std::map<int, region_t> regions_t;
	typedef std::map<std::string, std::deque<int> > checkpoint_history_t;

	tl::engine engine_client;
	tl::remote_procedure wait_completion;
	tl::remote_procedure init;
	tl::remote_procedure enqueue;
	tl::endpoint server;
	tl::provider_handle ph;
	regions_t mem_regions;
	checkpoint_history_t checkpoint_history;
	command_t current_ckpt;
	int rank;
	bool checkpoint_in_progress = false;    

	module_manager_t *modules = NULL;

	int run_blocking(const command_t &cmd);

	public:

	veloc_client_t(MPI_Comm comm, const char *cfg_file);
	void cleanup();

	bool mem_protect(int id, void *ptr, size_t count, size_t base_size);
	bool mem_unprotect(int id);
	std::string route_file(const char *original);

	bool checkpoint_begin(const char *name, int version);
	bool checkpoint_mem();
	bool checkpoint_end(bool success);
	bool checkpoint_wait();

	int restart_test(const char *name, int version);
	bool restart_begin(const char *name, int version);
	bool recover_mem(int mode, std::set<int> &ids);
	bool restart_end(bool success);

	~veloc_client_t();
};

#endif
