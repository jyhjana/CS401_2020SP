#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine will execute the /turtle_command service with the service data type std_srvs/Trigger

import rospy
import thread,time
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger, TriggerResponse

pubCommand = False;
turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)

def command_thread():
    while True:
        if pubCommand:
            vel_msg = Twist()
            vel_msg.linear.x = 0.5
            vel_msg.angular.z = 0.2
            turtle_vel_pub.publish(vel_msg)

        time.sleep(0.1)

def commandCallback(req):
    global pubCommand
    pubCommand = bool(1-pubCommand)

    # Display request data
    rospy.loginfo("Publish turtle velocity command![%d]", pubCommand)

    # Feedback
    return TriggerResponse(1, "Change turtle command state!")

def turtle_command_server():
    # Initialize the ROS node
    rospy.init_node('turtle_command_server')


    # Create a server named /turtle_command and
    # register the callback function commandCallback
    s = rospy.Service('/turtle_command', Trigger, commandCallback)


    print "Ready to receive turtle command."

    thread.start_new_thread(command_thread, ())
    # Wait for the callback function
    rospy.spin()

if __name__ == "__main__":
    turtle_command_server()