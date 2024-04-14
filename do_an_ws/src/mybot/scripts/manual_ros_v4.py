#!/usr/bin/env python

#node này đảm nhiệm manual (input signal from user) và xử lý dữ liệu từ topic /cmd_vel
#v2: su dung threading de loai bo delauy
#v3: sua lai code de nhin ro rang hon, sau nay de bao tri
#v4: them chuc nang auto nhan baundary de chay auto

#import cac thu vien can thiet
import rospy
from geometry_msgs.msg import Twist
import time
import threading 

import serial

from geometry_msgs.msg import Point32, Polygon, PoseStamped
from nav_msgs.msg import Odometry
from polygon_coverage_msgs.msg import PolygonWithHolesStamped
from polygon_coverage_msgs.srv import PolygonService, PlannerService
from geometry_msgs.msg import PointStamped

#open Serial port
bluetooh = serial.Serial("/dev/ttyUSB2",9600) #open port for bluetooh
ser = serial.Serial("/dev/ttyAMA0",115200) #open port send data to stm32
# ser1 = serial.Serial("/dev/ttyUSB1",115200) #open port receive data from stm32


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


# speed_msg = Vector3Stamped()

point_msg = PointStamped()


boundaryMode = False
holeMode = False
odomX = 0.0
odomY = 0.0
boundary = []
holes = []
hole = []



def handleDropPoint(boundaryMode,holeMode):
	global odomX, odomY
	if boundaryMode:
		boundary.append((odomX, odomY))
		print('Added '+str(odomX)+' '+str(odomY)+' point to boundary')
	elif holeMode:
		hole.append((odomX, odomY))
		print('Added '+str(odomX)+' '+str(odomY)+' point to temporary hole')

def poseCallback(odom_message,):
    global odomX, odomY, boundaryMode
    odomX = odom_message.pose.pose.position.x
    odomY = odom_message.pose.pose.position.y
	# if (boundaryMode):
	# 		point_msg.header.stamp = rospy.Time.now()  # Thời điểm ghi nhận
	# 		point_msg.header.frame_id = "map"  # Tên frame chứa điểm
	# 		point_msg.point.x = odomX  # Tọa độ x của điểm
	# 		point_msg.point.y = odomY  # Tọa độ y của điểm
	# 		#point_msg.point.z = 0.0  # Tọa độ z của điểm
	# 		pointPub.publish(point_msg)

def publishPolygonWithHoles(polygonPub):
	global boundaryMode, holeMode, boundary, holes, hole
	if len(boundary)>0:
		msgPolygon = PolygonWithHolesStamped()
		msgPolygon.header.frame_id='map'
		msgPolygon.header.stamp=rospy.Time.now()
		for x, y in boundary:
			point = Point32()
			point.x = float(x)
			point.y = float(y)
			point.z = 0.0
			msgPolygon.polygon.hull.points.append(point)
		if len(holes) > 0:
			print(str(len(holes))+' holes added')
			for i in range(len(holes)):
				polygon = Polygon()
				for j in range(len(holes[i])):
					x, y = holes[i][j]
					point = Point32()
					point.x = float(x)
					point.y = float(y)
					point.z = 0.01
					polygon.points.append(point)
				msgPolygon.polygon.holes.append(polygon)
		polygonPub.publish(msgPolygon)
		setPolygon = rospy.ServiceProxy('/coverage_planner/set_polygon', PolygonService)
		polygonOK = False
		try:
			polygonOK = setPolygon(msgPolygon)
		except rospy.ServiceException as exc:
			print("Polygon Service did not process request: " + str(exc))
		if polygonOK:
			print('Polygon set success, sending the message to planner')
			startPoint = msgPolygon.polygon.hull.points[0]
			startPose = PoseStamped()
			startPose.header.stamp=rospy.Time.now()
			startPose.header.frame_id='map'
			startPose.pose.position.x = startPoint.x
			startPose.pose.position.y = startPoint.y
			startPose.pose.position.z = 0.0
			startPose.pose.orientation.x = 0.0
			startPose.pose.orientation.y = 0.0
			startPose.pose.orientation.z = 0.0
			startPose.pose.orientation.w = 0.0
			endPose = startPose
			planPolygon = rospy.ServiceProxy('/coverage_planner/plan_path', PlannerService)
			planOK = False
			try:
				resp= planPolygon(startPose, endPose)
				planOK = resp.success
			except rospy.ServiceException as exc:
				print("Polygon Planner Service did not process request: " + str(exc))

			if planOK:
				print("Plan generated successfully")
				print(resp.sampled_plan)
			rospy.signal_shutdown("Plan generated successfully")
		boundaryMode = False
		holeMode = False
		boundary.clear()
		holes.clear()
		hole.clear()

#ham ngat trong ROS
def stm32_vel_values(cmdVel):
	global velLeftWheel, velRightWheel, pwmLeftReq, pwmRightReq, lastCmdVelReceived

	wheel_base = 0.3
	#Record timestamp of last velocity command received
	lastCmdVelReceived = time.time()

	
	# Calculate the vel value given by the /cmd_vel
	pwmLeftReq = cmdVel.linear.x 
	pwmRightReq = cmdVel.linear.x 
	linear_x = cmdVel.linear.x 
	angular_z = cmdVel.angular.z
	convertion = 60 / 0.13
	speed_max = 50
	speed_cmd = 0

	#rospy.loginfo("cmdvel x received: " + str(cmdVel.linear.x) + "-cmd spin value: " + str(cmdVel.angular.z))
 
	# Tính tốc độ của bánh trái và bánh phải dựa trên tốc độ tuyến tính và góc quay
	# wheel_left_speed = (linear_x - angular_z * wheel_base / 2) * convertion
	# wheel_right_speed = (linear_x + angular_z * wheel_base / 2) * convertion
	
	# # Giới hạn tốc độ tối đa và tối thiểu
	# wheel_left_speed_limit = max(min(wheel_left_speed, max_speed), -max_speed)
	# wheel_right_speed_limit = max(min(wheel_right_speed, max_speed), -max_speed)
	
	change_vel =  min(max(convertion* cmdVel.linear.x, 50), 50)

	if (cmdVel.angular.z != 0.0):
		#turn left 
		if cmdVel.angular.z > 0.35:
			pwmLeftreq = SPEED_TURN
			pwmRightreq = SPEED_TURN
			ser.write(("2"'d').encode())
			ser.write(("1"'e').encode())
			ser.write((str(pwmLeftreq)+'m').encode())
			ser.write((str(pwmRightreq)+'n').encode())
			ser.flush()
		elif cmdVel.angular.z < 0.35 and cmdVel.angular.z > 0.0:
			pwmLeftreq = SPEED_TURN
			pwmRightreq = SPEED_TURN
			ser.write(("1"'d').encode())
			ser.write(("1"'e').encode())
			ser.write((str(50)+'m').encode())
			ser.write((str(0)+'n').encode())
			ser.flush()
		#turn right
		elif cmdVel.angular.z < - 0.35:
			pwmLeftreq = SPEED_TURN
			pwmRightreq = SPEED_TURN
			ser.write(("1"'d').encode())
			ser.write(("2"'e').encode())
			ser.write((str(pwmLeftreq)+'m').encode())
			ser.write((str(pwmRightreq)+'n').encode())
			ser.flush()
		if cmdVel.angular.z > -0.35 and cmdVel.angular.z < 0.0:
			pwmLeftreq = SPEED_TURN
			pwmRightreq = SPEED_TURN
			ser.write(("1"'d').encode())
			ser.write(("1"'e').encode())
			ser.write((str(0)+'m').encode())
			ser.write((str(50)+'n').encode())
			ser.flush()

	#go straight
	elif(cmdVel.linear.x > 0.0):
		pwmLeftreq = change_vel
		pwmRightreq = change_vel
		ser.write(("1"'d').encode())
		ser.write(("1"'e').encode())
		ser.write((str(pwmLeftreq)+'m').encode())
		ser.write((str(pwmRightreq)+'n').encode())
		ser.flush()
	else:
		ser.write(("0"'d').encode())
		ser.write(("0"'e').encode())
		ser.write((str(0)+'m').encode())
		ser.write((str(0)+'n').encode())
		ser.flush()


def main_process():
	global speed_1, speed_2, cmdVel, boundaryMode


	# Khởi tạo node ROS
	rospy.init_node('manual_node', anonymous=True)

	# Subscriber để nhận du lieu dieu khien tu topic /cmd_vel
	rospy.Subscriber("cmd_vel", Twist, stm32_vel_values, queue_size=2)

	
	#punlish polygon baundary to topic /polygon
	polygonPub  = rospy.Publisher('polygon', PolygonWithHolesStamped, queue_size=1)

	#punlish polygon baundary to topic /polygon
	pointPub  = rospy.Publisher('clicked_point', PointStamped, queue_size=1)

	#sub de robot biet vi tri o dau
	rospy.Subscriber("odometry/filtered", Odometry, poseCallback, queue_size= 2)

	
    # Tạo và bắt đầu các luồng cho việc đọc dữ liệu từ các cổng serial
	# stm32_thread = threading.Thread(target=task_stm32_manual, args=(bluetooh,ser, polygonPub))
	# # serial_to_ros_thread = threading.Thread(target=task_serial_to_ros, args=(ser1))
	# stm32_thread.start()
	# serial_to_ros_thread.start()
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
				# elif(string_val == "a"):
				# 	boundaryMode = True
				# 	holeMode = False
				# 	print('Boundary mode activated')
				# elif(string_val == "h"):
				# 	if len(hole) > 0 and holeMode:
				# 		holes.append(hole.copy())
				# 		hole.clear()
				# 		holeMode = False
				# 		boundaryMode = False
				# 		print('Temporary hole added and Holes mode deactivated')
				# 	else:
				# 		boundaryMode = False
				# 		holeMode = True
				# 		print('Holes mode activated')
				# elif(string_val == "y"):
				# 	handleDropPoint(boundaryMode,holeMode)
				elif(string_val == "u"):
					boundaryMode = False
					holeMode = False
					boundary.clear()
					holes.clear()
					hole.clear()
					print('Cleared all boundary and holes data')
				elif (string_val == "p"):
					#publishPolygonWithHoles(polygonPub)
					point_msg.header.stamp = rospy.Time.now()  # Thời điểm ghi nhận
					point_msg.header.frame_id = "map"  # Tên frame chứa điểm
					point_msg.point.x = odomX  # Tọa độ x của điểm
					point_msg.point.y = odomY  # Tọa độ y của điểm
					#point_msg.point.z = 0.0  # Tọa độ z của điểm
					pointPub.publish(point_msg)
				else:
					speed_1 = str(int_val)
					speed_2 = str(int_val)

		

		rate.sleep()
	
	
	
    # Chờ cho đến khi tất cả các luồng kết thúc
	# stm32_thread.join()
	# serial_to_ros_thread.join()
	
	#Close ports if node is shutdown
	bluetooh.close()
	ser.close()

	# rospy.spin()



if __name__ == "__main__":
	try:
		main_process()
	except rospy.ROSInterruptException:
		pass