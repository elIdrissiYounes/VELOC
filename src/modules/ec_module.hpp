#ifndef __EC_MODULE_HPP
#define __EC_MODULE_HPP

#include "common/config.hpp"
#include "common/command.hpp"

#include <vector>
#include <mpi.h>

class ec_module_t {
    config_t cfg;
    MPI_Comm comm, comm_domain;
    std::string fdomain;
    int scheme_id;
public:
    ec_module_t(const config_t &c, MPI_Comm cm);
    ~ec_module_t();

    int process_commands(int command, const std::vector<command_t> &cmds);
};

#endif //__EC_MODULE_HPP
