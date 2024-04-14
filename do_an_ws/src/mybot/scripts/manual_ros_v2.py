#!/usr/bin/env python

#node này đảm nhiệm manual (input signal from user) và xử lý dữ liệu từ topic /cmd_vel
#v2: su dung threading de loai bo delauy


#import cac thu vien can thiet
import rospy
from geometry_msgs.msg import Twist
import RPi.GPIO as GPIO
import time
from geometry_msgs.msg import Vector3Stamped
import struct
import threading 

from std_msgs.msg import String
from std_msgs.msg import Byte 
import serial

from time import sleep


 #open Serial port
bluetooh = serial.Serial("/dev/ttyUSB0",9600) #open port
ser = serial.Serial("/dev/ttyAMA0",115200) #open port

speed_1 = 0 #RPM motor 1
speed_2 = 0 #RPM motor 2

dir_1 = 0 #dir of motor 1
dir_2 = 0 #dir of motor 2

cmdVel = 0 #value form Twist message

# Record the time that the last velocity command was received
lastCmdVelReceived = 0

#Set linear velocity and PWM variable values for each wheel
velLeftWheel = 0
velRightWheel = 0
pwmLeftReq = 0
pwmRightReq = 0

SPEED_TURN = 50


speed_msg = Vector3Stamped()

#task on threading
def task_serial_to_ros(ser, wheel):
	# Vòng lặp chính
	rate = rospy.Rate(100)  # Tần số cập nhật 1Hz
	while not rospy.is_shutdown():
		if ser.in_waiting > 0:
			speed = ser.read(8) 
			#decode the struct recerve from stm32
			linear_x, linear_y = struct.unpack('ff',speed)
			publish_speed(1000, linear_x, linear_y,wheel)
		rate.sleep()


def task_stm32_manual(bluetooh,ser):
	global speed_1, speed_2, cmdVel
	# Vòng lặp chính
	rate = rospy.Rate(1000)  # Tần số cập nhật 1Hz
	while not rospy.is_shutdown():

		if bluetooh.in_waiting > 0:  # Kiểm tra nếu có dữ liệu đang chờ trên cổng USB0
				data = bluetooh.read(bluetooh.in_waiting)  # Đọc dữ liệu từ cổng USB0
				string_val = (data).decode('utf-8')		#data to string 
				int_val = int.from_bytes(data, "big")    # data to interger
				#handle manual signal and send signal to STM32
				if(string_val == "f"):
					#rospy.loginfo(message)
					ser.write(("1"'d').encode())
					ser.write(("1"'e').encode())
					ser.write((str(speed_1)+'m').encode())
					ser.write((str(speed_2)+'n').encode())
					ser.flush()
				elif(string_val == "r"):
					ser.write(("1"'d').encode())
					ser.write(("2"'e').encode())
					ser.write((str(speed_1)+'m').encode())
					ser.write((str(speed_2)+'n').encode())
					ser.flush()
				elif(string_val == "l"):
					ser.write(("2"'d').encode())
					ser.write(("1"'e').encode())
					ser.write((str(speed_1)+'m').encode())
					ser.write((str(speed_2)+'n').encode())
					ser.flush()
				elif(string_val == "b"):
					ser.write(("2"'d').encode())
					ser.write(("2"'e').encode())
					ser.write((str(speed_1)+'m').encode())
					ser.write((str(speed_2)+'n').encode())
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
					
					speed_1 = str(int_val)
					speed_2 = str(int_val)

		rate.sleep()
#sub fucntion 
def publish_speed(time, linear_x, linear_y, wheel):
	global speed_msg
	speed_msg.header.stamp = rospy.Time.now()  # timestamp for odometry data
	speed_msg.vector.x = linear_x  # left wheel speed (in m/s)
	speed_msg.vector.y = linear_y  # right wheel speed (in m/s)
	speed_msg.vector.z = time / 1000  # looptime, should be the same as specified in LOOPTIME (in s)
	wheel.publish(speed_msg)
    # rospy.loginfo("Publishing odometry")

#ham ngat trong ROS
def stm32_vel_values(cmdVel):
	global velLeftWheel, velRightWheel, pwmLeftReq, pwmRightReq, lastCmdVelReceived
	#Record timestamp of last velocity command received
	lastCmdVelReceived = time.time()
	
	# Calculate the vel value given by the /cmd_vel
	pwmLeftReq = cmdVel.linear.x 
	pwmRightReq = cmdVel.linear.x 

	#check if we need to turn
	if (cmdVel.angular.z != 0.0):
		#turn left 
		if cmdVel.angular.z > 0.0:
			pwmLeftreq = SPEED_TURN
			pwmRightreq = SPEED_TURN
			ser.write(("2"'d').encode())
			ser.write(("1"'e').encode())
			ser.write((str(pwmLeftreq)+'m').encode())
			ser.write((str(pwmRightreq)+'n').encode())
			ser.flush()
		#turn right
		else:
			pwmLeftreq = SPEED_TURN
			pwmRightreq = SPEED_TURN
			ser.write(("1"'d').encode())
			ser.write(("2"'e').encode())
			ser.write((str(pwmLeftreq)+'m').encode())
			ser.write((str(pwmRightreq)+'n').encode())
			ser.flush()

	#go straight
	else:
		pwmLeftreq = SPEED_TURN
		pwmRightreq = SPEED_TURN
		ser.write(("1"'d').encode())
		ser.write(("1"'e').encode())
		ser.write((str(pwmLeftreq)+'m').encode())
		ser.write((str(pwmRightreq)+'n').encode())
		ser.flush()


def main_process():
	global speed_1, speed_2, cmdVel


	# Khởi tạo node ROS
	rospy.init_node('manual_node', anonymous=True)

	# Subscriber để nhận du lieu dieu khien tu topic /cmd_vel
	rospy.Subscriber("cmd_vel", Twist, stm32_vel_values)

	# publisher để cong bo data van toc 2 banh tu stm32
	wheel = rospy.Publisher("speed", Vector3Stamped, queue_size=10)

    # Tạo và bắt đầu các luồng cho việc đọc dữ liệu từ các cổng serial
	stm32_thread = threading.Thread(target=task_stm32_manual, args=(bluetooh,ser))
	serial_to_ros_thread = threading.Thread(target=task_serial_to_ros, args=(ser, wheel))
	stm32_thread.start()
	serial_to_ros_thread.start()
	
    # Chờ cho đến khi tất cả các luồng kết thúc
	stm32_thread.join()
	serial_to_ros_thread.join()
	
	#Close ports if node is shutdown
	# bluetooh.close()
	# ser.close()

	


if __name__ == "__main__":
	try:
		main_process()
		rospy.spin()
	except rospy.ROSInterruptException:
		pass