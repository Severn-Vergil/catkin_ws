execute_process(COMMAND "/home/rabot/catkin_ws/build/goal_sender/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/rabot/catkin_ws/build/goal_sender/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
