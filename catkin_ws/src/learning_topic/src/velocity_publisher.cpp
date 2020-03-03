//
// Created by jyh on 2020/2/23.
//

/**
 * This routine will publish the turtle1/cmd_vel topic, message type is geometry_msgs::Twist
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    // ROS init
    ros::init(argc, argv, "velocity_publisher");

    // Create a node handle
    ros::NodeHandle n;

    // Create a Publisher, publish a topic named /turtle1/cmd_vel, message type: geometry_msgs:Twist, queue length 10
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // Set the frequency of the loop
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // Initialize the message of  geometry_msgs::Twist
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;

        // publish message
        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",
                 vel_msg.linear.x, vel_msg.angular.z);

        // Delay by loop frequency
        loop_rate.sleep();
    }

    return 0;
}