#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
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

using namespace std;
namespace enc = sensor_msgs::image_encodings;
static const char WINDOW[] = "Panorama processing";
//image_transport::Publisher pub;
ros::Publisher pub;
std::vector <cv::Mat> vImg;

void stitcherCallback(const sensor_msgs::ImageConstPtr& rgb1, const sensor_msgs::ImageConstPtr& rgb2)
{
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
        // filename string concatnating
        char filename[] = "Panorama_";
        int nValue = vImg.size();
        char* szBuffer = (char *)malloc(sizeof(int) + 1);  //allocate memory
        memset(szBuffer, 0, sizeof(int) + 1);              //set memory
        sprintf(szBuffer, "%d", nValue);                   //convert integer to string
        strcat(filename, szBuffer);
        free(szBuffer);
        strcat(filename, ".jpg");
        printf("%s\n", filename);
        cv::imwrite(filename, rImg);

//        sensor_msgs::ImagePtr msg;
//        msg = cv_bridge::CvImage(std_msgs::Header(), "rgb8", rImg).toImageMsg();
//        pub.publish(msg);
        ROS_INFO_STREAM("Stitching current image stream, queue size: " << vImg.size());
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(rgb1, enc::BGR8); // some info should be written in advance.
        cv_ptr->image = rImg;
        pub.publish(cv_ptr->toImageMsg());
        cv_ptr.reset();
    }
    cv_ptr1.reset();
    cv_ptr2.reset();
}

void mySigintHandler(int sig)
{
    cv::destroyWindow(WINDOW);
    ROS_INFO("Force Quit!");
//    vImg.clear(); // Not reall work.
    //That will create an empty vector with no memory allocated and swap it with tempVector, effectively deallocating the memory.
    std::vector<cv::Mat>().swap(vImg);
    ROS_INFO("Memory released!");
    ros::shutdown();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_stitcher");
    ros::NodeHandle nh;
    cv::namedWindow(WINDOW);
    cv::startWindowThread();

    message_filters::Subscriber <sensor_msgs::Image> rgb_sub1(nh, "/camera1/rgb/image_rect_color", 1);
    message_filters::Subscriber <sensor_msgs::Image> rgb_sub2(nh, "/camera2/rgb/image_rect_color", 1);
//    // typedef synchronizer of RGB 1 and RGB 2
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image> sync_pol;
    message_filters::Synchronizer<sync_pol> sync_dualRGB(sync_pol(10), rgb_sub1, rgb_sub2);
    sync_dualRGB.registerCallback(boost::bind(&stitcherCallback, _1, _2));
//    message_filters::TimeSynchronizer<sensor_msgs::Image, sensor_msgs::Image> sync(rgb_sub1, rgb_sub2, 10);
//    sync.registerCallback(boost::bind(&stitcherCallback, _1, _2));

//    ros::Subscriber sub = nh.subscribe("/camera/rgb/image_rect_color", 10, stitcherCallback);

    pub = nh.advertise<sensor_msgs::Image>("/panorama", 10);

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
