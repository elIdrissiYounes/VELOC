#ifndef __COMMAND_HPP
#define __COMMAND_HPP

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <thallium.hpp>
#include <thallium/serialization/stl/array.hpp>
#include <thallium/serialization/stl/list.hpp>
#include <thallium/serialization/stl/string.hpp>
#include <thallium/serialization/stl/pair.hpp>
#include <thallium/serialization/stl/complex.hpp>
#include <thallium/serialization/stl/map.hpp>
#include <thallium/serialization/stl/set.hpp>
namespace tl=thallium;
class command_t {
	public:
		static const size_t MAX_SIZE = 128;
		static const int INIT = 0, CHECKPOINT = 1, RESTART = 2, TEST = 3;

		int unique_id, command, version;
		char name[MAX_SIZE] = {}, original[MAX_SIZE] = {};
		command_t() { }
		template <typename A> 
			void serialize(A& ar){
				std::string sn(name), orr(original);
				ar & this->unique_id;
				ar & this->command;
				ar & this->version;
				ar & sn;
				ar & orr;
			}

		command_t(int r, int c, int v, const std::string &s) : unique_id(r), command(c), version(v) {
			if (s.length() > MAX_SIZE)
				throw std::runtime_error("checkpoint name '" + s + "' is longer than admissible size " + std::to_string(MAX_SIZE));
			//s.c_str()
			std::strcpy(name ,s.c_str());
		}
		std::string stem() const {
			return std::string(name) + "-" + std::to_string(unique_id) +
				"-" + std::to_string(version) + ".dat";
		}
		std::string filename(const std::string &prefix) const {
			return prefix + "/" + stem();
		}
		std::string filename(const std::string &prefix, int new_version) const {
			return prefix + "/" + name +
				"-" + std::to_string(unique_id) + "-" +
				std::to_string(new_version) + ".dat";
		}
		friend std::ostream &operator<<(std::ostream &output, const command_t &c) {
			output << "(Rank = '" << c.unique_id << "', Command = '" << c.command
				<< "', Version = '" << c.version << "', File = '" << c.stem() << "')";
			return output;
		}
		//thallium serialization
       
};
/*template<typename A>
void serialize(A& ar,command_t& x){

				ar & x.MAX_SIZE;
                                ar & x.INIT;
                                ar & x.CHECKPOINT;
                                ar & x.RESTART;
                                ar & x.TEST;
                                ar & x.unique_id;
                                ar & x.command;
                                ar & x.version;
                                ar & x.name;
                                ar & x.original;



}*/
#endif // __COMMAND_HPP
