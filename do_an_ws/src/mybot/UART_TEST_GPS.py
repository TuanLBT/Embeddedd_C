
import serial

def main():
    # Khởi tạo đối tượng Serial để mở cổng serial
    gps_port = serial.Serial('/dev/ttyUSB2', 9600, timeout=1)

    # Kiểm tra xem cổng serial có mở thành công không
    if not gps_port.is_open:
        print("Failed to open GPS serial port")
        return

    print("GPS serial port opened successfully")

    try:
        # Đọc dữ liệu từ cổng serial và xuất ra màn hình
        while True:
            data = gps_port.read()  # Đọc một dòng dữ liệu từ cổng serial
            print("Received data:", data)
            
    except KeyboardInterrupt:
        print("Exiting program")

    # Đóng cổng serial khi không cần thiết nữa
    gps_port.close()

if __name__ == "__main__":
    main()
