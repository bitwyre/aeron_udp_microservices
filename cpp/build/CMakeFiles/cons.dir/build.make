# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/d/aeron_udp_service/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/aeron_udp_service/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/cons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cons.dir/flags.make

CMakeFiles/cons.dir/src/BasicSubscriber.cpp.o: CMakeFiles/cons.dir/flags.make
CMakeFiles/cons.dir/src/BasicSubscriber.cpp.o: ../src/BasicSubscriber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/aeron_udp_service/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cons.dir/src/BasicSubscriber.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cons.dir/src/BasicSubscriber.cpp.o -c /mnt/d/aeron_udp_service/cpp/src/BasicSubscriber.cpp

CMakeFiles/cons.dir/src/BasicSubscriber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cons.dir/src/BasicSubscriber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/aeron_udp_service/cpp/src/BasicSubscriber.cpp > CMakeFiles/cons.dir/src/BasicSubscriber.cpp.i

CMakeFiles/cons.dir/src/BasicSubscriber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cons.dir/src/BasicSubscriber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/aeron_udp_service/cpp/src/BasicSubscriber.cpp -o CMakeFiles/cons.dir/src/BasicSubscriber.cpp.s

# Object files for target cons
cons_OBJECTS = \
"CMakeFiles/cons.dir/src/BasicSubscriber.cpp.o"

# External object files for target cons
cons_EXTERNAL_OBJECTS =

cons: CMakeFiles/cons.dir/src/BasicSubscriber.cpp.o
cons: CMakeFiles/cons.dir/build.make
cons: /usr/local/lib/libcppkafka.so.0.4.0
cons: external/aeron/lib/libaeron_client.a
cons: /usr/local/lib/librdkafka.so
cons: CMakeFiles/cons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/aeron_udp_service/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cons.dir/build: cons

.PHONY : CMakeFiles/cons.dir/build

CMakeFiles/cons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cons.dir/clean

CMakeFiles/cons.dir/depend:
	cd /mnt/d/aeron_udp_service/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/aeron_udp_service/cpp /mnt/d/aeron_udp_service/cpp /mnt/d/aeron_udp_service/cpp/build /mnt/d/aeron_udp_service/cpp/build /mnt/d/aeron_udp_service/cpp/build/CMakeFiles/cons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cons.dir/depend

