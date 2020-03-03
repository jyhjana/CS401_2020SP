#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine will request the /student_score service,
# the service data type learning_service::Student

import sys
import rospy
from learning_service.srv import Student, StudentRequest

def student_client():
    # Initialize the ROS nodes
    rospy.init_node('student_client')

    # Wait for the /student_score service to start
    rospy.wait_for_service('/student_score')
    try:
        # Create a service client, and connect to the service named /student_score
        student_client = rospy.ServiceProxy('/student_score', Student)

        # Request service , input request data
        response = student_client("12345678")
        return response
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":
    #The service is invoked and the result is displayed
    print "Show Student's score:\n%s" %(student_client())