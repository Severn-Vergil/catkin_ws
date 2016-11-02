// Author: Severn Wong
// tackle with amcl localization method, fuse amcl VO with ORB-SLAM VO.
// TODO: how to choose the fusion strategy?
// set visual odometry as the initialpose of amcl if amcl_pose not found in a long time?
// how to trigger it? use timestamp to trigger it.

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>
#include <cmath>

// for saving files
#include <string>
#include <fstream>
using namespace std;

geometry_msgs::PoseWithCovarianceStamped initialpose;
ros::Time AmclTime;
bool isVoReceived = false;
double var = 0.0;

// save pose in txt format
const string &fnameAmcl = "amcl.txt";
const string &fnameOdom = "odom.txt";
ofstream foutAmcl, foutOdom;

double getYaw(geometry_msgs::Quaternion qmsg)
{
    tf::Quaternion q;
    double roll, pitch, yaw;
    tf::quaternionMsgToTF(qmsg, q);
    tf::Matrix3x3(q).getRPY(roll, pitch, yaw);
    return yaw;
}

void amclCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    AmclTime = msg->header.stamp;
    // save current AMCL pose in txt.
    // timestamp, x, y, yaw, cov_x, cov_y, cov_yaw.
    // covariance matrix in 6*6 -> 36 elements.
    unsigned int seq = msg->header.seq;
    double x = msg->pose.pose.position.x, y = msg->pose.pose.position.y, yaw = getYaw(msg->pose.pose.orientation);
    double cov_x = msg->pose.covariance[0], cov_y = msg->pose.covariance[7], cov_yaw = msg->pose.covariance[35];
    foutAmcl << setprecision(6) << msg->header.stamp.toSec()
             << " " << x << " " << y << " " << yaw
             << " " << cov_x << " " << cov_y << " " << cov_yaw << endl;
    //    }
    ROS_INFO("AMCL Sequence  -> seq: [%d]", seq);
    ROS_INFO("AMCL Position  -> x: [%3.3f], y: [%3.3f], yaw: [%3.3f]", x, y, yaw);
    ROS_INFO("AMCL Covariance-> x: [%3.3f], y: [%3.3f], yaw: [%3.3f]", cov_x, cov_y, cov_yaw);
}

//voCallback: if amcl_pose can not be received for a setting time, publish visual odometry as
//initial pose.
void voCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    // store latest visual odometry into initialpose
    initialpose.header.stamp = msg->header.stamp;
    initialpose.header.frame_id = "odom_fusion";
    initialpose.pose = msg->pose;
    isVoReceived = true;
}

//odomCallBack
void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    // save current odom pose in txt.
    // timestamp, x, y, yaw, cov_x, cov_y, cov_yaw.
    // covariance matrix in 6*6 -> 36 elements.
    unsigned int seq = msg->header.seq;
    double x = msg->pose.pose.position.x, y = msg->pose.pose.position.y, yaw = getYaw(msg->pose.pose.orientation);
    double cov_x = msg->pose.covariance[0], cov_y = msg->pose.covariance[7], cov_yaw = msg->pose.covariance[35];
    foutOdom << setprecision(6) << msg->header.stamp.toSec()
             << " " << x << " " << y << " " << yaw
             << " " << cov_x << " " << cov_y << " " << cov_yaw << endl;
//    ROS_INFO("odom Sequence  -> seq: [%d]", seq);
//    ROS_INFO("odom Position  -> x: [%3.3f], y: [%3.3f], yaw: [%3.3f]", x, y, yaw);
//    ROS_INFO("odom Covariance-> x: [%3.3f], y: [%3.3f], yaw: [%3.3f]", cov_x, cov_y, cov_yaw);
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "odom_fusion");
    ros::NodeHandle nh;
    ros::Rate rate(20.0);
    ROS_INFO("Data Recorder of VO, AMCL, odometry");
    foutAmcl.open(fnameAmcl.c_str());
    foutOdom.open(fnameOdom.c_str());
    foutAmcl << fixed;
    foutOdom << fixed;

    ros::Publisher  pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose", 50);
    ros::Subscriber sub_amcl = nh.subscribe("amcl_pose", 1000, amclCallback);
    ros::Subscriber sub_vo   = nh.subscribe("vo", 1000, voCallback);
    ros::Subscriber sub_odom = nh.subscribe("odom", 1000, odomCallback);
    ros::Duration PastAmclPub;
    AmclTime = ros::Time::now();
//    while(nh.ok())
//    {
//        // callback would be activated once by spinOnce.
//        ros::spinOnce();
//        PastAmclPub = ros::Time::now() - AmclTime;
//        // publish /initialpose if amcl not published in a long time, e.g. 1s
//        if((PastAmclPub > ros::Duration(0.2)) && isVoReceived && var > 0.7)
//        {
//            pub.publish(initialpose);
//            ROS_INFO("Publish initialpose for AMCL!");
//            isVoReceived = false;
//            var = 0.0;
//        }
//        rate.sleep();
//    }
    ros::spin();
    foutAmcl.close();
    foutOdom.close();
    return 0;
}
