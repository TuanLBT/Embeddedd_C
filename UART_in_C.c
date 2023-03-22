#include <stdio.h>
#include <fcntl.h> //Thư viện này cho phép người dùng tạo ra các file, mở, đóng, xóa, đổi tên, sao chép file, cũng như xác định trạng thái file, quyền truy cập và các thuộc tính khác.

#include <termios.h>
#include <unistd.h>

int main() {
    int uart0_filestream = -1;
    
    // Mở kết nối UART
    uart0_filestream = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY); //hàm open của thư viên fcntl.h
    /*
    "/dev/ttyS0": đây là đường dẫn của thiết bị cần mở. Trong trường hợp này, đây là thiết bị serial port đầu tiên trên hệ thống Linux, có thể được sử dụng để truyền dữ liệu giữa máy tính và các thiết bị ngoại vi như Arduino hoặc Raspberry Pi.

O_RDWR: đây là một cờ để mở file ở chế độ đọc/ghi.

O_NOCTTY: đây là một cờ để bỏ qua việc thiết lập thiết bị làm thiết bị điều khiển của tiến trình. Nó sẽ đảm bảo rằng thiết bị không bị "cố định" bởi tiến trình và cho phép truy cập trực tiếp vào thiết bị.

O_NDELAY: đây là một cờ để mở file ở chế độ không đợi tín hiệu (non-blocking mode), tức là nó sẽ trả về ngay lập tức mà không đợi cho đến khi có tín hiệu đầu vào được nhận từ thiết bị.
    */
    if (uart0_filestream == -1) {
        printf("Không thể mở kết nối UART.\n");
        return -1;
    }
    
    // Cấu hình tốc độ baud, độ dài bit, parity và stop bit
    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);
    
    // Gửi dữ liệu đi
    unsigned char tx_buffer[20] = "Hello, world!";
    if (uart0_filestream != -1) {
        int count = write(uart0_filestream, &tx_buffer, sizeof(tx_buffer));
        if (count < 0) {
            printf("Lỗi khi gửi dữ liệu.\n");
            return -1;
        }
    }
    
    // Đọc dữ liệu đến
    unsigned char rx_buffer[256];
    if (uart0_filestream != -1) {
        int rx_length = read(uart0_filestream, (void*)rx_buffer, 255);
        if (rx_length < 0) {
            printf("Không thể đọc dữ liệu.\n");
            return -1;
        } else if (rx_length == 0) {
            printf("Không có dữ liệu nào đến.\n");
            return -1;
        } else {
            rx_buffer[rx_length] = '\0';
            printf("%i bytes dữ liệu đến: %s\n", rx_length, rx_buffer);
        }
    }
    
    // Đóng kết nối UART
    close(uart0_filestream);
    
    return 0;
}
