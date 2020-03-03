/**
 * This routine publish /student topic, customizing the message type: learning_topic:: student
 */
 
#include <ros/ros.h>
#include "learning_topic/Student.h"

int main(int argc, char **argv)
{
    // ROS init
    ros::init(argc, argv, "student_publisher");

    // Create a node handle
    ros::NodeHandle n;

    //  Create a Publisher, publish a topic named /student, message type:learning_topic::Student, queue length 10
    ros::Publisher person_info_pub = n.advertise<learning_topic::Student>("/student_score", 10);

    // Set the frequency of the loop
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        // Initialize the message of learning_topic::Student
    	learning_topic::Student msg;
		msg.name = "Jimmy";
		msg.id = "12345678";
		msg.grade  = learning_topic::Student::junior;
		msg.score  = 90.8;

        // publish message
		person_info_pub.publish(msg);

       	ROS_INFO("Publish Student's score : name:%s  id:%s age:%d  float32:%.2f",
                 msg.name.c_str(),msg.id.c_str(), msg.grade, msg.score);



        // Delay by loop frequency
        loop_rate.sleep();
    }

    return 0;
}
