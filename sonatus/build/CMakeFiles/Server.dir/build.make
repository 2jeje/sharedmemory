# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/jaehoon/sharedmemory/sonatus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jaehoon/sharedmemory/sonatus/build

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/server/src/main.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/server/src/main.cpp.o: ../server/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaehoon/sharedmemory/sonatus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/server/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/server/src/main.cpp.o -c /home/jaehoon/sharedmemory/sonatus/server/src/main.cpp

CMakeFiles/Server.dir/server/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/server/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaehoon/sharedmemory/sonatus/server/src/main.cpp > CMakeFiles/Server.dir/server/src/main.cpp.i

CMakeFiles/Server.dir/server/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/server/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaehoon/sharedmemory/sonatus/server/src/main.cpp -o CMakeFiles/Server.dir/server/src/main.cpp.s

CMakeFiles/Server.dir/server/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Server.dir/server/src/main.cpp.o.requires

CMakeFiles/Server.dir/server/src/main.cpp.o.provides: CMakeFiles/Server.dir/server/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/server/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Server.dir/server/src/main.cpp.o.provides

CMakeFiles/Server.dir/server/src/main.cpp.o.provides.build: CMakeFiles/Server.dir/server/src/main.cpp.o


# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/server/src/main.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/server/src/main.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: libIpc.so
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jaehoon/sharedmemory/sonatus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/requires: CMakeFiles/Server.dir/server/src/main.cpp.o.requires

.PHONY : CMakeFiles/Server.dir/requires

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/jaehoon/sharedmemory/sonatus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jaehoon/sharedmemory/sonatus /home/jaehoon/sharedmemory/sonatus /home/jaehoon/sharedmemory/sonatus/build /home/jaehoon/sharedmemory/sonatus/build /home/jaehoon/sharedmemory/sonatus/build/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend
