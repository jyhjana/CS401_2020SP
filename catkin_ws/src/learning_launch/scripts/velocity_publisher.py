#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine will publish the turtle1/cmd_vel topic, message type is geometry_msgs::Twist

import rospy
from geometry_msgs.msg import Twist

def velocity_publisher():
  # ROS init
  rospy.init_node('velocity_publisher', anonymous=True)

  # Create a Publisher, publish a topic named /turtle1/cmd_vel, message type: geometry_msgs:Twist, queue length 10
  turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
  publish_frequency = rospy.get_param('~publish_frequency')
  #Set the frequency of the loop
  rate = rospy.Rate(publish_frequency)

  while not rospy.is_shutdown():
    # Initialize the message of  geometry_msgs::Twist
    vel_msg = Twist()
    vel_msg.linear.x = rospy.get_param('~linear_x')
    vel_msg.angular.z = rospy.get_param('~group/angular_z')

    # pulish message
    turtle_vel_pub.publish(vel_msg)
    rospy.loginfo("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",
                  vel_msg.linear.x, vel_msg.angular.z)

    # Delay by cycle frequency
    rate.sleep()

if __name__ == '__main__':
  try:
    velocity_publisher()
  except rospy.ROSInterruptException:
    pass