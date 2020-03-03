/**
 * The routine will subscribe to/turtle1/pose topic, message type is turtlesim::Pose
 */
 
#include <ros/ros.h>
#include "turtlesim/Pose.h"


//After receiving the subscribed message,
// enter the message callback function
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // Print out the received message
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

int main(int argc, char **argv)
{
    // ROS init
    ros::init(argc, argv, "pose_subscriber");

    // Create a node handle
    ros::NodeHandle n;

    // Create a Subscriber, subscribe to the topic /turtle1/pose,
    // and register the callback function poseCallback
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}
