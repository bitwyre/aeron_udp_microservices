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
include CMakeFiles/aeron_pub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeron_pub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeron_pub.dir/flags.make

CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.o: CMakeFiles/aeron_pub.dir/flags.make
CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.o: ../src/aeron/BasicPublisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/aeron_udp_service/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.o -c /mnt/d/aeron_udp_service/cpp/src/aeron/BasicPublisher.cpp

CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/aeron_udp_service/cpp/src/aeron/BasicPublisher.cpp > CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.i

CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/aeron_udp_service/cpp/src/aeron/BasicPublisher.cpp -o CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.s

# Object files for target aeron_pub
aeron_pub_OBJECTS = \
"CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.o"

# External object files for target aeron_pub
aeron_pub_EXTERNAL_OBJECTS =

aeron_pub: CMakeFiles/aeron_pub.dir/src/aeron/BasicPublisher.cpp.o
aeron_pub: CMakeFiles/aeron_pub.dir/build.make
aeron_pub: /usr/local/lib/libcppkafka.so.0.4.0
aeron_pub: external/aeron/lib/libaeron_client.a
aeron_pub: /usr/local/lib/librdkafka.so
aeron_pub: CMakeFiles/aeron_pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/aeron_udp_service/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aeron_pub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aeron_pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeron_pub.dir/build: aeron_pub

.PHONY : CMakeFiles/aeron_pub.dir/build

CMakeFiles/aeron_pub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aeron_pub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aeron_pub.dir/clean

CMakeFiles/aeron_pub.dir/depend:
	cd /mnt/d/aeron_udp_service/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/aeron_udp_service/cpp /mnt/d/aeron_udp_service/cpp /mnt/d/aeron_udp_service/cpp/build /mnt/d/aeron_udp_service/cpp/build /mnt/d/aeron_udp_service/cpp/build/CMakeFiles/aeron_pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aeron_pub.dir/depend
