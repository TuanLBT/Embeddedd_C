#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

def twist_callback(msg):
    linear_x = msg.linear.x
    linear_y = msg.linear.y
    linear_z = msg.linear.z
    angular_x = msg.angular.x
    angular_y = msg.angular.y
    angular_z = msg.angular.z

    # In ra các giá trị của twist message
    rospy.loginfo("Linear X: %f, Linear Y: %f, Linear Z: %f", linear_x, linear_y, linear_z)
    rospy.loginfo("Angular X: %f, Angular Y: %f, Angular Z: %f", angular_x, angular_y, angular_z)

def main():
    rospy.init_node('twist_subscriber')  # Khởi tạo node

    # Đăng ký một subscriber cho topic cmd_vel
    rospy.Subscriber('cmd_vel', Twist, twist_callback)

    rospy.spin()  # Không kết thúc chương trình cho đến khi node bị shutdown

if __name__ == '__main__':
    main()
