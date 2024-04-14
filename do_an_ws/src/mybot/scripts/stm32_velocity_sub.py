#!/usr/bin/env python

#node này đảm nhiệm nhan toc do tu stm32 va gui len topic /speed


#import cac thu vien can thiet
import rospy
from geometry_msgs.msg import Vector3Stamped
import struct


import serial

speed_msg = Vector3Stamped()
ser1 = serial.Serial("/dev/ttyUSB1",115200) #open port receive data from stm32


#task on threading
def task_serial_to_ros():
	# publisher để cong bo data van toc 2 banh tu stm32
	wheel = rospy.Publisher("speed", Vector3Stamped, queue_size=10)
	# Vòng lặp chính
	rate = rospy.Rate(1000)  # Tần số cập nhật 1Hz
	while not rospy.is_shutdown():
		if ser1.in_waiting > 0:
			speed = ser1.read(8) 
			#decode the struct recerve from stm32
			linear_x, linear_y = struct.unpack('ff',speed)
			publish_speed(100, linear_x, linear_y,wheel)
		rate.sleep()
		
#sub fucntion 
def publish_speed(time, linear_x, linear_y, wheel):
	global speed_msg
	speed_msg.header.stamp = rospy.Time.now()  # timestamp for odometry data
	speed_msg.vector.x = linear_x  # left wheel speed (in m/s)
	speed_msg.vector.y = linear_y  # right wheel speed (in m/s)
	speed_msg.vector.z = time / 1000  # looptime, should be the same as specified in LOOPTIME (in s)
	wheel.publish(speed_msg)
	#rospy.loginfo("Publishing odometry")
	
if __name__ == "__main__":
	try:
		# Khởi tạo node ROS
		rospy.init_node('stm32_node', anonymous=True)
		task_serial_to_ros()
		rospy.spin()
	except rospy.ROSInterruptException:
		pass
	