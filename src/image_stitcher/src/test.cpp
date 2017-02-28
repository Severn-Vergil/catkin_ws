#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/stitching/stitcher.hpp"
#include <string>
#include <sstream>

using namespace cv;
using namespace std;

static const std::string PANORAMA = "Panorama";
static int imageCounter = 1;

class ImageStitching
{
	//---Variable Decleration
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;

	//---Images
	cv::Mat inputImg;
	cv::Mat newStitchedImg, previousStitchedImg;
	cv::Mat outputImg;

	vector<Mat> imageArray;

	bool firstShow;

public:
	ImageStitching():it_(nh_)
	{
		firstShow = true;
		//---Subscrive to input video feed and publish output video feed
		image_sub_ = it_.subscribe("/usb_cam/image_rect_color", 1, &ImageStitching::imageCb, this);
		cv::namedWindow(PANORAMA);
	}

	~ImageStitching()
	{
		cv::destroyWindow(PANORAMA);
	}

	void imageCb(const sensor_msgs::ImageConstPtr& msg)
	{
		cv_bridge::CvImagePtr cv_ptr;
	try
	{
		//--convert ROS image msg to OpenCV Mat object
		cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
	}
	catch (cv_bridge::Exception& e)
	{
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	} 
		inputImg = cv_ptr->image;
		//--Push new image frame into Mat vector
		imageArray.push_back(inputImg);
		//---Image Stitching---//
		imageStitching();
		cv::waitKey(3);
	}

	void imageStitching()
	{
		//--Check vector size if 8 if yes remove first image and shift images
		if (imageArray.size() >= 8)
		{ 
			shiftVector(); 
		}

		//--Create Stitcher object
		Stitcher stitcherObj = Stitcher::createDefault();

		//--Do stitching on Mat vector images and output newStitchedImg
		stitcherObj.stitch(imageArray, newStitchedImg);

		int stitchedRows = (int)newStitchedImg.rows;
		//--Display newStitchedImg only if its width is greater than 100 (not empty)
		if (stitchedRows >= 100)
		{
			cv::imshow(PANORAMA, newStitchedImg);
			//--put newStitchedImg to previousStitchedImg
			previousStitchedImg = newStitchedImg;
			firstShow = false;
		}
		//--Show previousStitchedImg when newStitchedImg is empty
		else if (!firstShow)
		{ 
			cv::imshow(PANORAMA, previousStitchedImg); }
		}

	void shiftVector()
	{
		ROS_INFO("----Erasing Vector current Size: %ld", imageArray.size());
		for(int i=0; i<7; i++)
		{
			imageArray.at(i) = imageArray.at(i+1);
		}
		imageArray.erase(imageArray.end());
		ROS_INFO("-----Vectore size after erasing: %ld", imageArray.size());
	}
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "image_stitching");
	ImageStitching is;
	ros::spin();
	return 0;
}