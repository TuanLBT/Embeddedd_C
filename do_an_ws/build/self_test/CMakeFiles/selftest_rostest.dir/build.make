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
CMAKE_SOURCE_DIR = /home/pi/do_an_ws/src/diagnostics/self_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/do_an_ws/build/self_test

# Include any dependencies generated for this target.
include CMakeFiles/selftest_rostest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/selftest_rostest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/selftest_rostest.dir/flags.make

CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.o: CMakeFiles/selftest_rostest.dir/flags.make
CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.o: /home/pi/do_an_ws/src/diagnostics/self_test/src/selftest_rostest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/do_an_ws/build/self_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.o -c /home/pi/do_an_ws/src/diagnostics/self_test/src/selftest_rostest.cpp

CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/do_an_ws/src/diagnostics/self_test/src/selftest_rostest.cpp > CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.i

CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/do_an_ws/src/diagnostics/self_test/src/selftest_rostest.cpp -o CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.s

CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.o: CMakeFiles/selftest_rostest.dir/flags.make
CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.o: /home/pi/do_an_ws/src/diagnostics/self_test/gtest-1.7.0/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/do_an_ws/build/self_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.o -c /home/pi/do_an_ws/src/diagnostics/self_test/gtest-1.7.0/gtest-all.cc

CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/do_an_ws/src/diagnostics/self_test/gtest-1.7.0/gtest-all.cc > CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.i

CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/do_an_ws/src/diagnostics/self_test/gtest-1.7.0/gtest-all.cc -o CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.s

# Object files for target selftest_rostest
selftest_rostest_OBJECTS = \
"CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.o" \
"CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.o"

# External object files for target selftest_rostest
selftest_rostest_EXTERNAL_OBJECTS =

/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: CMakeFiles/selftest_rostest.dir/src/selftest_rostest.cpp.o
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: CMakeFiles/selftest_rostest.dir/gtest-1.7.0/gtest-all.cc.o
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: CMakeFiles/selftest_rostest.dir/build.make
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /home/pi/do_an_ws/devel/.private/diagnostic_updater/lib/libdiagnostic_updater.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libroscpp.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librosconsole.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librostime.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libcpp_common.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so.0.4
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /home/pi/do_an_ws/devel/.private/diagnostic_updater/lib/libdiagnostic_updater.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libroscpp.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librosconsole.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/librostime.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /opt/ros/noetic/lib/libcpp_common.so
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so.0.4
/home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest: CMakeFiles/selftest_rostest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/do_an_ws/build/self_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/selftest_rostest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/selftest_rostest.dir/build: /home/pi/do_an_ws/devel/.private/self_test/lib/self_test/selftest_rostest

.PHONY : CMakeFiles/selftest_rostest.dir/build

CMakeFiles/selftest_rostest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/selftest_rostest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/selftest_rostest.dir/clean

CMakeFiles/selftest_rostest.dir/depend:
	cd /home/pi/do_an_ws/build/self_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/do_an_ws/src/diagnostics/self_test /home/pi/do_an_ws/src/diagnostics/self_test /home/pi/do_an_ws/build/self_test /home/pi/do_an_ws/build/self_test /home/pi/do_an_ws/build/self_test/CMakeFiles/selftest_rostest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/selftest_rostest.dir/depend

