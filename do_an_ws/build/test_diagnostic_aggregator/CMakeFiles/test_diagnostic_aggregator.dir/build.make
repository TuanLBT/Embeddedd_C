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
CMAKE_SOURCE_DIR = /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/do_an_ws/build/test_diagnostic_aggregator

# Include any dependencies generated for this target.
include CMakeFiles/test_diagnostic_aggregator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_diagnostic_aggregator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_diagnostic_aggregator.dir/flags.make

CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.o: CMakeFiles/test_diagnostic_aggregator.dir/flags.make
CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.o: /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/match_no_analyze_analyzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/do_an_ws/build/test_diagnostic_aggregator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.o -c /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/match_no_analyze_analyzer.cpp

CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/match_no_analyze_analyzer.cpp > CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.i

CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/match_no_analyze_analyzer.cpp -o CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.s

CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.o: CMakeFiles/test_diagnostic_aggregator.dir/flags.make
CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.o: /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/fail_init_analyzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/do_an_ws/build/test_diagnostic_aggregator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.o -c /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/fail_init_analyzer.cpp

CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/fail_init_analyzer.cpp > CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.i

CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator/src/fail_init_analyzer.cpp -o CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.s

# Object files for target test_diagnostic_aggregator
test_diagnostic_aggregator_OBJECTS = \
"CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.o" \
"CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.o"

# External object files for target test_diagnostic_aggregator
test_diagnostic_aggregator_EXTERNAL_OBJECTS =

/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: CMakeFiles/test_diagnostic_aggregator.dir/src/match_no_analyze_analyzer.cpp.o
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: CMakeFiles/test_diagnostic_aggregator.dir/src/fail_init_analyzer.cpp.o
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: CMakeFiles/test_diagnostic_aggregator.dir/build.make
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /home/pi/do_an_ws/devel/.private/diagnostic_aggregator/lib/libdiagnostic_aggregator.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /home/pi/do_an_ws/devel/.private/bondcpp/lib/libbondcpp.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libuuid.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/libclass_loader.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/libPocoFoundation.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libdl.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/libroslib.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/librospack.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libpython3.7m.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_program_options.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libtinyxml2.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/libroscpp.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/librosconsole.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/librostime.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /opt/ros/noetic/lib/libcpp_common.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so.0.4
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so: CMakeFiles/test_diagnostic_aggregator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/do_an_ws/build/test_diagnostic_aggregator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library /home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_diagnostic_aggregator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_diagnostic_aggregator.dir/build: /home/pi/do_an_ws/devel/.private/test_diagnostic_aggregator/lib/libtest_diagnostic_aggregator.so

.PHONY : CMakeFiles/test_diagnostic_aggregator.dir/build

CMakeFiles/test_diagnostic_aggregator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_diagnostic_aggregator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_diagnostic_aggregator.dir/clean

CMakeFiles/test_diagnostic_aggregator.dir/depend:
	cd /home/pi/do_an_ws/build/test_diagnostic_aggregator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator /home/pi/do_an_ws/src/diagnostics/test_diagnostic_aggregator /home/pi/do_an_ws/build/test_diagnostic_aggregator /home/pi/do_an_ws/build/test_diagnostic_aggregator /home/pi/do_an_ws/build/test_diagnostic_aggregator/CMakeFiles/test_diagnostic_aggregator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_diagnostic_aggregator.dir/depend
