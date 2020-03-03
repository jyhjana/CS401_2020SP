//
// Created by jyh on 2020/2/23.
//
/**
 * This routine  requests the /spawn service, the service data type turtlesim:: spawn
 */

#include <ros/ros.h>
#include <std_srvs/Trigger.h>

int main(int argc, char** argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "turtle_spawn");

    // Create a node handle
    ros::NodeHandle node;


    //Once the /spawn service is found,
    // create a service client and connect to the service named /spawn
    ros::service::waitForService("/turtle_command");
    ros::ServiceClient add_turtle = node.serviceClient<std_srvs::Trigger>("/turtle_command");

    // Initialize the service data for std_srvs::Trigger
    std_srvs::Trigger srv;

    // Request service
    add_turtle.call(srv);

    // Displays the result of the response
    ROS_INFO("%s \n %s", srv.response.success?"True":"false", srv.response.message.c_str());

    return 0;
};
