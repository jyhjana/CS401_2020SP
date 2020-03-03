#!/usr/bin/env python
# -*- coding: utf-8 -*-
# The routine will subscribe to/turtle1/pose topic, message type is sturtlesim::Pose

import rospy
from turtlesim.msg import Pose

def poseCallback(msg):
  rospy.loginfo("Turtle pose: x:%0.6f, y:%0.6f", msg.x, msg.y)

def pose_subscriber():
  # ROS init
  rospy.init_node('pose_subscriber', anonymous=True)

  # Create a Subscriber, subscribe to the topic /turtle1/pose, and register the callback function poseCallback
  rospy.Subscriber("/turtle1/pose", Pose, poseCallback)

  # Enter a loop, pumping callbacks
  rospy.spin()

if __name__ == '__main__':
  pose_subscriber()