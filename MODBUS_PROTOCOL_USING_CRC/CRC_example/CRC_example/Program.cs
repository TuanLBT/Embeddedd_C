// See https://aka.ms/new-console-template for more information

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.XPath;

namespace CRC_Sample
{
    class Program
    {
        static void Main(string[] args)
        {
            byte slaveaddress = 1;
            byte functioncode = 3;
            ushort startaddress = 0; //ushort là kiểu biến dữ liệu tương đương 16bit
            ushort numberofpoints = 2;

            //build message (FC03)
            byte[] frame = new byte[8];
            frame[0] = slaveaddress;
            frame[1] = functioncode;
            frame[2] = (byte)(startaddress >> 8); //byte thứ ba của mảng frame chứa byte cao nhất của startaddress.
            frame[3] = (byte)startaddress; //byte thứ tư của mảng frame chứa byte thấp nhất của startaddress.
            frame[4] = (byte)(numberofpoints >> 8); //high byte of numberofpoint
            frame[5] = (byte)numberofpoints;        //low byte of numberofpoint
            //byte[] checkSum = CRC16(frame);
            ushort checkSum = CRC16(frame);
            //frame[6] = checkSum[0];
            //frame[7] = checkSum[1];

            //print
            /*
            foreach (var item in frame)
            {
                Console.WriteLine(string.Format("{0:X2}", item));
            }
            Console.ReadKey();*/
            Console.WriteLine(checkSum);
        }
        private static ushort CRC16(byte[] data)
        {
            byte[] checkSum = new byte[2];
            ushort reg_crc = 0XFFFF;
            for (int i = 0; i < data.Length - 2; i++)
            {
                reg_crc ^= data[i]; //reg_crc xor với byte thứ i trong data
                for(int j = 0; j < 8; j++) 
                {
                    if ((reg_crc&0x01) == 1) //trong lý thuyết, chỗ này là so sánh số ở đầu của byte, 0 hoặc 1 

                    {
                        reg_crc = (ushort)((reg_crc >> 1) ^ 0xA001); //XOR với đa thức sinh
                    }
                    else
                    {
                        reg_crc = (ushort)(reg_crc >> 1); //dịch phải 1 bit, XOR với 00000000 cũng ra tương tự
                    }
                }
            }
            //checkSum[1] = (byte)((reg_crc >> 8) & 0xFF); // tại sao lại phải and với FF mà ko lấy luôn giá trị sau khi dịch
            //vì sau khi dịch thì nó vẫn là 16bit, mà mình cần là 8bit (byte thấp) dùng để tính toán checksum, nên 
            // and với FF một cái nữa để lấy giá trị byte thấp (8bit) 


            //checkSum[0] = (byte)(reg_crc& 0xFF);
            /*
             *     1111111111111111    <-- giá trị 0xFFFF (16 bit)
                 & 0000000011111111    <-- giá trị 0xFF (đã được đưa lên 16 bit)
                 -----------------
                   0000000011111111    <-- kết quả phép AND bit

             */
            return reg_crc;
        }
        
    }
}