# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "polygon_coverage_msgs: 2 messages, 2 services")

set(MSG_I_FLAGS "-Ipolygon_coverage_msgs:/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg;-Igeometry_msgs:/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Itrajectory_msgs:/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(polygon_coverage_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" NAME_WE)
add_custom_target(_polygon_coverage_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "polygon_coverage_msgs" "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" "geometry_msgs/Point32:geometry_msgs/Polygon"
)

get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" NAME_WE)
add_custom_target(_polygon_coverage_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "polygon_coverage_msgs" "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" "geometry_msgs/Point32:polygon_coverage_msgs/PolygonWithHoles:geometry_msgs/Polygon:std_msgs/Header"
)

get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" NAME_WE)
add_custom_target(_polygon_coverage_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "polygon_coverage_msgs" "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" "trajectory_msgs/MultiDOFJointTrajectory:trajectory_msgs/MultiDOFJointTrajectoryPoint:geometry_msgs/Point:geometry_msgs/Pose:geometry_msgs/Twist:geometry_msgs/Transform:geometry_msgs/Vector3:std_msgs/Header:geometry_msgs/PoseStamped:geometry_msgs/Quaternion"
)

get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" NAME_WE)
add_custom_target(_polygon_coverage_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "polygon_coverage_msgs" "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" "polygon_coverage_msgs/PolygonWithHoles:geometry_msgs/Polygon:std_msgs/Header:polygon_coverage_msgs/PolygonWithHolesStamped:geometry_msgs/Point32"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_msg_cpp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Services
_generate_srv_cpp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectory.msg;/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectoryPoint.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Twist.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Transform.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/PoseStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_srv_cpp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Module File
_generate_module_cpp(polygon_coverage_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(polygon_coverage_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(polygon_coverage_msgs_generate_messages polygon_coverage_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_cpp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_cpp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_cpp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_cpp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(polygon_coverage_msgs_gencpp)
add_dependencies(polygon_coverage_msgs_gencpp polygon_coverage_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS polygon_coverage_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_msg_eus(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Services
_generate_srv_eus(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectory.msg;/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectoryPoint.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Twist.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Transform.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/PoseStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_srv_eus(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Module File
_generate_module_eus(polygon_coverage_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(polygon_coverage_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(polygon_coverage_msgs_generate_messages polygon_coverage_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_eus _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_eus _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_eus _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_eus _polygon_coverage_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(polygon_coverage_msgs_geneus)
add_dependencies(polygon_coverage_msgs_geneus polygon_coverage_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS polygon_coverage_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_msg_lisp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Services
_generate_srv_lisp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectory.msg;/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectoryPoint.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Twist.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Transform.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/PoseStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_srv_lisp(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Module File
_generate_module_lisp(polygon_coverage_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(polygon_coverage_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(polygon_coverage_msgs_generate_messages polygon_coverage_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_lisp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_lisp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_lisp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_lisp _polygon_coverage_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(polygon_coverage_msgs_genlisp)
add_dependencies(polygon_coverage_msgs_genlisp polygon_coverage_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS polygon_coverage_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_msg_nodejs(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Services
_generate_srv_nodejs(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectory.msg;/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectoryPoint.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Twist.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Transform.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/PoseStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_srv_nodejs(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Module File
_generate_module_nodejs(polygon_coverage_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(polygon_coverage_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(polygon_coverage_msgs_generate_messages polygon_coverage_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_nodejs _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_nodejs _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_nodejs _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_nodejs _polygon_coverage_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(polygon_coverage_msgs_gennodejs)
add_dependencies(polygon_coverage_msgs_gennodejs polygon_coverage_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS polygon_coverage_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_msg_py(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Services
_generate_srv_py(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectory.msg;/home/pi/do_an_ws/src/common_msgs/trajectory_msgs/msg/MultiDOFJointTrajectoryPoint.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Twist.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Transform.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/PoseStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs
)
_generate_srv_py(polygon_coverage_msgs
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv"
  "${MSG_I_FLAGS}"
  "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg;/home/pi/do_an_ws/src/common_msgs/geometry_msgs/msg/Point32.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs
)

### Generating Module File
_generate_module_py(polygon_coverage_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(polygon_coverage_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(polygon_coverage_msgs_generate_messages polygon_coverage_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHoles.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_py _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/msg/PolygonWithHolesStamped.msg" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_py _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PlannerService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_py _polygon_coverage_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/do_an_ws/src/polygon_coverage_planning/polygon_coverage_msgs/srv/PolygonService.srv" NAME_WE)
add_dependencies(polygon_coverage_msgs_generate_messages_py _polygon_coverage_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(polygon_coverage_msgs_genpy)
add_dependencies(polygon_coverage_msgs_genpy polygon_coverage_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS polygon_coverage_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/polygon_coverage_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(polygon_coverage_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(polygon_coverage_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET trajectory_msgs_generate_messages_cpp)
  add_dependencies(polygon_coverage_msgs_generate_messages_cpp trajectory_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/polygon_coverage_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(polygon_coverage_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(polygon_coverage_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET trajectory_msgs_generate_messages_eus)
  add_dependencies(polygon_coverage_msgs_generate_messages_eus trajectory_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/polygon_coverage_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(polygon_coverage_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(polygon_coverage_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET trajectory_msgs_generate_messages_lisp)
  add_dependencies(polygon_coverage_msgs_generate_messages_lisp trajectory_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/polygon_coverage_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(polygon_coverage_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(polygon_coverage_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET trajectory_msgs_generate_messages_nodejs)
  add_dependencies(polygon_coverage_msgs_generate_messages_nodejs trajectory_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/polygon_coverage_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(polygon_coverage_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(polygon_coverage_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET trajectory_msgs_generate_messages_py)
  add_dependencies(polygon_coverage_msgs_generate_messages_py trajectory_msgs_generate_messages_py)
endif()
