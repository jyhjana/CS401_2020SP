#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine sets/reads the parameters in the turtle routine

import sys
import rospy
from std_srvs.srv import Empty


def parameter_config():
    # ROS node initialization
    rospy.init_node('parameter_config', anonymous=True)

    # Read the background color parameter
    red = rospy.get_param('/background_r')
    green = rospy.get_param('/background_g')
    blue = rospy.get_param('/background_b')

    rospy.loginfo("Get Backgroud Color[%d, %d, %d]", red, green, blue)

    # Set background color parameters
    rospy.set_param("/background_r", 255);
    rospy.set_param("/background_g", 255);
    rospy.set_param("/background_b", 255);

    rospy.loginfo("Set Backgroud Color[255, 255, 255]");

    # Read the background color parameter
    red = rospy.get_param('/background_r')
    green = rospy.get_param('/background_g')
    blue = rospy.get_param('/background_b')

    rospy.loginfo("Get Backgroud Color[%d, %d, %d]", red, green, blue)

    # Call the service and refresh the background color
    rospy.wait_for_service('/clear')
    try:
        clear_background = rospy.ServiceProxy('/clear', Empty)

        # Request service
        response = clear_background()
        return response
    except rospy.ServiceException, e:
        print "Service call failed: %s" % e


if __name__ == "__main__":
    parameter_config()


