#include <unistd.h>
#include <signal.h>
#include <vector>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/stitching/stitcher.hpp>

namespace enc = sensor_msgs::image_encodings;
static const char WINDOW[] = "Panorama processing";
//image_transport::Publisher pub;
ros::Publisher pub;
std::vector <cv::Mat> vImg;

void stitcherCallback(const sensor_msgs::ImageConstPtr& original_image)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
        // The real-time camera color format is BGR.
        cv_ptr = cv_bridge::toCvCopy(original_image, enc::BGR8);
        ROS_INFO("Receive an image!");
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("tutorialROSOpenCV::main.cpp::cv_bridge exception: %s", e.what());
        return;
    }

    cv::Stitcher stitcher = cv::Stitcher::createDefault();
    cv::Mat rImg;
    vImg.push_back(cv_ptr->image);
    cv::Stitcher::Status status = stitcher.stitch(vImg, rImg);

    if(cv::Stitcher::OK == status)
    {
        cv::imshow(WINDOW, rImg);
        cv_ptr->image = rImg;
        pub.publish(cv_ptr->toImageMsg());
        ROS_INFO("Stitching current image stream, queue size: %u", vImg.size());
    }

}

void mySigintHandler(int sig)
{
    cv::destroyWindow(WINDOW);
    ROS_INFO("Force Quit!");
    vImg.clear();
    ros::shutdown();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_stitcher");
    ros::NodeHandle nh;
    cv::namedWindow(WINDOW);
    cv::startWindowThread();
    ros::Subscriber sub = nh.subscribe("/camera/rgb/image_rect_color", 10, stitcherCallback);
    pub = nh.advertise<sensor_msgs::Image>("/image_color_stitched", 10);

    signal(SIGINT, mySigintHandler);
    ros::Rate r(0.5);
    ros::spin();
//    while (ros::ok())
//    {
//        ros::spinOnce();
//        r.sleep();
//    }
    return 0;
}

