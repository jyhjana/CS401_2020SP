#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine publish /student topic, customizing the message type: learning_topic:: student

import rospy
from learning_topic.msg import Student


def student_publisher():
  # ROS init
  rospy.init_node('student_publisher', anonymous=True)

  # Create a Publisher named /student, message type learning_topic:: student, queue length 10
  person_info_pub = rospy.Publisher('/student_score', Student, queue_size=10)

  #Set the frequency of the loop
  rate = rospy.Rate(10)

  while not rospy.is_shutdown():
    # Initializes a message of  learning_topic::Person
    msg = Student()
    msg.name = "Jimmy"
    msg.grade  = Student.junior
    msg.id  = "12345678"
    msg.score = 95.3

    # publish message
    person_info_pub.publish(msg)
    rospy.loginfo("Publsh Student's score[%s, %s, %d,%.2f]",
                  msg.name, msg.id,msg.grade, msg.score)

    # Delay by cycle frequency
    rate.sleep()

if __name__ == '__main__':
  try:
    student_publisher()
  except rospy.ROSInterruptException:
    pass