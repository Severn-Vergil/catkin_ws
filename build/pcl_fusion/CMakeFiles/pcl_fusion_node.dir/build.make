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
include pcl_fusion/CMakeFiles/pcl_fusion_node.dir/depend.make

# Include the progress variables for this target.
include pcl_fusion/CMakeFiles/pcl_fusion_node.dir/progress.make

# Include the compile flags for this target's objects.
include pcl_fusion/CMakeFiles/pcl_fusion_node.dir/flags.make

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/flags.make
pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o: /home/rabot/catkin_ws/src/pcl_fusion/src/pcl_fusion_node.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rabot/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o"
	cd /home/rabot/catkin_ws/build/pcl_fusion && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o -c /home/rabot/catkin_ws/src/pcl_fusion/src/pcl_fusion_node.cpp

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.i"
	cd /home/rabot/catkin_ws/build/pcl_fusion && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rabot/catkin_ws/src/pcl_fusion/src/pcl_fusion_node.cpp > CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.i

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.s"
	cd /home/rabot/catkin_ws/build/pcl_fusion && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rabot/catkin_ws/src/pcl_fusion/src/pcl_fusion_node.cpp -o CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.s

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.requires:
.PHONY : pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.requires

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.provides: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.requires
	$(MAKE) -f pcl_fusion/CMakeFiles/pcl_fusion_node.dir/build.make pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.provides.build
.PHONY : pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.provides

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.provides.build: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o

# Object files for target pcl_fusion_node
pcl_fusion_node_OBJECTS = \
"CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o"

# External object files for target pcl_fusion_node
pcl_fusion_node_EXTERNAL_OBJECTS =

/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/build.make
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libpcl_ros_filters.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libpcl_ros_io.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libpcl_ros_tf.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_common.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_octree.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_io.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_kdtree.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_search.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_sample_consensus.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_filters.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_features.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_keypoints.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_segmentation.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_visualization.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_outofcore.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_registration.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_recognition.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_surface.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_people.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_tracking.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libpcl_apps.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libqhull.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libOpenNI.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libvtkCommon.so.5.8.0
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libvtkRendering.so.5.8.0
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libvtkHybrid.so.5.8.0
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libvtkCharts.so.5.8.0
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libdynamic_reconfigure_config_init_mutex.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libnodeletlib.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libbondcpp.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libuuid.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libclass_loader.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/libPocoFoundation.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libdl.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libroslib.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/librosbag.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/librosbag_storage.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libroslz4.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/liblz4.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libtopic_tools.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libtf.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libtf2_ros.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libactionlib.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libmessage_filters.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libroscpp.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libtf2.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/librosconsole.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/liblog4cxx.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/librostime.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /opt/ros/indigo/lib/libcpp_common.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node"
	cd /home/rabot/catkin_ws/build/pcl_fusion && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_fusion_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pcl_fusion/CMakeFiles/pcl_fusion_node.dir/build: /home/rabot/catkin_ws/devel/lib/pcl_fusion/pcl_fusion_node
.PHONY : pcl_fusion/CMakeFiles/pcl_fusion_node.dir/build

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/requires: pcl_fusion/CMakeFiles/pcl_fusion_node.dir/src/pcl_fusion_node.cpp.o.requires
.PHONY : pcl_fusion/CMakeFiles/pcl_fusion_node.dir/requires

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/clean:
	cd /home/rabot/catkin_ws/build/pcl_fusion && $(CMAKE_COMMAND) -P CMakeFiles/pcl_fusion_node.dir/cmake_clean.cmake
.PHONY : pcl_fusion/CMakeFiles/pcl_fusion_node.dir/clean

pcl_fusion/CMakeFiles/pcl_fusion_node.dir/depend:
	cd /home/rabot/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rabot/catkin_ws/src /home/rabot/catkin_ws/src/pcl_fusion /home/rabot/catkin_ws/build /home/rabot/catkin_ws/build/pcl_fusion /home/rabot/catkin_ws/build/pcl_fusion/CMakeFiles/pcl_fusion_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pcl_fusion/CMakeFiles/pcl_fusion_node.dir/depend

