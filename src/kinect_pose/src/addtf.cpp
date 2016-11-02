// from optical frame to mobile base frame
// x: the middle point of turtlebot plane to kinect camera
// y: place a box in front of the kinect camera, and adjust the place of box
//    until it is in the middle of the scan, then measure the distance of
//    mid robot point and box point.
// z: set a suitable height. or measure it by yourself.
// rotation: RPY or quaternion, child_link's rotation relative to parent's.
// warning: we usually use (w,x,y,z) however in ROS (x,y,z,w)!!!

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "addtf");
	ros::NodeHandle node;

	tf::TransformBroadcaster br;
	tf::Transform transform;

    ros::Rate rate(10.0);
	while (node.ok())
	{
        ros::Time now = ros::Time::now();

//        // Kinect horizonal placed.
        transform.setOrigin(tf::Vector3( 0.132, 0.05, 0.5));
        transform.setRotation(tf::Quaternion( -0.5, 0.5, -0.5, 0.5 ));

//        // Kinect vertical placed, base on the left.
//        transform.setOrigin(tf::Vector3( 0.125, 0, 0.4 ));
//        transform.setRotation(tf::Quaternion( 0, sqrt(2)/2, 0, sqrt(2)/2 ));

        // Kinect vertical placed, base on the right.
//        transform.setOrigin(tf::Vector3( 0.0, 0.0, 0.0 ));  // scan test
        // distance of kinect optical frame to camera frame is 0.11m
        // add this with the distance of camera frame to base frame.      
//        transform.setOrigin(tf::Vector3( 0.22, 0.0, 0.0 ));
//        transform.setRotation(tf::Quaternion( sqrt(2)/2, 0, sqrt(2)/2, 0 ));

        br.sendTransform(tf::StampedTransform(transform, now, "base_link", "kinect2_link"));

		rate.sleep();
	}
	return 0;
}

// ORB-SLAM
//        // here Kinect is used in vertical mode, with Kinect base on the left;
//        vo_quat.w = Q.w(); vo_quat.x = Q.z(); vo_quat.y = Q.y(); vo_quat.z = -Q.x();
//        // set transform and publish tf.
//        vo_trans.setOrigin(tf::Vector3( t[2], t[1], -t[0] ));
//        vo_trans.setRotation(tf::Quaternion( Q.z(), Q.y(), -Q.x(), Q.w() ));
//        // publish navigation message.
//        vo.header.stamp = stamp;
//        vo.header.frame_id = "vo";
//        // transform from TUM camera frame to mobile robot frame
//        vo.pose.pose.position.x =  t[2];
//        vo.pose.pose.position.y =  t[1];
//        vo.pose.pose.position.z = -t[0];
//        vo.pose.pose.orientation = vo_quat;

//        // here Kinect is used in vertical mode, with Kinect base on the right;
//        vo_quat.w = Q.w(); vo_quat.x = Q.z(); vo_quat.y = -Q.y(); vo_quat.z = Q.x();
//        // set transform and publish tf.
//        vo_trans.setOrigin(tf::Vector3( t[2], -t[1], t[0] ));
//        vo_trans.setRotation(tf::Quaternion( Q.z(), -Q.y(), Q.x(), Q.w() ));
//        // publish navigation message.
//        vo.header.stamp = stamp;
//        vo.header.frame_id = "vo";
//        // transform from TUM camera frame to mobile robot frame
//        vo.pose.pose.position.x =  t[2];
//        vo.pose.pose.position.y = -t[1];
//        vo.pose.pose.position.z =  t[0];
//        vo.pose.pose.orientation = vo_quat;
