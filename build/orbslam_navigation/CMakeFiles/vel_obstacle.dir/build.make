# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rabot/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rabot/catkin_ws/build

# Include any dependencies generated for this target.
include orbslam_navigation/CMakeFiles/vel_obstacle.dir/depend.make

# Include the progress variables for this target.
include orbslam_navigation/CMakeFiles/vel_obstacle.dir/progress.make

# Include the compile flags for this target's objects.
include orbslam_navigation/CMakeFiles/vel_obstacle.dir/flags.make

orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o: orbslam_navigation/CMakeFiles/vel_obstacle.dir/flags.make
orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o: /home/rabot/catkin_ws/src/orbslam_navigation/src/vel_obstacle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rabot/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o"
	cd /home/rabot/catkin_ws/build/orbslam_navigation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o -c /home/rabot/catkin_ws/src/orbslam_navigation/src/vel_obstacle.cpp

orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.i"
	cd /home/rabot/catkin_ws/build/orbslam_navigation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rabot/catkin_ws/src/orbslam_navigation/src/vel_obstacle.cpp > CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.i

orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.s"
	cd /home/rabot/catkin_ws/build/orbslam_navigation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rabot/catkin_ws/src/orbslam_navigation/src/vel_obstacle.cpp -o CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.s

orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.requires:
.PHONY : orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.requires

orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.provides: orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.requires
	$(MAKE) -f orbslam_navigation/CMakeFiles/vel_obstacle.dir/build.make orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.provides.build
.PHONY : orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.provides

orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.provides.build: orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o

# Object files for target vel_obstacle
vel_obstacle_OBJECTS = \
"CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o"

# External object files for target vel_obstacle
vel_obstacle_EXTERNAL_OBJECTS =

/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: orbslam_navigation/CMakeFiles/vel_obstacle.dir/build.make
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libpcl_ros_filters.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libpcl_ros_io.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libpcl_ros_tf.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_common.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_octree.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_io.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_kdtree.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_search.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_sample_consensus.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_filters.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_features.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_keypoints.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_segmentation.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_visualization.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_outofcore.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_registration.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_recognition.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_surface.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_people.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_tracking.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libpcl_apps.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libqhull.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libOpenNI.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libvtkCommon.so.5.8.0
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libvtkRendering.so.5.8.0
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libvtkHybrid.so.5.8.0
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libvtkCharts.so.5.8.0
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libdynamic_reconfigure_config_init_mutex.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libnodeletlib.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libbondcpp.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libuuid.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libclass_loader.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/libPocoFoundation.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libdl.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libroslib.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/librosbag.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/librosbag_storage.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libroslz4.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/liblz4.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libtopic_tools.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libtf.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libtf2_ros.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libactionlib.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libmessage_filters.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libroscpp.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libtf2.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/librosconsole.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/liblog4cxx.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/librostime.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /opt/ros/indigo/lib/libcpp_common.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle: orbslam_navigation/CMakeFiles/vel_obstacle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle"
	cd /home/rabot/catkin_ws/build/orbslam_navigation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vel_obstacle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
orbslam_navigation/CMakeFiles/vel_obstacle.dir/build: /home/rabot/catkin_ws/devel/lib/orbslam_navigation/vel_obstacle
.PHONY : orbslam_navigation/CMakeFiles/vel_obstacle.dir/build

orbslam_navigation/CMakeFiles/vel_obstacle.dir/requires: orbslam_navigation/CMakeFiles/vel_obstacle.dir/src/vel_obstacle.cpp.o.requires
.PHONY : orbslam_navigation/CMakeFiles/vel_obstacle.dir/requires

orbslam_navigation/CMakeFiles/vel_obstacle.dir/clean:
	cd /home/rabot/catkin_ws/build/orbslam_navigation && $(CMAKE_COMMAND) -P CMakeFiles/vel_obstacle.dir/cmake_clean.cmake
.PHONY : orbslam_navigation/CMakeFiles/vel_obstacle.dir/clean

orbslam_navigation/CMakeFiles/vel_obstacle.dir/depend:
	cd /home/rabot/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rabot/catkin_ws/src /home/rabot/catkin_ws/src/orbslam_navigation /home/rabot/catkin_ws/build /home/rabot/catkin_ws/build/orbslam_navigation /home/rabot/catkin_ws/build/orbslam_navigation/CMakeFiles/vel_obstacle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : orbslam_navigation/CMakeFiles/vel_obstacle.dir/depend

