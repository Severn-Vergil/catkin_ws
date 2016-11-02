//convert cmd_vel given from the motion controller(rbx1_nav nav_square.py)
//to turtlebot velocity command.

#include <ros/ros.h>
#include <math.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

using namespace std;
ros::Publisher cmdVelPub;
geometry_msgs::Twist speed;


void callback(const geometry_msgs::Twist& twist_msg)
{
	ros::Rate loopRate(50);
    speed = twist_msg;
	cmdVelPub.publish(speed);
	loopRate.sleep();

}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "conversion");
	ros::NodeHandle node;
	ros::Rate loopRate(50);
    ROS_INFO("Twist message conversion start!");
	ros::Subscriber sub = node.subscribe("/cmd_vel",1,callback);
	cmdVelPub = node.advertise < geometry_msgs::Twist > ("cmd_vel_mux/input/navi", 1);
	ros::spin();

	return 0;
}
