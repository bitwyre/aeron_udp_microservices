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
include CMakeFiles/kafka_cons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kafka_cons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kafka_cons.dir/flags.make

CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.o: CMakeFiles/kafka_cons.dir/flags.make
CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.o: ../src/kafka/consumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/aeron_udp_service/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.o -c /mnt/d/aeron_udp_service/cpp/src/kafka/consumer.cpp

CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/aeron_udp_service/cpp/src/kafka/consumer.cpp > CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.i

CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/aeron_udp_service/cpp/src/kafka/consumer.cpp -o CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.s

# Object files for target kafka_cons
kafka_cons_OBJECTS = \
"CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.o"

# External object files for target kafka_cons
kafka_cons_EXTERNAL_OBJECTS =

kafka_cons: CMakeFiles/kafka_cons.dir/src/kafka/consumer.cpp.o
kafka_cons: CMakeFiles/kafka_cons.dir/build.make
kafka_cons: /usr/local/lib/libcppkafka.so.0.4.0
kafka_cons: /usr/local/lib/librdkafka.so
kafka_cons: CMakeFiles/kafka_cons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/aeron_udp_service/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kafka_cons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kafka_cons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kafka_cons.dir/build: kafka_cons

.PHONY : CMakeFiles/kafka_cons.dir/build

CMakeFiles/kafka_cons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kafka_cons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kafka_cons.dir/clean

CMakeFiles/kafka_cons.dir/depend:
	cd /mnt/d/aeron_udp_service/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/aeron_udp_service/cpp /mnt/d/aeron_udp_service/cpp /mnt/d/aeron_udp_service/cpp/build /mnt/d/aeron_udp_service/cpp/build /mnt/d/aeron_udp_service/cpp/build/CMakeFiles/kafka_cons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kafka_cons.dir/depend

