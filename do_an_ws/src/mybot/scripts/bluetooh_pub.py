#!/usr/bin/env python

#Read data from bluetooh sent from phone and publish on ROS


import rospy
from std_msgs.msg import String
from std_msgs.msg import Byte 
import serial
import RPi.GPIO as GPIO
from time import sleep


bluetooh = serial.Serial("/dev/ttyUSB0",9600) #open port

def publisher():
    pub = rospy.Publisher('bluetooh_pub', String, queue_size = 10)
    rate = rospy.Rate(1)
    msg_to_publish1= String()
    msg_to_publish2 = String() #Byte()
    counter = 0

    while not rospy.is_shutdown():
        data = bluetooh.read()
        int_val = int.from_bytes(data, "big")
        string_val = (data).decode('utf-8')
        
        msg_to_publish1.data = string_val
        msg_to_publish2.data = str(int_val)
        
        if(msg_to_publish1.data == "f" or msg_to_publish1.data == "b" or msg_to_publish1.data == "l" or msg_to_publish1.data == "r" or msg_to_publish1.data == "s" or msg_to_publish1.data == "c" or msg_to_publish1.data == "t"):
            pub.publish(msg_to_publish1.data)
            rospy.loginfo(msg_to_publish1.data)
        else:
            pub.publish(msg_to_publish2.data)
            rospy.loginfo(msg_to_publish2.data)

        rate.sleep()

if __name__ == "__main__":
    rospy.init_node("publish_node")
    publisher()
