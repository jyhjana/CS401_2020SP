/**
 * This routine will subscribe to /student topic, customizing the message type learning_topic/Student
 */
 
#include <ros/ros.h>
#include "learning_topic/Student.h"


//After receiving the subscribed message,
// enter the message callback function
void studentCallback(const learning_topic::Student::ConstPtr& msg)
{
    // Print out the received message
    ROS_INFO("Subcribe Student's score : name:%s  id:%s grade:%d  score:%.2f",
			 msg->name.c_str(),msg->id.c_str(), msg->grade, msg->score);
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "student_subscriber");

    // Create a node handle
    ros::NodeHandle n;


    // Create a Subscriber, subscribe to the topic /student,
    // and register the callback function studentCallback
    ros::Subscriber person_info_sub = n.subscribe("/student_score", 10, studentCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}
