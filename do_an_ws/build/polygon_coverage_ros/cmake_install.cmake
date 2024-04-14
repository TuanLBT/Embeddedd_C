# Install script for directory: /home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_ros

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/pi/do_an_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/pi/do_an_ws/build/polygon_coverage_ros/gtest/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pi/do_an_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pi/do_an_ws/install" TYPE PROGRAM FILES "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pi/do_an_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pi/do_an_ws/install" TYPE PROGRAM FILES "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pi/do_an_ws/install/setup.bash;/home/pi/do_an_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pi/do_an_ws/install" TYPE FILE FILES
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/setup.bash"
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pi/do_an_ws/install/setup.sh;/home/pi/do_an_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pi/do_an_ws/install" TYPE FILE FILES
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/setup.sh"
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pi/do_an_ws/install/setup.zsh;/home/pi/do_an_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pi/do_an_ws/install" TYPE FILE FILES
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/setup.zsh"
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/pi/do_an_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/pi/do_an_ws/install" TYPE FILE FILES "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/polygon_coverage_ros.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/polygon_coverage_ros/cmake" TYPE FILE FILES
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/polygon_coverage_rosConfig.cmake"
    "/home/pi/do_an_ws/build/polygon_coverage_ros/catkin_generated/installspace/polygon_coverage_rosConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/polygon_coverage_ros" TYPE FILE FILES "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_ros/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib/polygon_coverage_ros/coverage_planner")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/eigen_conversions/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_msgs/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_geometry/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_planners/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_solvers/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib/polygon_coverage_ros/coverage_planner_exact")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/eigen_conversions/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_msgs/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_geometry/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_planners/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_solvers/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/eigen_conversions/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_msgs/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_geometry/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_planners/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_solvers/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/coverage_planner_exact_preprocessed")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib/polygon_coverage_ros/shortest_path_planner")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/eigen_conversions/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_msgs/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_geometry/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_planners/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_solvers/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/shortest_path_planner")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib/polygon_coverage_ros/sweep_test")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/polygon_coverage_ros/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/eigen_conversions/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_msgs/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_geometry/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_planners/lib:/home/pi/do_an_ws/devel/.private/polygon_coverage_solvers/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/polygon_coverage_ros/sweep_test")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/pi/do_an_ws/build/polygon_coverage_ros/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
