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
static const char WINDOW[] = "Panorama processing";
image_transport::Publisher pub;
std::vector <cv::Mat> vImg;

//int stitcher_num_frames = 20;
//double registr_resol = 0.6;
//double seam_est_resol = 0.1;
//double compose_resol = -1;
//double conf_thresh = 1;
//bool do_wave_correct = true;
void stitcherCallback(const sensor_msgs::ImageConstPtr& original_image)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
        // The real-time camera color format is BGR.
//        cv_ptr = cv_bridge::toCvCopy(original_image, enc::RGB8);
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
        ROS_INFO("Stitching current image stream.");
        // using same size for stitching is needed.
//        ROS_INFO("Stitching current image, clear image queue and push panorama.");
//        vImg.clear();
//        vImg.push_back(rImg);
    }
//    else
//    {
//        vImg.pop_back();
//        ROS_INFO("Bad stitching.");
//    }

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
    cv::destroyWindow(WINDOW);
    ROS_INFO("Force Quit!");
    ros::shutdown();
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
    cv::namedWindow(WINDOW, CV_WINDOW_AUTOSIZE);
    image_transport::Subscriber sub = it.subscribe("/camera/rgb/image_rect_color", 1, stitcherCallback);


    pub = it.advertise("/image_color_stitched", 1);

    signal(SIGINT, mySigintHandler);
    ros::Rate r(0.5);
//    ros::spin();
    while (ros::ok())
    {
        ros::spinOnce();
        r.sleep();
    }

    return 0;
}
