//
// Created by jyh on 2020/2/23.
//
/**
 * This routine  requests the /spawn service, the service data type turtlesim:: spawn
 */

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "turtle_spawn");

    // Create a node handle
    ros::NodeHandle node;


    //Once the /spawn service is found,
    // create a service client and connect to the service named /spawn
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    // Initialize the service data for turtlesim::Spawn
    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";


    ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]",
             srv.request.x, srv.request.y, srv.request.name.c_str());
    // Request service
    add_turtle.call(srv);

    // Displays the result of the response
    ROS_INFO("Spwan turtle successfully [name:%s]", srv.response.name.c_str());

    return 0;
};
