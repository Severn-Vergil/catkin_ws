#include <ros/ros.h>
#include <angles/angles.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Bool.h>

// messages data
double turn_angle = angles::from_degrees(0.0), goal_angle = angles::from_degrees(360.0), last_angle = angles::from_degrees(0.0);
bool bRotateTrigger = false, bRotateFinished = false;
ros::Publisher pubVel, pubRotateFinished;

double getYaw(geometry_msgs::Quaternion qmsg)
{
    tf::Quaternion q;
    double roll, pitch, yaw;
    tf::quaternionMsgToTF(qmsg, q);
    tf::Matrix3x3(q).getRPY(roll, pitch, yaw);
    return yaw;
}

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    double current_angle = getYaw(msg->pose.pose.orientation);
    double delta_angle = angles::normalize_angle(current_angle - last_angle);
    double eps = angles::from_degrees(1.0);
    turn_angle += delta_angle;
    last_angle = current_angle;

    geometry_msgs::Twist cmd;
    if((turn_angle + eps) < goal_angle && bRotateTrigger)
    {
        cmd.angular.z = 0.4;    // radian per second
        pubVel.publish(cmd);
    }
    else
    {
        if((turn_angle + eps) > goal_angle)
        {
            cmd.angular.z = 0.0;    // radian per second
            pubVel.publish(cmd);
            bRotateFinished = true;
            bRotateTrigger = false;
            turn_angle = angles::from_degrees(0.0);
            std_msgs::Bool bmsg;
            bmsg.data = bRotateFinished;
            pubRotateFinished.publish(bmsg);
            ROS_INFO("Rotate process finished, set trigger to false and angle to zero!");
        }
    }
}

// rotate behavior trigger
void triggerCallback(const std_msgs::Bool::ConstPtr& msg)
{
    bRotateTrigger = msg->data;
    ROS_INFO("Rotate trigger received!");
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "rotate_task");
    ros::NodeHandle nh;
    ros::Rate rate(50.0);   // match with odometry speed.
    ros::Subscriber subOdom = nh.subscribe("/odom", 1000, odomCallback);
    ros::Subscriber subTrigger = nh.subscribe("/trigger", 10, triggerCallback);
    pubVel = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 10);
    pubRotateFinished = nh.advertise<std_msgs::Bool>("/rotate_finished", 10);
    ros::spin();
    return 0;
}
