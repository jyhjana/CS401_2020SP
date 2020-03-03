#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine  requests the /spawn service, the service data type turtlesim:: spawn

import sys
import rospy
from turtlesim.srv import Spawn

def turtle_spawn():
    # Initialize the ROS node
    rospy.init_node('turtle_spawn')

    # Once the /spawn service is found,
    rospy.wait_for_service('/spawn')
    try:
        # create a service client and connect to the service named /spawn
        add_turtle = rospy.ServiceProxy('/spawn', Spawn)

        # Request service , input request data
        response = add_turtle(8.0, 8.0, 0.0, "turtle2")
        return response.name
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":
    #Displays the result of the response
    print "Spwan turtle successfully [name:%s]" %(turtle_spawn())