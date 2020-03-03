#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This routine will subscribe to /student topic, customizing the message type learning_topic/Student

import rospy
from learning_topic.msg import Student

def studentCallback(msg):
  rospy.loginfo("Subcribe Student's score: [name:%s, id:%s, grade:%d,score:%.2f]",
                msg.name, msg.id,msg.grade, msg.score)


def student_subscriber():
  # ROS init
  rospy.init_node('person_subscriber', anonymous=True)

  # Create a Subscriber, subscribe to the topic /person_info,
  # and register the callback function studentCallback
  rospy.Subscriber("/student_score", Student, studentCallback)

  # wait for the callback function
  rospy.spin()

if __name__ == '__main__':
  student_subscriber()