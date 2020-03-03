#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine  requests the /spawn service, the service data type turtlesim:: spawn

import sys
import rospy

from std_srvs.srv import Trigger, TriggerResponse

if __name__ == "__main__":

    # Initialize the ROS node
    rospy.init_node('turtle_command_client')

    # Once the /turtle_command service is found,
    rospy.wait_for_service('/turtle_command')
    try:
        # create a service client and connect to the service named /spawn
        trigger_turtle = rospy.ServiceProxy('/turtle_command', Trigger)

        # Request service , input request data
        response = trigger_turtle()
        print response.success
        print response.message
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

