# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/younes/anl-veloc/VELOC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/younes/anl-veloc/VELOC

# Include any dependencies generated for this target.
include test/CMakeFiles/heatdis_file.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/heatdis_file.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/heatdis_file.dir/flags.make

test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o: test/CMakeFiles/heatdis_file.dir/flags.make
test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o: test/heatdis_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/younes/anl-veloc/VELOC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o"
	cd /home/younes/anl-veloc/VELOC/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/heatdis_file.dir/heatdis_file.c.o   -c /home/younes/anl-veloc/VELOC/test/heatdis_file.c

test/CMakeFiles/heatdis_file.dir/heatdis_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heatdis_file.dir/heatdis_file.c.i"
	cd /home/younes/anl-veloc/VELOC/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/younes/anl-veloc/VELOC/test/heatdis_file.c > CMakeFiles/heatdis_file.dir/heatdis_file.c.i

test/CMakeFiles/heatdis_file.dir/heatdis_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heatdis_file.dir/heatdis_file.c.s"
	cd /home/younes/anl-veloc/VELOC/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/younes/anl-veloc/VELOC/test/heatdis_file.c -o CMakeFiles/heatdis_file.dir/heatdis_file.c.s

test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.requires:

.PHONY : test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.requires

test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.provides: test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.requires
	$(MAKE) -f test/CMakeFiles/heatdis_file.dir/build.make test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.provides.build
.PHONY : test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.provides

test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.provides.build: test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o


# Object files for target heatdis_file
heatdis_file_OBJECTS = \
"CMakeFiles/heatdis_file.dir/heatdis_file.c.o"

# External object files for target heatdis_file
heatdis_file_EXTERNAL_OBJECTS =

test/heatdis_file: test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o
test/heatdis_file: test/CMakeFiles/heatdis_file.dir/build.make
test/heatdis_file: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
test/heatdis_file: src/lib/libveloc-client.so
test/heatdis_file: src/modules/libveloc-modules.so
test/heatdis_file: /home/younes/anl-veloc/install/lib/libaxl.so
test/heatdis_file: /home/younes/anl-veloc/install/lib/liber.so
test/heatdis_file: /home/younes/anl-veloc/install/lib/librankstr.so
test/heatdis_file: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi_cxx.so
test/heatdis_file: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
test/heatdis_file: test/CMakeFiles/heatdis_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/younes/anl-veloc/VELOC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable heatdis_file"
	cd /home/younes/anl-veloc/VELOC/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heatdis_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/heatdis_file.dir/build: test/heatdis_file

.PHONY : test/CMakeFiles/heatdis_file.dir/build

test/CMakeFiles/heatdis_file.dir/requires: test/CMakeFiles/heatdis_file.dir/heatdis_file.c.o.requires

.PHONY : test/CMakeFiles/heatdis_file.dir/requires

test/CMakeFiles/heatdis_file.dir/clean:
	cd /home/younes/anl-veloc/VELOC/test && $(CMAKE_COMMAND) -P CMakeFiles/heatdis_file.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/heatdis_file.dir/clean

test/CMakeFiles/heatdis_file.dir/depend:
	cd /home/younes/anl-veloc/VELOC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/younes/anl-veloc/VELOC /home/younes/anl-veloc/VELOC/test /home/younes/anl-veloc/VELOC /home/younes/anl-veloc/VELOC/test /home/younes/anl-veloc/VELOC/test/CMakeFiles/heatdis_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/heatdis_file.dir/depend
