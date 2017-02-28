# CCC Tasks
## 1. The hardware drivers
	roslaunch turtlebot_bringup minimal.launch 
	roslaunch openni_launch camera1.launch 
	roslaunch openni_launch camera2.launch 
The Kinect cameras should be called with order in a time interval.

## 2. Mapping and navigation 
	roslaunch rtabmap_ros dualRGBD_turtlebot_mapping.launch
	roslaunch ase_exploration turtlebot_exploration.launch // you can write your own navigation launch file.

## 3. CCC taks process
    Using rotate_node, panorama_node, navigation_node to finish following tasks
	Rotate 360 deg, and stitch a panorama using images from 2 Kinects simutaneously.
	Send a goal to move_base application, and wait till the goal finished.
	Rotate 360 deg, and stitch a panorama using images from 2 Kinects simutaneously.
	Using messages /trigger and /rotate_finished to communicate among the nodes.

## 4. Data recording, visualization and task activating
    rosbag record /map /odom /panorama /trigger /rotate_finished
    rostopic pub /trigger std_msgs/Bool "data: true" -1
    roslaunch ccc_task ccc_task.launch 