# VELOC: VEry-Low Overhead Checkpointing system

VELOC Experimental Branch

The VELOC project aims to provide a framework offering a
checkpoint/restart interface and providing transparently the benefit
of multilevel checkpointing to exascale applications. VELOC is a
collaboration between Argonne National Laboratory and Lawrence
Livermore National Laboratory as part of the Exascale Computing
Project.


## VELOC API

This implementation of VELOC software is based on VELOC API (version
0.4 currently).The VELOC API can be obtained from the
https://xgitlab.cels.anl.gov/ecp-veloc/Veloc-Documentation.git

## Quickstart

For now, VELOC has to be build from source. The first step is to
clone the VELOC git repository: 

```shell
git clone git@xgitlab.cels.anl.gov:ecp-veloc/veloc.git

In terms of dependencies, VELOC requires boost 1.60 or newer and CMake
3.8 or newer. VELOC has a convenience script to install the latest
Boost version. Change the "PREFIX" environment variable in the script
to point to the directory where Boost needs to be installed, then
launch the script:

```shell
./install_boost.sh

Next step is to configure VELOC. Again, there is a corresponding
convenience script where the installation PREFIX needs to be specified.

```shell
./configure.sh

Finally, run "make" to build VELOC.

## Testing

We currently test three ways to interact with the VeloC API:

- Memory interface
- File-based interface
- A hybrid interface mixing memory-interface and file-based interface paradigms

There are two test applications in the "test" subdirectory which illustrate
how to use the memory based and file based API.

## Contacts

In case of questions and comments or help, please contact the VELOC
team at ecp-veloc@lists.mcs.anl.gov
