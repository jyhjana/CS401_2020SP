//
// Created by jyh on 2020/2/23.
//
/**
 * This routine will request the /student_score service, the service data type learning_service::Student
 */

#include <ros/ros.h>
#include "learning_service/Student.h"

int main(int argc, char** argv)
{
    // Initialize the ROS nodes
    ros::init(argc, argv, "student_client");

    // Create a node handle
    ros::NodeHandle node;


    // Wait for the /student_score service to start
    ros::service::waitForService("/student_score");
    // Create a service client, and connect to the service named /student_score
    ros::ServiceClient student_client = node.serviceClient<learning_service::Student>("/student_score");

    // Initialize the request data for learning_service::Student
    learning_service::Student srv;
    srv.request.id = "12345678";



    ROS_INFO("Call service to show student's score[ id:%s ]",
             srv.request.id.c_str()
             );
    // Call the service
    student_client.call(srv);

    // Displays the result of the service response
    ROS_INFO("Show student's score[name:%s, id:%s, grade:%d, score:%.2f]",
             srv.response.name.c_str(),
             srv.response.id.c_str(),
             srv.response.grade,
             srv.response.score);

    return 0;
};
