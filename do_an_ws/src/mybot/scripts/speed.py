#!/usr/bin/env python

#Read speed data of 2 motor from stm32 and publish on ROS

#topic need to publish for odometry:
#
import rospy
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist, Vector3Stamped
from sensor_msgs.msg import NavSatFix
import serial
import RPi.GPIO as GPIO
from time import sleep

speed_act_left = 0                   #Actual speed for left wheel in m/s
speed_act_right = 0 


# nh = rospy.init_node("speed")

# LOOPTIME = 10

def cmd_vel_cb(twist):
    global demandx, demandz
    demandx = twist.linear.x
    demandz = twist.angular.z

sub = rospy.Subscriber("cmd_vel",Twist, cmd_vel_cb)

speed_msg = Vector3Stamped()
speed_pub = rospy.Publisher("speed", Vector3Stamped, queue_size=10)
gps_pub = rospy.Publisher("gps/fix", NavSatFix, queue_size=10)

speed_act_left = 0  # Actual speed for left wheel in m/s
speed_act_right = 0  

# def setup():
#    rospy.Timer(rospy.Duration(LOOPTIME / 1000.0), loop)

# def loop(event):
#    global deman

def publish_speed(time):
   global speed_msg
   speed_msg.header.stamp = rospy.get_rostime()
   speed_msg.vector.x = speed_act_left
   speed_msg.vector.y = speed_act_right
   speed_msg.vector.z = time / 1000
   speed_pub.publish(speed_msg)

if __name__ == "__main__":

  rospy.spin()
