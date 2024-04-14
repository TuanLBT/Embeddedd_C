# CMake generated Testfile for 
# Source directory: /home/pi/do_an_ws/src/roslint
# Build directory: /home/pi/do_an_ws/build/roslint
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_roslint_roslint_package "/home/pi/do_an_ws/build/roslint/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/pi/do_an_ws/build/roslint/test_results/roslint/roslint-roslint.xml" "--working-dir" "/home/pi/do_an_ws/build/roslint" "--return-code" "/home/pi/do_an_ws/src/roslint/scripts/test_wrapper /home/pi/do_an_ws/build/roslint/test_results/roslint/roslint-roslint.xml make roslint_roslint")
set_tests_properties(_ctest_roslint_roslint_package PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/home/pi/do_an_ws/build/roslint/cmake/roslint-extras.cmake;68;catkin_run_tests_target;/home/pi/do_an_ws/src/roslint/CMakeLists.txt;28;roslint_add_test;/home/pi/do_an_ws/src/roslint/CMakeLists.txt;0;")
subdirs("gtest")
