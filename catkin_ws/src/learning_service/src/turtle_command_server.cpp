//
// Created by jyh on 2020/2/23.
//
/**
 * This routine will execute the /turtle_command service with the service data type std_srvs/Trigger
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool pubCommand = false;

// Service callback function, input parameter req, output parameter res
bool commandCallback(std_srvs::Trigger::Request  &req,
                     std_srvs::Trigger::Response &res)
{
    pubCommand = !pubCommand;

    // Display request data
    ROS_INFO("Publish turtle velocity command [%s]", pubCommand==true?"Yes":"No");

    // Set feedback data
    res.success = true;
    res.message = "Change turtle command state!";

    return true;
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "turtle_command_server");

    // Create a node handle
    ros::NodeHandle n;

    // Create a server named /turtle_command and register the callback function commandCallback
    ros::ServiceServer command_service = n.advertiseService("/turtle_command", commandCallback);

    // Create a Publisher and publish a topic named /turtle1/cmd_vel, message type is
    // geometry_msgs::Twist, queue length is 10
    turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);


    ROS_INFO("Ready to receive turtle command.");

    // Set the frequency of the loop
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        // View a callback function queue
        ros::spinOnce();

        // If the flag is true, the speed instruction is issued
        if(pubCommand)
        {
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x = 0.5;
            vel_msg.angular.z = 0.2;
            turtle_vel_pub.publish(vel_msg);
        }

        // Delay
        loop_rate.sleep();
    }

    return 0;
}
