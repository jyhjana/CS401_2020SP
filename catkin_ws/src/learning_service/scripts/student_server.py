#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine will execute /student_score, service data type learning_service::Student

import rospy
from learning_service.srv import Student, StudentResponse

def studentCallback(req):
    # Display request data
    rospy.loginfo("the student id:%s ", req.id,)


    # Feedback data
    return StudentResponse("Jimmy", "12345678",StudentResponse.junior,95.8)

def student_server():
    # Initialize the ROS nodes
    rospy.init_node('student_server')

    # Create a server named /show_student and
    # register the callback function studentCallback
    s = rospy.Service('/student_score', Student, studentCallback)

    # Enter the event loop and
    # wait for the callback function studentCallback
    print "Ready to response student's score."
    rospy.spin()

if __name__ == "__main__":
    student_server()