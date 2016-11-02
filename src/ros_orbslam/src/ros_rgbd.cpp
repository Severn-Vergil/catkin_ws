//    A hard question is how to judge whether the sensor data stream stop.
//    As synchronizer store and tackle with asynchronic data, the old data will
//keep sending in a new time stamp, which cannot be used as a condition, and
//EKF process will be corrupted by repeated data(overfitting process).
//    If tracking lost, Tcw will be an empty matrix!

// Original ros_rgbd example headers
#include <iostream>
#include <fstream>
//#include <algorithm>
//#include <chrono>

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <opencv2/core/core.hpp>

// ORB-SLAM system headers
#include "../../../ORB_SLAM2/include/System.h"
#include "../../../ORB_SLAM2/include/Converter.h"

// test added headers
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Header.h>

// set message to be global for change convenience
// vo_quat is a part of vo and vo_trans
// vo for publishing message
// vo_trans for publishing tf
// vo message and tf tree
ros::Time stamp;
geometry_msgs::Quaternion vo_quat;
nav_msgs::Odometry vo;
tf::Transform vo_trans;
ros::Publisher vo_pub;
tf::TransformBroadcaster * vo_broadcaster;

// base to camera transform
tf::TransformListener * base2camera1_listener, * base2camera2_listener, * c1_c2_listener;
tf::StampedTransform base2camera1, base2camera2, c1_c2;

// switch camera algorithm
unsigned int status = 0, nCam = 0;
bool bSwitch = false; // switch camera
tf::Transform tfC2; // camera 2 initial pose.
tf::Transform tfLast; // last pose;
bool bC2 = false; // use camera 2 the first time.
std::string strLastid = "";   // id of latest camera
tf::Transform vo_trans0; // store the current transform after switching camera
tf::Transform vo_ego_motion; // store the ego-motion
tf::Transform tfOon;    // store the transform of complete ego-motion before switching, from frame O to O_n.


// Save current, camera1, camera2 trajectory and lost tracking camera number
const string strCur = "TrajectoryCur.txt", strC1 = "camera1.txt", strC2 = "camera2.txt",
             strLost = "lost.txt";
ofstream fCur, fC1, fC2, fL;
std::vector<float> q(4);
std::vector<float> t(3);

class ImageGrabber
{
public:
    ImageGrabber(ORB_SLAM2::System* pSLAM):mpSLAM(pSLAM){}

    void GrabRGBD(const sensor_msgs::ImageConstPtr& msgRGB,	const sensor_msgs::ImageConstPtr& msgD);

    ORB_SLAM2::System* mpSLAM;
};
void statusCb(const std_msgs::UInt8::ConstPtr& msg);
double getYaw(tf::Transform trans);


int main(int argc, char **argv)
{
    ros::init(argc, argv, "orbslam_rgbd");
    ros::start();
    ros::NodeHandle nh;

    string orbVocFile = "/home/rabot/ORB_SLAM2/Vocabulary/ORBvoc.bin";
    stamp = ros::Time::now();
    vo_broadcaster = new tf::TransformBroadcaster();
    vo_pub = nh.advertise<nav_msgs::Odometry>("vo", 1000);
    base2camera1_listener = new tf::TransformListener();
    base2camera2_listener = new tf::TransformListener();
    c1_c2_listener = new tf::TransformListener();
    vo_trans0.setIdentity();
    vo_trans.setIdentity();
    tfOon.setIdentity();
    tfLast.setIdentity();

    fCur.open(strCur.c_str());
    fCur << fixed;
    fC1.open(strC1.c_str());
    fC1  << fixed;
    fC2.open(strC2.c_str());
    fC2  << fixed;
    fL.open(strLost.c_str());
    fL   << fixed;

    // system status subscriber
    ros::Subscriber status_sub = nh.subscribe("status", 10, statusCb);


//    // Kinect 2
//    string orbSetiingsFile = "/home/rabot/catkin_ws/src/ros_orbslam/data/kinect2_qhd.yaml";
//    message_filters::Subscriber <sensor_msgs::Image> rgb_sub(nh, "/kinect2/qhd/image_color_rect", 1);
//    message_filters::Subscriber <sensor_msgs::Image> depth_sub(nh, "/kinect2/qhd/image_depth_rect", 1);

//    // TUM 1
//    string orbSetiingsFile = "/home/rabot/workspace/TUM1.yaml";
//    message_filters::Subscriber <sensor_msgs::Image> rgb_sub(nh, "/camera/rgb/image_color", 1);
//    message_filters::Subscriber <sensor_msgs::Image> depth_sub(nh, "/camera/depth/image", 1);

    // Kinect multiple
    string orbSetiingsFile = "/home/rabot/catkin_ws/src/ros_orbslam/data/default.yaml";
    message_filters::Subscriber <sensor_msgs::Image> rgb_sub1(nh, "/camera1/rgb/image_raw", 1);
    message_filters::Subscriber <sensor_msgs::Image> depth_sub1(nh, "/camera1/depth_registered/image_raw", 1);
    message_filters::Subscriber <sensor_msgs::Image> rgb_sub2(nh, "/camera2/rgb/image_raw", 1);
    message_filters::Subscriber <sensor_msgs::Image> depth_sub2(nh, "/camera2/depth_registered/image_raw", 1);

    // Kinect 2 multiple
//    string orbSetiingsFile = "/home/rabot/catkin_ws/src/ros_orbslam/data/multiK2.yaml";
//    message_filters::Subscriber <sensor_msgs::Image> rgb_sub1(nh, "/k2_c1/qhd/image_color_rect", 1);
//    message_filters::Subscriber <sensor_msgs::Image> depth_sub1(nh, "/k2_c1/qhd/image_depth_rect", 1);
//    message_filters::Subscriber <sensor_msgs::Image> rgb_sub2(nh, "/k2_c2/qhd/image_color_rect", 1);
//    message_filters::Subscriber <sensor_msgs::Image> depth_sub2(nh, "/k2_c2/qhd/image_depth_rect", 1);

    // Create SLAM system. It initializes all system threads and gets ready to process frames.
    ORB_SLAM2::System SLAM(orbVocFile, orbSetiingsFile, ORB_SLAM2::System::RGBD, true);
    ImageGrabber igb(&SLAM);

    // synchronizer of rgb and depth
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image> sync_pol;
    // camera 1
    message_filters::Synchronizer<sync_pol> sync1(sync_pol(10), rgb_sub1, depth_sub1);
    sync1.registerCallback(boost::bind(&ImageGrabber::GrabRGBD, &igb, _1, _2));
    // camera 2
    message_filters::Synchronizer<sync_pol> sync2(sync_pol(10), rgb_sub2, depth_sub2);
    sync2.registerCallback(boost::bind(&ImageGrabber::GrabRGBD, &igb, _1, _2));

    ros::spin();

    // Stop all threads
    SLAM.Shutdown();

    // Save camera trajectory
    SLAM.SaveTrajectoryTUM("Trajectory.txt");
    fCur.close();
    fC1.close();
    fC2.close();
    fL.close();
    cout << endl << "current trajectory saved!" << endl;

    ros::shutdown();

    return 0;
}

// GrabRGBD in ROS format: providing a bridge from ROS message to cv Mat.
// Receive data from synchronizer pool
// Store current pose in global var q,t to plot in TUM format.
// Call once while spinOnce
void ImageGrabber::GrabRGBD(const sensor_msgs::ImageConstPtr& msgRGB, const sensor_msgs::ImageConstPtr& msgD)
{
    // check camera id and set number.
    if(msgRGB->header.frame_id == "camera1_rgb_optical_frame")
    {
        nCam = 1;
    }
    if(msgRGB->header.frame_id == "camera2_rgb_optical_frame")
    {
        nCam = 2;
    }
    // keep data from camera 1.
    if((nCam == 1 && status != 1) && status != 7 )
    {
        return;
    }

    // keep data from camera 2.
    if((nCam == 2 && status != 2) && status != 7 )
    {
        return;
    }

    // Copy the ros image message to cv::Mat.
    cv_bridge::CvImageConstPtr cv_ptrRGB;
    try
    {
        cv_ptrRGB = cv_bridge::toCvShare(msgRGB);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    cv_bridge::CvImageConstPtr cv_ptrD;
    try
    {
        cv_ptrD = cv_bridge::toCvShare(msgD);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    // new frame received.
    // todo: how to configure with tracking lost?
    if(stamp != cv_ptrRGB->header.stamp)
    {
        stamp = cv_ptrRGB->header.stamp;
        // Record current frame pose in TUM format.
        cv::Mat Tcw = mpSLAM->TrackRGBD(cv_ptrRGB->image, cv_ptrD->image, cv_ptrRGB->header.stamp.toSec());
        // Tracking Lost: Tcw will be empty matrix
        if(Tcw.dims < 2)
        {          
            ROS_INFO("Tracking lost from %d", nCam);
            fL << setprecision(6) << stamp.toSec() << " " << nCam << endl;
            return;
        }
        // be cafeful: col vs colRange, access exception.
        cv::Mat Rwc = Tcw.rowRange(0,3).colRange(0,3).t();
        cv::Mat twc = -Rwc*Tcw.rowRange(0,3).col(3);

        // method copy from original converter.cc - toMatrix3d and toQuartenion method.
        // save TUM type in std vec format: tx, ty, tz, qx, qy, qz, qw
        Eigen::Matrix<double,3,3> eigMat;
        eigMat << Rwc.at<float>(0,0), Rwc.at<float>(0,1), Rwc.at<float>(0,2),
                  Rwc.at<float>(1,0), Rwc.at<float>(1,1), Rwc.at<float>(1,2),
                  Rwc.at<float>(2,0), Rwc.at<float>(2,1), Rwc.at<float>(2,2);
        Eigen::Quaterniond Q(eigMat);
        q[0] = Q.x(); q[1] = Q.y(); q[2] = Q.z(); q[3] = Q.w();
        t[0] = twc.at<float>(0); t[1] = twc.at<float>(1); t[2] = twc.at<float>(2);

        // here Kinect is used in horizonal mode!!! Be careful of transformation
        // modify vo message in mobile robot frame, transform from TUM camera frame to mobile robot frame
        vo_quat.w = Q.w(); vo_quat.x = Q.z(); vo_quat.y = -Q.x(); vo_quat.z = -Q.y();
        // set transform and publish tf.
        vo_trans.setOrigin(tf::Vector3( t[2], -t[0], -t[1]));
        vo_trans.setRotation(tf::Quaternion( Q.z(), -Q.x(), -Q.y(), Q.w() ));

        // 2016.07.27 not work
//        // camera switching algorithm.
//        // vo_trans: localization data from ORB-SLAM, which presents the motion
//        // from the initial camera pose(here is camera 1) to current camera pose.
//        if(strLastid != cv_ptrRGB->header.frame_id)
//        {
//            vo_trans0 = vo_trans;   // store the beginning trans of a new ego-motion
//            bSwitch = true;
//            ROS_INFO("Switch beginning point!");
//            ROS_INFO("%3.3f %3.3f %3.3f", vo_trans0.getOrigin().getX(),
//                     vo_trans0.getOrigin().getY(), vo_trans0.getOrigin().getZ());
//            ROS_INFO("%3.3f %3.3f %3.3f %3.3f",
//                     vo_trans0.getRotation().getW(), vo_trans0.getRotation().getX(),
//                     vo_trans0.getRotation().getY(), vo_trans0.getRotation().getZ());
//            // update id.
//            strLastid = msgRGB->header.frame_id;
//        }
//        else
//        {
//            bSwitch = false;
//        }

//        vo_ego_motion = vo_trans0.inverse() * vo_trans; // ego-motion from a single camera part.

//        // transform from beginning(in the switch point) base to current base
//        // notice: here still in the beginning of a single camera part.
//        if(cv_ptrRGB->header.frame_id == "camera1_rgb_optical_frame")
//        {
//            try
//            {
//                base2camera1_listener->lookupTransform("/base_link", "/camera1_link", ros::Time(0), base2camera1);
//            }
//            catch (tf::TransformException ex)
//            {
//                ROS_ERROR("%s",ex.what());
//            }
//            vo_trans = base2camera1 * vo_ego_motion * base2camera1.inverse();
//        }

//        if(cv_ptrRGB->header.frame_id == "camera2_rgb_optical_frame")
//        {
//            try
//            {
//                base2camera2_listener->lookupTransform("/base_link", "/camera2_link", ros::Time(0), base2camera2);
//            }
//            catch (tf::TransformException ex)
//            {
//                ROS_ERROR("%s",ex.what());
//            }
//            vo_trans = base2camera2 * vo_ego_motion * base2camera2.inverse();
//        }
//        if(!bSwitch)
//        {
//            tfOon = vo_trans;   // store complete motion before switch.
//        }
//        else
//        {
//            ROS_INFO("Ego-motion.");
//            ROS_INFO("%3.3f %3.3f %3.3f", vo_trans.getOrigin().getX(),
//                     vo_trans.getOrigin().getY(), vo_trans.getOrigin().getZ());
//            ROS_INFO("%3.3f %3.3f %3.3f %3.3f",
//                     vo_trans.getRotation().getW(), vo_trans.getRotation().getX(),
//                     vo_trans.getRotation().getY(), vo_trans.getRotation().getZ());
//            vo_trans = tfOon * vo_trans;    // apply motion before to stitch up odometry.
//            ROS_INFO("Camera swtiching, apply odometry to ego-motion.");
//            ROS_INFO("%3.3f %3.3f %3.3f", vo_trans.getOrigin().getX(),
//                     vo_trans.getOrigin().getY(), vo_trans.getOrigin().getZ());
//            ROS_INFO("%3.3f %3.3f %3.3f %3.3f",
//                     vo_trans.getRotation().getW(), vo_trans.getRotation().getX(),
//                     vo_trans.getRotation().getY(), vo_trans.getRotation().getZ());
//        }

        // 2016.07.27 not work
//        if(cv_ptrRGB->header.frame_id == "camera2_rgb_optical_frame")
//        {
//            try
//            {
//                c1_c2_listener->lookupTransform("/camera1_link", "/camera2_link", ros::Time(0), c1_c2);
//            }
//            catch (tf::TransformException ex)
//            {
//                ROS_ERROR("%s",ex.what());
//            }
//            vo_trans = c1_c2.inverse() * vo_trans;
//        }


        // 2016.08.16 check pose between 1 and 2
//        // convert camera 2 frame to camera 1 frame with known transform.
//        if(cv_ptrRGB->header.frame_id == "camera2_rgb_optical_frame")
//        {
//            try
//            {
//                c1_c2_listener->lookupTransform("/camera1_link", "/camera2_link", ros::Time(0), c1_c2);
//            }
//            catch (tf::TransformException ex)
//            {
//                ROS_ERROR("%s",ex.what());
//            }
//            if(!bC2)
//            {
//                tfC2 = vo_trans;
//                bC2 = true;
//            }
//            // transform
//            vo_trans.setBasis(c1_c2.getBasis().inverse() * vo_trans.getBasis());
//            vo_trans.setOrigin(vo_trans.getOrigin() - vo_trans.getBasis() * tfC2.getOrigin());
//        }

        // throw away result if huge move from last transformation
//        if(tf::tfDistance(vo_trans.getOrigin(), tfLast.getOrigin()) > 0.3)
////           || (getYaw(vo_trans) - getYaw(tfLast)) > 0.5)
//        {
//            return;
//        }


        // publish navigation message.
        tf::pointTFToMsg(vo_trans.getOrigin(), vo.pose.pose.position);
        tf::quaternionTFToMsg(vo_trans.getRotation(), vo.pose.pose.orientation);
        vo.header.stamp = stamp;
        vo.header.frame_id = "vo";

        vo.pose.covariance = {0.01, 0, 0, 0, 0, 0, // covariance on vo_x
                              0, 0.01, 0, 0, 0, 0, // covariance on vo_y
                              0, 0, 0.01, 0, 0, 0, // covariance on vo_z
                              0, 0, 0, 0.01, 0, 0, // covariance on rot_x
                              0, 0, 0, 0, 0.01, 0, // covariance on rot_y
                              0, 0, 0, 0, 0, 0.01}; //covariance on rot_z

        // publish tf when new message received.
        // broadcast tf /vo as the child of /odom.
        vo_broadcaster->sendTransform(tf::StampedTransform(vo_trans, stamp, "odom", "vo"));
        vo_pub.publish(vo);

        // save current trajectory, method from saveTrajectoryTUM
        fCur << setprecision(6) << stamp.toSec() << setprecision(9)
             << " " << vo.pose.pose.position.x << " " << vo.pose.pose.position.y << " " << vo.pose.pose.position.z
             << " " << vo.pose.pose.orientation.w << " " << vo.pose.pose.orientation.x
             << " " << vo.pose.pose.orientation.y << " " << vo.pose.pose.orientation.z << endl;

        if(msgRGB->header.frame_id == "camera1_rgb_optical_frame")
        {
            fC1  << setprecision(6) << stamp.toSec() << setprecision(9)
                 << " " << vo.pose.pose.position.x << " " << vo.pose.pose.position.y << " " << vo.pose.pose.position.z
                 << " " << vo.pose.pose.orientation.w << " " << vo.pose.pose.orientation.x
                 << " " << vo.pose.pose.orientation.y << " " << vo.pose.pose.orientation.z << endl;
        }
        if(msgRGB->header.frame_id == "camera2_rgb_optical_frame")
        {
            fC2  << setprecision(6) << stamp.toSec() << setprecision(9)
                 << " " << vo.pose.pose.position.x << " " << vo.pose.pose.position.y << " " << vo.pose.pose.position.z
                 << " " << vo.pose.pose.orientation.w << " " << vo.pose.pose.orientation.x
                 << " " << vo.pose.pose.orientation.y << " " << vo.pose.pose.orientation.z << endl;
        }

        // last pose
        tfLast = vo_trans;
    }
}

// set status to control RGB-D data flow.
void statusCb(const std_msgs::UInt8::ConstPtr& msg)
{
    status = msg->data;
    ROS_INFO("Camera %d!", status);
}

double getYaw(tf::Transform trans)
{
    double roll, pitch, yaw;
    trans.getBasis().getRPY(roll, pitch, yaw);
    return yaw;
}
