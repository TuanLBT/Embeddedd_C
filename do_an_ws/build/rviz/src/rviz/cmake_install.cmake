# Install script for directory: /home/pi/do_an_ws/src/rviz/src/rviz

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rviz" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/rviz/lib/rviz/rviz")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/rviz/lib:/home/pi/do_an_ws/devel/.private/image_transport/lib:/home/pi/do_an_ws/devel/.private/interactive_markers/lib:/home/pi/do_an_ws/devel/.private/laser_geometry/lib:/home/pi/do_an_ws/devel/.private/tf/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/resource_retriever/lib:/home/pi/do_an_ws/devel/.private/tf2_ros/lib:/home/pi/do_an_ws/devel/.private/actionlib/lib:/home/pi/do_an_ws/devel/.private/tf2/lib:/home/pi/do_an_ws/devel/.private/urdf/lib:/home/pi/do_an_ws/devel/.private/rosconsole_bridge/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rviz/rviz")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/pi/do_an_ws/devel/.private/rviz/lib/librviz.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/image_transport/lib:/home/pi/do_an_ws/devel/.private/interactive_markers/lib:/home/pi/do_an_ws/devel/.private/laser_geometry/lib:/home/pi/do_an_ws/devel/.private/tf/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/resource_retriever/lib:/home/pi/do_an_ws/devel/.private/tf2_ros/lib:/home/pi/do_an_ws/devel/.private/actionlib/lib:/home/pi/do_an_ws/devel/.private/tf2/lib:/home/pi/do_an_ws/devel/.private/urdf/lib:/home/pi/do_an_ws/devel/.private/rosconsole_bridge/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/librviz.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rviz" TYPE DIRECTORY FILES "/home/pi/do_an_ws/src/rviz/src/rviz/./" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rviz" TYPE FILE FILES "/home/pi/do_an_ws/devel/.private/rviz/include/rviz/rviz_export.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/pi/do_an_ws/devel/.private/rviz/lib/rviz/rviz")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz"
         OLD_RPATH "/home/pi/do_an_ws/devel/.private/rviz/lib:/home/pi/do_an_ws/devel/.private/image_transport/lib:/home/pi/do_an_ws/devel/.private/interactive_markers/lib:/home/pi/do_an_ws/devel/.private/laser_geometry/lib:/home/pi/do_an_ws/devel/.private/tf/lib:/opt/ros/noetic/lib:/home/pi/do_an_ws/devel/.private/resource_retriever/lib:/home/pi/do_an_ws/devel/.private/tf2_ros/lib:/home/pi/do_an_ws/devel/.private/actionlib/lib:/home/pi/do_an_ws/devel/.private/tf2/lib:/home/pi/do_an_ws/devel/.private/urdf/lib:/home/pi/do_an_ws/devel/.private/rosconsole_bridge/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rviz")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/pi/do_an_ws/build/rviz/src/rviz/default_plugin/cmake_install.cmake")

endif()

