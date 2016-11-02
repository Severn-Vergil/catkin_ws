//============================================================================
// Name        : hello.cpp
// Author      : li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <ros/ros.h>
#include <math.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_listener.h>

#define pi 3.1415926

using namespace std;

ros::Publisher velocity;
double roll, pitch, yaw;
double xs, ys, zs;
void shutdown(int sig)
{
	velocity.publish(geometry_msgs::Twist());
	ROS_INFO("polar_example_move cpp ended!");
	ros::shutdown();
}

double regular(double x)
{
	if (x > pi)
		x = x - 2 * pi;
	else if (x < -pi)
		x = x + 2 * pi;
	return x;
}
void get_pose()
{
	tf::TransformListener listener; //用于获取小车的坐标
	tf::StampedTransform transform;
	try
	{
		listener.waitForTransform("odom", "base_footprint", ros::Time(0),
				ros::Duration(1.0));
		listener.lookupTransform("odom", "base_footprint", ros::Time(0),
				transform);
	} catch (tf::TransformException ex)
	{
		ROS_ERROR("%s", ex.what());
	}
	transform.getBasis().getRPY(roll, pitch, yaw);
	xs = transform.getOrigin().x();
	ys = transform.getOrigin().y();
	zs = yaw;
}

int main(int argc, char **argv)
{
	ofstream outfile("abc.txt");
	//定义变量用于表示小车旋转角度
	double roll, pitch, yaw;
	//参数
	double rol, alfa, beta;
	double v, w, wk;
	// 速度和角速度上限
	double vmax = 0.08;
	double wmax = 0.2;
	// 增益参数
	double kp = 3;
	double ka = 8;
	double kb = -1.5;
	//初始位姿
//	double xs, ys, zs; //存储当前坐标变换量
	//目标位姿
	double xr, yr, zr;
	xr = yr = 0;
	zr = pi/2;
	//允许误差范围
	double xp, yp, zp;
	xp = 0.03;
	yp = 0.03;
	zp = 0.05;
	// 参数
	int k = 0;
	double limit = 0.02;
	double m, n, l, vk;
	double xe, ye, ze;
	int i = 0;
	int j = 0;
	double xm = 0;
	double out[1000][3] =
	{ };
	ros::init(argc, argv, "polar");
	std::string topic = "/chatter1";
	ros::NodeHandle node;
	ros::Publisher velocity = node.advertise < geometry_msgs::Twist
			> (topic, 1);
	ros::Rate loopRate(5);
	signal(SIGINT, shutdown);
	ROS_INFO("test cpp start...");
	geometry_msgs::Twist speed; // 控制信号载体 Twist message
	get_pose();
	bool task = 1;
	int flag = 0;
	alfa = atan2((yr - ys), (xr - xs)) - zs;
	cout << alfa << endl;
	alfa = regular(alfa);
	if (abs(alfa) > pi / 2)
	{
		xs = -xs;
		ys = -ys;
		flag = 1;
	}
	cout << "flag = " << flag << endl;
	zr = regular(zr);
	zs = regular(zs);
	cout << xs << ys << zs << endl;
	while (task)
	{
		rol = sqrt((xr - xs) * (xr - xs) + (yr - ys) * (yr - ys));
		alfa = atan2((yr - ys), (xr - xs)) - zs;
		alfa = regular(alfa);
		beta = zr - atan2((yr - ys), (xr - xs));
		beta = regular(beta);
		/*
		 cerr << "rol = " << rol << endl;
		 cerr << "alfa = " << alfa << endl;
		 cerr << "beta = " << beta << endl;
		 */
		v = kp * rol;
		w = ka * alfa + kb * beta;
		get_pose();
		if (flag == 1)
		{
			v = -v;
			w = w;
			xs = -xs;
			ys = -ys;
		}

//		cerr << "x= " << xs << endl;
//		cerr << "y= " << ys << endl;
//		cerr << "z= " << zs << endl;
		if (j == 0)
		{
			out[j][0] = xs;
			out[j][1] = ys;
			out[j][2] = zs;
		}
		else
		{

			out[j][0] = xs;
			out[j][1] = ys;
			out[j][2] = zs;
		}
		j = j + 1;
		if (fabs(w) > wmax)
		{
			if (w > 0)
			{
				wk = w;
				w = wmax;
				v = v * w / wk;
			}
			else
			{
				wk = w;
				w = -wmax;
				v = v * w / wk;
			}
		}
		if (fabs(v) > vmax)
		{
			if (v > 0)
			{
				vk = v;
				v = vmax;
				w = v * w / vk;
			}
			else
			{
				vk = v;
				v = -vmax;
				w = v * w / vk;
			}

		}
		xe = xr - xs;
		ye = yr - ys;
		ze = zr - zs;
		if ((abs(xs - xr) < xp) && (abs(ys - yr) < yp)) //&&((abs(zs-zr)<zp)||(abs(abs(zs-zr)-2*pi)<zp)
		{
			task = 0;
		}
		speed.linear.x = v;
		speed.angular.z = w; // 设置角速度为0.4rad/s，正为左转，负为右转
		cerr << "v = " << v << endl;
		cerr << "w = " << w << endl;
		cerr << endl;
		velocity.publish(speed); // 将刚才设置的指令发送给机器人
		loopRate.sleep();
	}
#if(1)
	cerr << "第一阶段" << endl;
	cerr << "ze = " << ze << endl;

	j = j - 1;
	get_pose();
	ze = zs - zr;
	while (abs(ze) > zp)
	{

		cerr << "xs = " << xs << endl;
		cerr << "ys = " << ys << endl;
		cerr << "zs = " << zs << endl;

		out[j][0] = xs;
		out[j][1] = ys;
		out[j][2] = zs;
		j = j + 1;

		v = 0;
		if (ze > 0)
			w = -0.2;
		else
			w = 0.2;
		cerr << "v = " << v << endl;
		cerr << "w = " << w << endl;
		speed.linear.x = v;
		speed.angular.z = w; // 设置角速度为0.4rad/s，正为左转，负为右转
		velocity.publish(speed); // 将刚才设置的指令发送给机器人
		loopRate.sleep();
		get_pose();
		ze = zs - zr;
	}
	cerr << "第二阶段" << endl;
	cerr << "xs = " << xs << endl;
	get_pose();
	ye = ys - yr;

	while (abs(ye) > 0.03)
	{

		cerr << "xs = " << xs << endl;
		cerr << "ys = " << ys << endl;
		cerr << "zs = " << zs << endl;
		out[j][0] = xs;
		out[j][1] = ys;
		out[j][2] = zs;
		j = j + 1;
		w = 0;
		if (ye > 0)
			v = -vmax;
		else
			v = vmax;
		cerr << "v = " << v << endl;
		cerr << "w = " << w << endl;
		speed.linear.x = v;
		speed.angular.z = w; // 设置角速度为0.4rad/s，正为左转，负为右转
		velocity.publish(speed); // 将刚才设置的指令发送给机器人
		loopRate.sleep();
		get_pose();
		ye = ys - yr;

	}
	speed.linear.x = 0;
	speed.angular.z = 0;
	velocity.publish(speed);

#endif
	get_pose();
	cerr << "xs = " << xs << endl;
	cerr << "ys = " << ys << endl;
	cerr << "zs = " << zs << endl;
	out[j][0] = xs;
	out[j][1] = ys;
	out[j][2] = zs;
	for (int m = 0; m < j+1; m++)
	{
		outfile << out[m][0] << " " << out[m][1] << " " << out[m][2] << endl;
		//cerr << a[m][0] << " " << a[m][1] << " " << a[m][2] << endl;
	}
	outfile.close();
	cout << "!!!Well done!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
