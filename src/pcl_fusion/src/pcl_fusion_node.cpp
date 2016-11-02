// 2016.07.22 fuck opening
#include <ros/ros.h>
#include <tf/transform_listener.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/transforms.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;
tf::TransformListener * listener;
sensor_msgs::PointCloud2 output, output1, output2;
pcl::PCLPointCloud2 output_pcl, output1_pcl, output2_pcl;


// pcl pointcloud2 not support +
// pcl pointXYZ support +

// either new pcl from camera1 or camera2 will flush the output stack.
void cloud_cb1(const sensor_msgs::PointCloud2ConstPtr& input1)
{
    // set transform of the ros pcl message
    listener->waitForTransform("/base_link", (*input1).header.frame_id, (*input1).header.stamp, ros::Duration(5.0));
    pcl_ros::transformPointCloud("/base_link", *input1, output1, *listener);

    // Container for original & filtered data
    pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
    // Convert to PCL data type
    pcl_conversions::toPCL(output1, *cloud);

    // Perform the actual filtering
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    sor.setInputCloud(cloudPtr); //set pointer of the cloud
    sor.setLeafSize(0.05, 0.05, 0.05);
    sor.filter(output1_pcl);

    pcl::concatenatePointCloud(output1_pcl, output2_pcl, output_pcl);

    // Convert to ROS data type
    sensor_msgs::PointCloud2 output;
    pcl_conversions::moveFromPCL(output_pcl, output);

    // Publish the data
    output.header.frame_id = "base_link";
    pub.publish (output);

}

void cloud_cb2(const sensor_msgs::PointCloud2ConstPtr& input2)
{
    // set transform of the ros pcl message
    listener->waitForTransform("/base_link", (*input2).header.frame_id, (*input2).header.stamp, ros::Duration(5.0));
    pcl_ros::transformPointCloud("/base_link", *input2, output2, *listener);

    // Container for original & filtered data
    pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
    // Convert to PCL data type
    pcl_conversions::toPCL(output2, *cloud);

    // Perform the actual filtering
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    sor.setInputCloud(cloudPtr); //set pointer of the cloud
    sor.setLeafSize(0.05, 0.05, 0.05);
    sor.filter(output2_pcl);

    pcl::concatenatePointCloud(output1_pcl, output2_pcl, output_pcl);

    // Convert to ROS data type
    sensor_msgs::PointCloud2 output;
    pcl_conversions::moveFromPCL(output_pcl, output);

    // Publish the data
    output.header.frame_id = "base_link";
    pub.publish (output);
}



//// either new pcl from camera1 or camera2 will flush the output stack.
//// Only keep XYZ data without RGB
/// pcl::PointCloud<pcl::PointXYZ> output_pcl, output1_pcl, output2_pcl;
//void cloud_cb1(const sensor_msgs::PointCloud2ConstPtr& input1)
//{
//    listener->waitForTransform("/base_link", (*input1).header.frame_id, (*input1).header.stamp, ros::Duration(5.0));
//    pcl_ros::transformPointCloud("/base_link", *input1, output1, *listener);
//    pcl::fromROSMsg(output1, output1_pcl);
//    output_pcl = output1_pcl;
//    output_pcl += output2_pcl;
//    pcl::toROSMsg(output_pcl, output);
//    pub.publish(output);
//}

//void cloud_cb2(const sensor_msgs::PointCloud2ConstPtr& input2)
//{
//    listener->waitForTransform("/base_link", (*input2).header.frame_id, (*input2).header.stamp, ros::Duration(5.0));
//    pcl_ros::transformPointCloud("/base_link", *input2, output2, *listener);
//    pcl::fromROSMsg(output2, output2_pcl);
//    output_pcl = output2_pcl;
//    output_pcl += output1_pcl;
//    pcl::toROSMsg(output_pcl, output);
//    pub.publish(output);
//}

int main (int argc, char **argv)
{
    ros::init (argc, argv, "pcl_fusion");
    ros::NodeHandle n;

    listener = new tf::TransformListener();
    ros::Subscriber sub1 = n.subscribe("/camera1/depth_registered/points", 1, cloud_cb1);
    ros::Subscriber sub2 = n.subscribe("/camera2/depth_registered/points", 1, cloud_cb2);

    pub = n.advertise<sensor_msgs::PointCloud2>("/camera_merged/depth_registered/points", 1);
    ros::spin();

    return 0;
}
