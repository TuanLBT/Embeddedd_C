# CMake generated Testfile for 
# Source directory: /home/pi/do_an_ws/src/interactive_markers
# Build directory: /home/pi/do_an_ws/build/interactive_markers
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_interactive_markers_rostest_test_cpp_server.test "/home/pi/do_an_ws/build/interactive_markers/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/pi/do_an_ws/build/interactive_markers/test_results/interactive_markers/rostest-test_cpp_server.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/pi/do_an_ws/src/interactive_markers --package=interactive_markers --results-filename test_cpp_server.xml --results-base-dir \"/home/pi/do_an_ws/build/interactive_markers/test_results\" /home/pi/do_an_ws/src/interactive_markers/test/cpp_server.test ")
set_tests_properties(_ctest_interactive_markers_rostest_test_cpp_server.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/home/pi/do_an_ws/src/interactive_markers/CMakeLists.txt;56;add_rostest;/home/pi/do_an_ws/src/interactive_markers/CMakeLists.txt;0;")
add_test(_ctest_interactive_markers_rostest_test_cpp_client.test "/home/pi/do_an_ws/build/interactive_markers/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/pi/do_an_ws/build/interactive_markers/test_results/interactive_markers/rostest-test_cpp_client.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/pi/do_an_ws/src/interactive_markers --package=interactive_markers --results-filename test_cpp_client.xml --results-base-dir \"/home/pi/do_an_ws/build/interactive_markers/test_results\" /home/pi/do_an_ws/src/interactive_markers/test/cpp_client.test ")
set_tests_properties(_ctest_interactive_markers_rostest_test_cpp_client.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/home/pi/do_an_ws/src/interactive_markers/CMakeLists.txt;61;add_rostest;/home/pi/do_an_ws/src/interactive_markers/CMakeLists.txt;0;")
add_test(_ctest_interactive_markers_rostest_test_cpp_server_client.test "/home/pi/do_an_ws/build/interactive_markers/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/pi/do_an_ws/build/interactive_markers/test_results/interactive_markers/rostest-test_cpp_server_client.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/pi/do_an_ws/src/interactive_markers --package=interactive_markers --results-filename test_cpp_server_client.xml --results-base-dir \"/home/pi/do_an_ws/build/interactive_markers/test_results\" /home/pi/do_an_ws/src/interactive_markers/test/cpp_server_client.test ")
set_tests_properties(_ctest_interactive_markers_rostest_test_cpp_server_client.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/home/pi/do_an_ws/src/interactive_markers/CMakeLists.txt;66;add_rostest;/home/pi/do_an_ws/src/interactive_markers/CMakeLists.txt;0;")
subdirs("gtest")