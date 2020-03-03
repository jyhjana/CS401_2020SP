//
// Created by jyh on 2020/2/23.
//

/**
 * This routine will execute /student_score, service data type learning_service::Student
 */

#include <ros/ros.h>
#include "learning_service/Student.h"

// Service callback function, input parameter req, output parameter res
bool studentCallback(learning_service::Student::Request  &req,
                    learning_service::Student::Response &res)
{
    // Display request data
    ROS_INFO("Student: id: %s",req.id.c_str());

    // Set feedback data
    res.name = "Jimmy";
    res.grade  = learning_service::Student::Response::sophomore;
    res.id = "12345678";
    res.score  = 90.5;
    return true;
}

int main(int argc, char **argv)
{
    // Initialize the ROS nodes
    ros::init(argc, argv, "student_server");

    // Create a node handle
    ros::NodeHandle n;

    // Create a server named /show_student and register the callback function studentCallback
    ros::ServiceServer student_service = n.advertiseService("/student_score", studentCallback);


    ROS_INFO("Ready to response student's score.");
    // Enter the event loop and wait for the callback function studentCallback
    ros::spin();

    return 0;
}