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
include kinect_pose/CMakeFiles/addtf.dir/depend.make

# Include the progress variables for this target.
include kinect_pose/CMakeFiles/addtf.dir/progress.make

# Include the compile flags for this target's objects.
include kinect_pose/CMakeFiles/addtf.dir/flags.make

kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o: kinect_pose/CMakeFiles/addtf.dir/flags.make
kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o: /home/rabot/catkin_ws/src/kinect_pose/src/addtf.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rabot/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o"
	cd /home/rabot/catkin_ws/build/kinect_pose && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/addtf.dir/src/addtf.cpp.o -c /home/rabot/catkin_ws/src/kinect_pose/src/addtf.cpp

kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addtf.dir/src/addtf.cpp.i"
	cd /home/rabot/catkin_ws/build/kinect_pose && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rabot/catkin_ws/src/kinect_pose/src/addtf.cpp > CMakeFiles/addtf.dir/src/addtf.cpp.i

kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addtf.dir/src/addtf.cpp.s"
	cd /home/rabot/catkin_ws/build/kinect_pose && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rabot/catkin_ws/src/kinect_pose/src/addtf.cpp -o CMakeFiles/addtf.dir/src/addtf.cpp.s

kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.requires:
.PHONY : kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.requires

kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.provides: kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.requires
	$(MAKE) -f kinect_pose/CMakeFiles/addtf.dir/build.make kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.provides.build
.PHONY : kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.provides

kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.provides.build: kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o

# Object files for target addtf
addtf_OBJECTS = \
"CMakeFiles/addtf.dir/src/addtf.cpp.o"

# External object files for target addtf
addtf_EXTERNAL_OBJECTS =

/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: kinect_pose/CMakeFiles/addtf.dir/build.make
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libtf.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libtf2_ros.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libactionlib.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libmessage_filters.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libroscpp.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libtf2.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/librosconsole.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/liblog4cxx.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/librostime.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /opt/ros/indigo/lib/libcpp_common.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/rabot/catkin_ws/devel/lib/kinect_pose/addtf: kinect_pose/CMakeFiles/addtf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/rabot/catkin_ws/devel/lib/kinect_pose/addtf"
	cd /home/rabot/catkin_ws/build/kinect_pose && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/addtf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
kinect_pose/CMakeFiles/addtf.dir/build: /home/rabot/catkin_ws/devel/lib/kinect_pose/addtf
.PHONY : kinect_pose/CMakeFiles/addtf.dir/build

kinect_pose/CMakeFiles/addtf.dir/requires: kinect_pose/CMakeFiles/addtf.dir/src/addtf.cpp.o.requires
.PHONY : kinect_pose/CMakeFiles/addtf.dir/requires

kinect_pose/CMakeFiles/addtf.dir/clean:
	cd /home/rabot/catkin_ws/build/kinect_pose && $(CMAKE_COMMAND) -P CMakeFiles/addtf.dir/cmake_clean.cmake
.PHONY : kinect_pose/CMakeFiles/addtf.dir/clean

kinect_pose/CMakeFiles/addtf.dir/depend:
	cd /home/rabot/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rabot/catkin_ws/src /home/rabot/catkin_ws/src/kinect_pose /home/rabot/catkin_ws/build /home/rabot/catkin_ws/build/kinect_pose /home/rabot/catkin_ws/build/kinect_pose/CMakeFiles/addtf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kinect_pose/CMakeFiles/addtf.dir/depend

