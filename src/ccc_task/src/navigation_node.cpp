#include <ros/ros.h>
#include <angles/angles.h>
#include <tf/tf.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/Bool.h>

// store the pose in x, y, yaw and its corresponding place
double pose[][3] =
{3.5, 0.0 , angles::from_degrees(0.0),
};
unsigned int current_num = 0, pose_num = sizeof(pose)/sizeof(pose[0]);
bool bRotateFinished = false, bTrigger = false;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
ros::Publisher pubTrigger;

void rotatefinishedCallback(const std_msgs::Bool::ConstPtr& msg)
{
    bRotateFinished = msg->data;
    if(bRotateFinished)
    {
        ROS_INFO("Rotate finished, navigation begin!");
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
        if(current_num < pose_num)
        {
            unsigned int i = current_num;
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
                ROS_INFO("Successfully reach the goal %d, trigger open!", (i+1));
                bTrigger = true;
                std_msgs::Bool bmsg;
                bmsg.data = bTrigger;
                pubTrigger.publish(bmsg);
                bRotateFinished = false;
            }
            else
            {
                ROS_INFO("Failed for the goal %d!", (i+1));
                return;
            }
            current_num += 1;
        }
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "navigation_task");
    ros::NodeHandle nh;
    ros::Subscriber subRotateFinished = nh.subscribe("/rotate_finished", 10, rotatefinishedCallback);
    pubTrigger = nh.advertise<std_msgs::Bool>("/trigger", 10);
    ros::Rate(10.0);
    ros::spin();
    return 0;
}
