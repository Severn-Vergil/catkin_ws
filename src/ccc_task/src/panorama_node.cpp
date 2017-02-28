#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <vector>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/Bool.h>
#include <sensor_msgs/image_encodings.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/stitching/stitcher.hpp>

using namespace std;
namespace enc = sensor_msgs::image_encodings;
static const char WINDOW[] = "Panorama processing";
ros::Publisher pub;
bool bPanoramaTrigger = false, bRotateFinished = false;
std::vector <cv::Mat> vImg;

void stitcherCallback(const sensor_msgs::ImageConstPtr& rgb1, const sensor_msgs::ImageConstPtr& rgb2)
{
    if(!bPanoramaTrigger)
    {
        return;
    }

    cv_bridge::CvImagePtr cv_ptr1, cv_ptr2;
    try
    {
        ROS_INFO("Synchronized images received!");
        // The real-time camera color format is BGR.
        cv_ptr1 = cv_bridge::toCvCopy(rgb1, enc::BGR8);
        cv_ptr2 = cv_bridge::toCvCopy(rgb2, enc::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("tutorialROSOpenCV::main.cpp::cv_bridge exception: %s", e.what());
        return;
    }

    cv::Stitcher stitcher = cv::Stitcher::createDefault();
    cv::Mat rImg;
    vImg.push_back(cv_ptr1->image);
    vImg.push_back(cv_ptr2->image);
    cv::Stitcher::Status status = stitcher.stitch(vImg, rImg);

    if(cv::Stitcher::OK == status)
    {
        cv::imshow(WINDOW, rImg);
        ROS_INFO_STREAM("Stitching current image stream, queue size: " << vImg.size());
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(rgb1, enc::BGR8); // some info should be written in advance.
        cv_ptr->image = rImg;
        pub.publish(cv_ptr->toImageMsg());
        cv_ptr.reset();
    }

    if(bRotateFinished)
    {
        bPanoramaTrigger = false;
        vImg.clear();
        ROS_INFO("Rotate finished, panorama memory released!");
        bRotateFinished = false;
    }

    cv_ptr1.reset();
    cv_ptr2.reset();
}

// panorama trigger
void triggerCallback(const std_msgs::Bool::ConstPtr& msg)
{
    bPanoramaTrigger = msg->data;
    ROS_INFO("Panorama trigger received!");
}

void rotatefinishedCallback(const std_msgs::Bool::ConstPtr& msg)
{
    bRotateFinished = msg->data;
    ROS_INFO("Rotate finished flag received in panorama node!");
}

void mySigintHandler(int sig)
{
    cv::destroyWindow(WINDOW);
    ROS_INFO("Force Quit!");
    //That will create an empty vector with no memory allocated and swap it with tempVector, effectively deallocating the memory.
    std::vector<cv::Mat>().swap(vImg);
    ROS_INFO("Panorama memory released!");
    ros::shutdown();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "panorama_task");
    ros::NodeHandle nh;
    cv::namedWindow(WINDOW);
    cv::startWindowThread();

    message_filters::Subscriber <sensor_msgs::Image> rgb_sub1(nh, "/camera1/rgb/image_rect_color", 1);
    message_filters::Subscriber <sensor_msgs::Image> rgb_sub2(nh, "/camera2/rgb/image_rect_color", 1);
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image> sync_pol;
    message_filters::Synchronizer<sync_pol> sync_dualRGB(sync_pol(10), rgb_sub1, rgb_sub2);
    sync_dualRGB.registerCallback(boost::bind(&stitcherCallback, _1, _2));
    pub = nh.advertise<sensor_msgs::Image>("/panorama", 10);

    ros::Subscriber subTrigger = nh.subscribe("/trigger", 10, triggerCallback);
    ros::Subscriber subRotateFinished = nh.subscribe("/rotate_finished", 10, rotatefinishedCallback);

    signal(SIGINT, mySigintHandler);
    ros::Rate r(0.5);
    ros::spin();

    return 0;
}
