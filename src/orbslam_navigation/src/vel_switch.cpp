#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>

using namespace std;
ros::Publisher cmdVelPub;
geometry_msgs::Twist speed;
double v,v1, v2;
double w, w1, w2;

void Callback1(const geometry_msgs::Twist& msg)
{
	v1 = msg.linear.x;
	w1 = msg.angular.z;
}
void Callback2(const geometry_msgs::Twist& msg)
{
	v2 = msg.linear.x;
	w2 = msg.angular.z;
	if (w2 == 0)
	{
		v = v1;
		w = w1;
	}
	else
	{
		v = v2;
		w = w2;
	}
	cerr<<"v = "<<v<<endl;
	cerr<<"w = "<<w<<endl;
	cerr<<endl;
	speed.linear.x = v;
	speed.angular.z = w;
	cmdVelPub.publish(speed);
}
void shutdown(int sig)
{
	cmdVelPub.publish(geometry_msgs::Twist());
	ROS_INFO("turtlebot example move cpp ended!");
	ros::shutdown();
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "fuse");
	std::string topic = "/cmd_vel_mux/input/navi";
	ros::NodeHandle node;
	cmdVelPub = node.advertise<geometry_msgs::Twist>(topic, 1);
	ros::Rate loopRate(5);
	signal(SIGINT, shutdown);
	ROS_INFO("exbot_example_move cpp start...");
	ros::Subscriber Sub1 = node.subscribe("/chatter1", 1, Callback1);
	ros::Subscriber Sub2 = node.subscribe("/chatter2", 1, Callback2);
	ros::spin();
}

