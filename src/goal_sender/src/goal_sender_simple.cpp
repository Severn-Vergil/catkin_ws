//Author: Shirong Wang
//A simple goal reaching task for CCC 2017.

// ros package
#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <cmath>
#include <string>
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

// store the pose in x, y, yaw and its corresponding place
double pose[][3] =
{3.0, 0.0 , M_PI/2,     // 101
};
unsigned int pose_num = sizeof(pose)/sizeof(pose[0]);

int main(int argc, char** argv)
{
    ros::init(argc, argv, "goal_sender");

    // tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    // wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up!");
    }

    move_base_msgs::MoveBaseGoal goal;
    geometry_msgs::Point p;
    tf::Point ptf;
    geometry_msgs::Quaternion q;
    tf::Quaternion qtf;

    // send goals in the map frame
    for(unsigned int i = 0; i < pose_num; i++)
    {
        goal.target_pose.header.frame_id = "map";
        goal.target_pose.header.stamp = ros::Time::now();

        // using tf tools to set data into goal message.
        ptf.setValue(pose[i][0], pose[i][1], 0.0);
        tf::pointTFToMsg(ptf, p);
        qtf.setRPY(0.0, 0.0, pose[i][2]);
        tf::quaternionTFToMsg(qtf, q);
        goal.target_pose.pose.position = p;
        goal.target_pose.pose.orientation = q;
        ROS_INFO("Sending goal!");
        ac.sendGoal(goal);
        // wait until receive the result.
        ac.waitForResult();
        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        {
            ROS_INFO("Successfully reach the goal %d!", (i+1));
        }
        else
        {
            ROS_INFO("Failed for the goal %d!", (i+1));
            break;
        }
    }

    return 0;
}
