# CMake generated Testfile for 
# Source directory: /home/pi/do_an_ws/src/diagnostics/diagnostic_analysis
# Build directory: /home/pi/do_an_ws/build/diagnostic_analysis
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_diagnostic_analysis_nosetests_test.bag_csv_test.py "/home/pi/do_an_ws/build/diagnostic_analysis/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/pi/do_an_ws/build/diagnostic_analysis/test_results/diagnostic_analysis/nosetests-test.bag_csv_test.py.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/pi/do_an_ws/build/diagnostic_analysis/test_results/diagnostic_analysis" "/usr/bin/nosetests3 -P --process-timeout=60 /home/pi/do_an_ws/src/diagnostics/diagnostic_analysis/test/bag_csv_test.py --with-xunit --xunit-file=/home/pi/do_an_ws/build/diagnostic_analysis/test_results/diagnostic_analysis/nosetests-test.bag_csv_test.py.xml")
set_tests_properties(_ctest_diagnostic_analysis_nosetests_test.bag_csv_test.py PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/nosetests.cmake;83;catkin_run_tests_target;/home/pi/do_an_ws/src/diagnostics/diagnostic_analysis/CMakeLists.txt;11;catkin_add_nosetests;/home/pi/do_an_ws/src/diagnostics/diagnostic_analysis/CMakeLists.txt;0;")
subdirs("gtest")
