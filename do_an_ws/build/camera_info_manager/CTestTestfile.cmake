# CMake generated Testfile for 
# Source directory: /home/pi/do_an_ws/src/image_common/camera_info_manager
# Build directory: /home/pi/do_an_ws/build/camera_info_manager
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_camera_info_manager_rostest_tests_unit_test.test "/home/pi/do_an_ws/build/camera_info_manager/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/pi/do_an_ws/build/camera_info_manager/test_results/camera_info_manager/rostest-tests_unit_test.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/pi/do_an_ws/src/image_common/camera_info_manager --package=camera_info_manager --results-filename tests_unit_test.xml --results-base-dir \"/home/pi/do_an_ws/build/camera_info_manager/test_results\" /home/pi/do_an_ws/src/image_common/camera_info_manager/tests/unit_test.test ")
set_tests_properties(_ctest_camera_info_manager_rostest_tests_unit_test.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/home/pi/do_an_ws/src/image_common/camera_info_manager/CMakeLists.txt;38;add_rostest;/home/pi/do_an_ws/src/image_common/camera_info_manager/CMakeLists.txt;0;")
subdirs("gtest")
