# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "teb_local_planner: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iteb_local_planner:/home/rabot/catkin_ws/src/teb_local_planner/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(teb_local_planner_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg" NAME_WE)
add_custom_target(_teb_local_planner_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "teb_local_planner" "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg" "geometry_msgs/Point:geometry_msgs/Vector3:teb_local_planner/TrajectoryPointMsg:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg" NAME_WE)
add_custom_target(_teb_local_planner_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "teb_local_planner" "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg" "geometry_msgs/Quaternion:geometry_msgs/Vector3:geometry_msgs/Twist:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg" NAME_WE)
add_custom_target(_teb_local_planner_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "teb_local_planner" "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg" "geometry_msgs/Point32:geometry_msgs/Polygon:geometry_msgs/Point:geometry_msgs/PolygonStamped:geometry_msgs/Vector3:teb_local_planner/TrajectoryPointMsg:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Twist:teb_local_planner/TrajectoryMsg:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg" NAME_WE)
add_custom_target(_teb_local_planner_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "teb_local_planner" "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg" "geometry_msgs/Polygon:geometry_msgs/PolygonStamped:geometry_msgs/TwistWithCovariance:geometry_msgs/Vector3:geometry_msgs/Point32:geometry_msgs/Quaternion:geometry_msgs/Twist:geometry_msgs/QuaternionStamped:std_msgs/Header"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner
)
_generate_msg_cpp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner
)
_generate_msg_cpp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner
)
_generate_msg_cpp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/QuaternionStamped.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner
)

### Generating Services

### Generating Module File
_generate_module_cpp(teb_local_planner
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(teb_local_planner_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(teb_local_planner_generate_messages teb_local_planner_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_cpp _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_cpp _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_cpp _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_cpp _teb_local_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(teb_local_planner_gencpp)
add_dependencies(teb_local_planner_gencpp teb_local_planner_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS teb_local_planner_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner
)
_generate_msg_lisp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner
)
_generate_msg_lisp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner
)
_generate_msg_lisp(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/QuaternionStamped.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner
)

### Generating Services

### Generating Module File
_generate_module_lisp(teb_local_planner
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(teb_local_planner_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(teb_local_planner_generate_messages teb_local_planner_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_lisp _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_lisp _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_lisp _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_lisp _teb_local_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(teb_local_planner_genlisp)
add_dependencies(teb_local_planner_genlisp teb_local_planner_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS teb_local_planner_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner
)
_generate_msg_py(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner
)
_generate_msg_py(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner
)
_generate_msg_py(teb_local_planner
  "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/QuaternionStamped.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner
)

### Generating Services

### Generating Module File
_generate_module_py(teb_local_planner
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(teb_local_planner_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(teb_local_planner_generate_messages teb_local_planner_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_py _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/TrajectoryPointMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_py _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/FeedbackMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_py _teb_local_planner_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rabot/catkin_ws/src/teb_local_planner/msg/ObstacleMsg.msg" NAME_WE)
add_dependencies(teb_local_planner_generate_messages_py _teb_local_planner_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(teb_local_planner_genpy)
add_dependencies(teb_local_planner_genpy teb_local_planner_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS teb_local_planner_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/teb_local_planner
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(teb_local_planner_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(teb_local_planner_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/teb_local_planner
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(teb_local_planner_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(teb_local_planner_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/teb_local_planner
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(teb_local_planner_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(teb_local_planner_generate_messages_py std_msgs_generate_messages_py)
