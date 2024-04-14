#!/usr/bin/env python

#Read data from bluetooh sent from phone and
#send it directly to STM32

import rospy
from std_msgs.msg import String
from std_msgs.msg import Byte 
import serial
import RPi.GPIO as GPIO
from time import sleep

bluetooh = serial.Serial("/dev/ttyUSB0",9600) #open port

ser = serial.Serial("/dev/ttyAMA0",115200) #open port


speed = 0 #RPM

def manual():
	global speed
	try:
		while True:
			if bluetooh.in_waiting > 0:  # Kiểm tra nếu có dữ liệu đang chờ trên cổng USB0
				data = bluetooh.read(bluetooh.in_waiting)  # Đọc dữ liệu từ cổng USB0
				int_val = int.from_bytes(data, "big")
				string_val = (data).decode('utf-8')
				
				if(string_val == "f"):
					#rospy.loginfo(message)
					ser.write(("1"'d').encode())
					ser.write(("1"'e').encode())
					ser.write((str(speed)+'m').encode())
					ser.write((str(speed)+'n').encode())
					ser.flush()
				elif(string_val == "r"):
					ser.write(("1"'d').encode())
					ser.write(("2"'e').encode())
					ser.write((str(speed)+'m').encode())
					ser.write((str(speed)+'n').encode())
					ser.flush()
				elif(string_val == "l"):
					ser.write(("2"'d').encode())
					ser.write(("1"'e').encode())
					ser.write((str(speed)+'m').encode())
					ser.write((str(speed)+'n').encode())
					ser.flush()
				elif(string_val == "b"):
					ser.write(("2"'d').encode())
					ser.write(("2"'e').encode())
					ser.write((str(speed)+'m').encode())
					ser.write((str(speed)+'n').encode())
					ser.flush()
				elif(string_val == "s"):
					ser.write(("0"'d').encode())
					ser.write(("0"'e').encode())
					ser.write(("0"+'m').encode())
					ser.write(("0"+'n').encode())
					ser.flush()
				elif(string_val == "c"):
					ser.write(('r').encode())
					ser.flush()
				elif(string_val == "t"):
					ser.write(('s').encode())
					ser.flush()
				else:
					speed = str(int_val)
	except:
		pass
	finally:
		pass
#def publisher():
#	pub = rospy.Publisher('bluetooh_pub', String, queue_size = 10)
#	rate = rospy.Rate(1)
#	while not rospy.is_shutdown():
#		rate.sleep()

if __name__ == "__main__":
    #rospy.init_node("custome_node")
    manual()
