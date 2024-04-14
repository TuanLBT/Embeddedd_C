execute_process(COMMAND "/home/pi/do_an_ws/build/diagnostic_common_diagnostics/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/pi/do_an_ws/build/diagnostic_common_diagnostics/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
