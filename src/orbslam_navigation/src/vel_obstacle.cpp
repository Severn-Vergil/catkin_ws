#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>
#include <pcl_ros/point_cloud.h>
#include <math.h>

using namespace std;
//使用std空间

ros::Publisher pub; //用于在rviz中显示移动机器人正前方点云
ros::Publisher pub1; //用于在rviz中显示移动机器人正前方点云
ros::Publisher velocity; //控制小车速度
geometry_msgs::Twist speed; // 控制信号载体 Twist message
int average = 0; //初始设置为0,在直行情况下的平均点数
list<int> samples; //链表用于存每次点云的点数
int current = 2; //小车运行状态1为左转2为直行3为右转
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
pcl::PassThrough<pcl::PointXYZ> crop;
pcl::VoxelGrid<pcl::PointXYZ> downsample;
pcl::PointCloud<pcl::PointXYZ>::Ptr downsampled(new pcl::PointCloud<
		pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr front(new pcl::PointCloud<pcl::PointXYZ>);

void shutdown(int sig)
{
	velocity.publish(geometry_msgs::Twist());
	ROS_INFO("obstacle_avoidance cpp ended!");
	ros::shutdown();
}

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr& input)
{
	// Convert the sensor_msgs/PointCloud2 data to pcl/PointCloud
	ros::Rate loopRate(10);
	pcl::fromROSMsg(*input, *cloud);

	//downsample the PCL
	downsample.setInputCloud(cloud);
	downsample.setLeafSize(0.04, 0.04, 0.04);
	downsample.filter(*downsampled);

	//crop X axis
	crop.setInputCloud(downsampled);
	crop.setFilterFieldName("x");
	crop.setFilterLimits(-0.2, 0.2);
	crop.filter(*front);

	//crop Y axis

	crop.setInputCloud(front);
	crop.setFilterFieldName("y");
	crop.setFilterLimits(-0.2, 0.2);
	crop.filter(*front);

	//crop Z axis
	crop.setInputCloud(front);
	crop.setFilterFieldName("z");
	crop.setFilterLimits(0, 0.8);
	crop.filter(*front);

#if (0)
	sensor_msgs::PointCloud2 output;
	pcl::toROSMsg(*front, output);
	pub.publish(output);

	sensor_msgs::PointCloud2 output2;
	pcl::toROSMsg (*downsampled, output2);
	pub.publish (output2);
#endif

	if (current == 2)
		samples.clear();
	// 	samples.push_front(front->width * front->height);
	samples.push_front(front->size());
	while (samples.size() > 2)
		samples.pop_back();
	for (list<int>::iterator location = samples.begin(); location
			!= samples.end(); location++)
		average += *location;
	average /= samples.size();
	if (average > 0) //something is in our way!
	{
		float centroidX = 0;
		//	front->points.resize (front->width * front->height);

		//compute the centroid of the detected points
		// 	for(int point=0; point<front->width * front->height; point++)
		//	  		centroidX+=front->points[point].x;
		for (pcl::PointCloud<pcl::PointXYZ>::iterator point = front->begin(); point
				< front->end(); point++)
			centroidX += point->x;
		centroidX /= abs(front->width * front->height);
	//	cerr<<centroidX<<endl;
		if (centroidX > 0) //obstacle(s)'[s] centroid is off to left
		{
			ROS_INFO("LEFT");
			speed.linear.x = 0.08; // 设置线速度为0.1m/s，正为前进，负为后退
			speed.angular.z = 0.2; // 设置角速度为0.4rad/s，正为左转，负为右转
			velocity.publish(speed); // 将刚才设置的指令发送给机器人
			loopRate.sleep();
			current = 3;
		}
		else if (centroidX < 0)//centroidX>=0
		{
			ROS_INFO("RIGHT");
			speed.linear.x = 0.08; // 设置线速度为0.1m/s，正为前进，负为后退
			speed.angular.z = -0.2; // 设置角速度为0.4rad/s，正为左转，负为右转
			velocity.publish(speed); // 将刚才设置的指令发送给机器人
			loopRate.sleep();
			current = 1;
		}

	}
	else
	{
		ROS_INFO("FORWARD");
		speed.linear.x = 0.08; // 设置线速度为0.1m/s，正为前进，负为后退
		speed.angular.z = 0; // 设置角速度为0.4rad/s，正为左转，负为右转
		velocity.publish(speed); // 将刚才设置的指令发送给机器人
		loopRate.sleep();
		current = 2;
	}
	for (int cir=1;cir<3;cir++)
	{
		velocity.publish(speed); // 将刚才设置的指令发送给机器人
		loopRate.sleep();
	}

}

int main(int argc, char** argv)
{
	// Initialize ROS
    ros::init(argc, argv, "obstacle_avoidance");
	ros::NodeHandle nh;
	// Create a ROS subscriber for the input point cloud
	ros::Subscriber sub;
	signal(SIGINT, shutdown);
	//ros::Rate loopRate(1);
	sub = nh.subscribe("/kinect2/qhd/points", 1, cloud_cb);
	//cerr << current << endl;
	// Create a ROS publisher for the output model coefficients
//	pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
	//  pub1 = nh.advertise<sensor_msgs::PointCloud2> ("output2", 1);
	velocity = nh.advertise<geometry_msgs::Twist> ("/chatter2",
			1);
	// Spin
	ros::spin();
}
