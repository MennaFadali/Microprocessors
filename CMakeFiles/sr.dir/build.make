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
CMAKE_SOURCE_DIR = /home/mennafadali/CLionProjects/Microprocessors

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mennafadali/CLionProjects/Microprocessors

# Include any dependencies generated for this target.
include CMakeFiles/sr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sr.dir/flags.make

CMakeFiles/sr.dir/sendrec.c.o: CMakeFiles/sr.dir/flags.make
CMakeFiles/sr.dir/sendrec.c.o: sendrec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mennafadali/CLionProjects/Microprocessors/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sr.dir/sendrec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sr.dir/sendrec.c.o   -c /home/mennafadali/CLionProjects/Microprocessors/sendrec.c

CMakeFiles/sr.dir/sendrec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sr.dir/sendrec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mennafadali/CLionProjects/Microprocessors/sendrec.c > CMakeFiles/sr.dir/sendrec.c.i

CMakeFiles/sr.dir/sendrec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sr.dir/sendrec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mennafadali/CLionProjects/Microprocessors/sendrec.c -o CMakeFiles/sr.dir/sendrec.c.s

CMakeFiles/sr.dir/sendrec.c.o.requires:

.PHONY : CMakeFiles/sr.dir/sendrec.c.o.requires

CMakeFiles/sr.dir/sendrec.c.o.provides: CMakeFiles/sr.dir/sendrec.c.o.requires
	$(MAKE) -f CMakeFiles/sr.dir/build.make CMakeFiles/sr.dir/sendrec.c.o.provides.build
.PHONY : CMakeFiles/sr.dir/sendrec.c.o.provides

CMakeFiles/sr.dir/sendrec.c.o.provides.build: CMakeFiles/sr.dir/sendrec.c.o


# Object files for target sr
sr_OBJECTS = \
"CMakeFiles/sr.dir/sendrec.c.o"

# External object files for target sr
sr_EXTERNAL_OBJECTS =

sr: CMakeFiles/sr.dir/sendrec.c.o
sr: CMakeFiles/sr.dir/build.make
sr: CMakeFiles/sr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mennafadali/CLionProjects/Microprocessors/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sr.dir/build: sr

.PHONY : CMakeFiles/sr.dir/build

CMakeFiles/sr.dir/requires: CMakeFiles/sr.dir/sendrec.c.o.requires

.PHONY : CMakeFiles/sr.dir/requires

CMakeFiles/sr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sr.dir/clean

CMakeFiles/sr.dir/depend:
	cd /home/mennafadali/CLionProjects/Microprocessors && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mennafadali/CLionProjects/Microprocessors /home/mennafadali/CLionProjects/Microprocessors /home/mennafadali/CLionProjects/Microprocessors /home/mennafadali/CLionProjects/Microprocessors /home/mennafadali/CLionProjects/Microprocessors/CMakeFiles/sr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sr.dir/depend

