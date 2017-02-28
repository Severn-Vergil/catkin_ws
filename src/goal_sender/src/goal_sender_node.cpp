//Author: Shirong Wang
//Goals are predefined in the map and the coordinate can be obtained
//from rviz and map_server, by specifying the initialpose/goals, the
//coordinate will be printed out in the shell of rviz.

// ros package
#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <cmath>
//#include <string>
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

// store the pose in x, y, yaw and its corresponding place
//double pose[][3] =
//{1.35, 5.7 ,  M_PI/2,     // 101
// 1.35, 13.8,  M_PI/2,     // 102
// 1.35, 41.5,  M_PI/2,     // 106
// 1.51, 81.7,  M_PI/4,     // 拐角
// 11.0, 81.3,  0.0   ,     // 进大厅门口
// 17.3, 82.5,  0.0   ,     // 柱子1
// 25.7, 82.5,  0.0   ,     // 柱子2
// 32.5, 82.5,  0.0   ,     // 柱子3
// 33.3, 79.3, -M_PI/4,     // 电梯角落
// 36.0, 79.3, -M_PI/2      // 电梯1
//};

double pose_forward[][3] =
{1.35, 5.7 ,  M_PI/2,     // 101
 1.35, 13.8,  M_PI/2,     // 102
 1.35, 41.5,  M_PI/2,     // 106
 1.35, 80.3,  0.0   ,     // 拐角
 6.60, 80.6,  0.0   ,     // 邮箱旁
 11.0, 80.6,  0.0   ,     // 进大厅右门
 13.2, 80.6, -M_PI/2,     // 进大厅右门框外
 13.2, 79.5, -M_PI/2,     // 电视柜1门侧
 15.0, 76.0,  0.0   ,     // 电视柜1边侧
 17.5, 76.0,  0.0   ,     // 边柱1
 20.0, 76.0,  0.0   ,     // 展板
 25.5, 76.0,  0.0   ,     // 边柱2
 29.5, 76.0,  0.0   ,     // 电视柜2边侧
 33.3, 79.0,  M_PI/4,     // 电梯角落
 36.0, 79.3, -M_PI/2      // 电梯1
};
unsigned int pose_forward_num = sizeof(pose_forward)/sizeof(pose_forward[0]);

double pose_backward[][3] =
{1.35, 5.7 ,  -M_PI/2,     // 101
 1.35, 13.8,  -M_PI/2,     // 102
 1.35, 41.5,  -M_PI/2,     // 106
 1.35, 80.3,  M_PI   ,     // 拐角
 8.0,  80.6,  M_PI  ,     // 邮箱旁
 11.0, 80.6,  0.0   ,     // 进大厅右门
 12.0, 81.0, -3*M_PI/4,   // 进大厅门框内
 13.2, 79.5,  M_PI/2,     // 电视柜1门侧
 13.2, 79.0,  3*M_PI/4,   // 电视柜1角落
 13.8, 77.5,  3*M_PI/4,   // 电视柜1中点
 15.0, 76.0,  M_PI  ,     // 电视柜1边侧
 20.0, 76.0,  M_PI  ,     // 边柱1
 22.5, 76.0,  M_PI  ,     // 展板中点
 25.2, 76.0,  M_PI  ,     // 展板
 27.5, 76.0,  M_PI  ,     // 边柱2
 30.0, 76.5, -M_PI/2,     // 电视柜2边侧
 33.3, 79.0, -M_PI/2,     // 电梯角落
 36.0, 79.3,  M_PI/2      // 电梯1
};
unsigned int pose_backward_num = sizeof(pose_backward)/sizeof(pose_backward[0]);


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
    for(unsigned int i = 0; i < pose_forward_num; i++)
    {
        goal.target_pose.header.frame_id = "map";
        goal.target_pose.header.stamp = ros::Time::now();

        // using tf tools to set data into goal message.
        ptf.setValue(pose_forward[i][0], pose_forward[i][1], 0.0);
        tf::pointTFToMsg(ptf, p);
        qtf.setRPY(0.0, 0.0, pose_forward[i][2]);
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

//    // goes back!
//    for(unsigned int i = pose_backward_num-1; i >= 0; i--)
//    {
//        goal.target_pose.header.frame_id = "map";
//        goal.target_pose.header.stamp = ros::Time::now();

//        // using tf tools to set data into goal message.
//        ptf.setValue(pose_backward[i][0], pose_backward[i][1], 0.0);
//        tf::pointTFToMsg(ptf, p);
//        qtf.setRPY(0.0, 0.0, pose_backward[i][2]);
//        tf::quaternionTFToMsg(qtf, q);
//        goal.target_pose.pose.position = p;
//        goal.target_pose.pose.orientation = q;
//        ROS_INFO("Sending goal!");
//        ac.sendGoal(goal);
//        // wait until receive the result.
//        ac.waitForResult();
//        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
//        {
//            ROS_INFO("Successfully reach the goal %d!", (i+1));
//        }
//        else
//        {
//            ROS_INFO("Failed for the goal %d!", (i+1));
//            break;
//        }
//    }

    return 0;
}
