#!/usr/bin/env python

#Read data published on ROS and send Data to stm32f103c8t6

import rospy
import serial
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from geometry_msgs.msg import TwistStamped
import RPi.GPIO as GPIO

TwistMsg = Twist
ser = serial.Serial("/dev/ttyAMA0",115200) #open port


flag = 0

speed = 0 #RPM

def speed_read():
    
    ser.readln()

def subscriber():
    sub = rospy.Subscriber('bluetooh_pub', String, callback_function)

    rospy.spin()

def callback_function(message):
    #send data through uart
    global speed
    if(message.data == "f"):
        #rospy.loginfo(message)
        ser.write(("1"'d').encode())
        ser.write(("1"'e').encode())
        ser.write((str(speed)+'m').encode())
        ser.write((str(speed)+'n').encode())
        ser.flush()
    elif(message.data == "r"):
        ser.write(("1"'d').encode())
        ser.write(("2"'e').encode())
        ser.write((str(speed)+'m').encode())
        ser.write((str(speed)+'n').encode())
        ser.flush()
    elif(message.data == "l"):
        ser.write(("2"'d').encode())
        ser.write(("1"'e').encode())
        ser.write((str(speed)+'m').encode())
        ser.write((str(speed)+'n').encode())
        ser.flush()
    elif(message.data == "b"):
        ser.write(("2"'d').encode())
        ser.write(("2"'e').encode())
        ser.write((str(speed)+'m').encode())
        ser.write((str(speed)+'n').encode())
        ser.flush()
    elif(message.data == "s"):
        ser.write(("0"'d').encode())
        ser.write(("0"'e').encode())
        ser.write(("0"+'m').encode())
        ser.write(("0"+'n').encode())
        ser.flush()
    elif(message.data == "c"):
        ser.write(('r').encode())
        ser.flush()
    elif(message.data == "t"):
        ser.write(('s').encode())
        ser.flush()
    else:
        speed = message.data

if __name__ == "__main__":
    rospy.init_node("subcribe_node")
    subscriber()

    



