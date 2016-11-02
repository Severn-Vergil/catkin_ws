#include <unistd.h>
#include <signal.h>
#include <vector>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/stitching/stitcher.hpp>

//#include <dynamic_reconfigure/server.h>
//#include <image_stitcher/StitcherConfig.h>

namespace enc = sensor_msgs::image_encodings;
static const char WINDOW[] = "Image Processed";
image_transport::Publisher pub;
std::vector <cv::Mat> vImg;

int stitcher_num_frames = 20;
double registr_resol = 0.6;
double seam_est_resol = 0.1;
double compose_resol = -1;
double conf_thresh = 1;
bool do_wave_correct = true;

void stitcherCallback(const sensor_msgs::ImageConstPtr& original_image)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
//        cv_ptr = cv_bridge::toCvCopy(original_image, enc::RGB8);
        cv_ptr = cv_bridge::toCvCopy(original_image, enc::BGR8);
        ROS_INFO("Fuck an image!");
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("tutorialROSOpenCV::main.cpp::cv_bridge exception: %s", e.what());
        return;
    }

//    if (vImg.size() == stitcher_num_frames - 1)
//    {
        vImg.push_back(cv_ptr->image);
        cv::Stitcher stitcher = cv::Stitcher::createDefault();
        stitcher.stitch(vImg, cv_ptr->image);

//        cv::imwrite("images/Panorama.jpg", cv_ptr->image);
//        // check if the picture is to be stitched, if ok, strike the keyboard.
//        cv::imshow(WINDOW, cv_ptr->image);
//        cv::waitKey(-1);

        pub.publish(cv_ptr->toImageMsg());
        // stitch image in your period of set seconds.
//        vImg.clear();
//    }
//    else
//    {
//        vImg.push_back(cv_ptr->image);
//    }
}

//void configCallBack(image_stitcher::StitcherConfig &config, uint32_t level)
//{
//    stitcher_num_frames = config.stitcher_num_frames;
//    registr_resol = config.registr_resol;
//    seam_est_resol = config.seam_est_resol;
//    compose_resol = config.compose_resol;
//    conf_thresh = config.conf_thresh;
//    do_wave_correct = config.do_wave_correct;

//    ROS_INFO("Reconfigure Request: %d %f %f %f %f %d",
//                stitcher_num_frames,
//                registr_resol,
//                seam_est_resol,
//                compose_resol,
//                conf_thresh,
//                do_wave_correct);
//}

void mySigintHandler(int sig)
{
//    cv::destroyWindow(WINDOW);
    ROS_INFO("Force Quit!");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_stitcher");
    ros::NodeHandle nh;

//    dynamic_reconfigure::Server<image_stitcher::StitcherConfig> server;
//    dynamic_reconfigure::Server<image_stitcher::StitcherConfig>::CallbackType f;
//    f = boost::bind(&configCallBack, _1, _2);
//    server.setCallback(f);

    image_transport::ImageTransport it(nh);
//    cv::namedWindow(WINDOW, CV_WINDOW_AUTOSIZE);
    image_transport::Subscriber sub = it.subscribe("/kinect2/qhd/image_color", 1, stitcherCallback);


    pub = it.advertise("/kinect2/image_color_stitched", 1);

    signal(SIGINT, mySigintHandler);
    ros::Rate r(1.0);
    ros::spin();
//    while (ros::ok())
//    {
//        ros::spinOnce();
//    }

    return 0;
}
