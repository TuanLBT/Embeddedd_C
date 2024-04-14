import serial
import struct

# Thiết lập cổng UART
ser = serial.Serial('/dev/ttyUSB1', 115200)  # Thay đổi '/dev/ttyUSB0' thành cổng UART thực tế của bạn

try: 
	while True:
		# Đọc dữ liệu từ UART
		data = ser.read(8)  # Đọc 24 byte (kích thước của struct TwistMessage)

		# Giải mã dữ liệu nhận được thành cấu trúc TwistMessage
		linear_x, linear_y = struct.unpack('ff', data)

		# In ra các giá trị của cấu trúc TwistMessage
		print("Linear X:", linear_x)
		print("Linear Y:", linear_y)
except KeyboardInterrupt:
	    # Dừng chương trình nếu nhận phím tắt (Ctrl+C)
	pass

finally:
	#dong cong UART
	ser.close()
	
