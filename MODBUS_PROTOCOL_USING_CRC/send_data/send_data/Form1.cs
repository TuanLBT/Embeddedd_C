using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports; //allow all instruction
using static System.Windows.Forms.VisualStyles.VisualStyleElement;


namespace send_data
{
    public partial class Form1 : Form
    {
        string dataout;
        string dataIn;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e) //double click on form, we get this
        {
            string[] ports = SerialPort.GetPortNames(); //lấy dữ liệu là cổng com hiện đang active gán cho array string
           cbbox_comport.Items.AddRange(ports); //đưa dữ liệu từ array string vào combobox
        }

        private void button_open_Click(object sender, EventArgs e)
        {
            //khi ấn nút thì các thông số của serialport sẽ cập nhập dựa trên các string từ combobox
            try
            {
                serialPort1.PortName = cbbox_comport.Text;
                serialPort1.Open();
                cbbox_baudrate.Enabled= true;
                cbbox_databit.Enabled= true;
                cbbox_stopbit.Enabled= true;
                cbbox_paritybit.Enabled= true;
                textBox_senddata.Enabled= true;
                texbox_receiver.Enabled= true;
                button_sendata.Enabled= true;
                button_readdata.Enabled= true;
                bt_on1.Enabled = true;
                bt_on2.Enabled = true;
                bt_on.Enabled = true;
                bt_on4.Enabled= true;
                bt_on5.Enabled= true;
                bt_on6.Enabled= true;
                bt_on7.Enabled= true;
                bt_on8.Enabled= true;

                bt_off1.Enabled= true;
                bt_off2.Enabled= true;
                bt_off3.Enabled= true;
                bt_off4.Enabled= true;
                bt_off5.Enabled= true;
                bt_off6.Enabled= true;
                bt_off7.Enabled= true;
                bt_off8.Enabled= true;
                progressBar1.Value= 100;
            }
            catch(Exception err)
            {
                MessageBox.Show(err.Message,"error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button_close_Click(object sender, EventArgs e)
        {
            if(serialPort1.IsOpen)
            {
                serialPort1.Close();
                cbbox_baudrate.Enabled= false;
                cbbox_databit.Enabled= false;
                cbbox_stopbit.Enabled= false;
                cbbox_paritybit.Enabled= false;
                textBox_senddata.Enabled= false;
                texbox_receiver.Enabled= false;
                button_readdata.Enabled = false;
                button_sendata.Enabled= false;
                bt_on1.Enabled = false;
                bt_on2.Enabled = false;
                bt_on.Enabled = false;
                bt_on4.Enabled = false;
                bt_on5.Enabled = false;
                bt_on6.Enabled = false;
                bt_on7.Enabled = false;
                bt_on8.Enabled = false;

                bt_off1.Enabled = false;
                bt_off2.Enabled = false;
                bt_off3.Enabled = false;
                bt_off4.Enabled = false;
                bt_off5.Enabled = false;
                bt_off6.Enabled = false;
                bt_off7.Enabled = false;
                bt_off8.Enabled = false;
                progressBar1.Value = 0;

            }
        }

        private void button_sendata_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                
                serialPort1.BaudRate = Convert.ToInt32(cbbox_baudrate.Text); //baudrate là giá trị int, nên phải convert từ string sang int
                serialPort1.DataBits = Convert.ToInt32(cbbox_databit.Text);
                //stopbit, parity bit thuộc enum, nên phải sử dụng cú pháp như dưới để chuyến string sang enum
                //parse(typeof(...), string)
                serialPort1.StopBits = (StopBits)Enum.Parse(typeof(StopBits), cbbox_stopbit.Text);
                serialPort1.Parity = (Parity)Enum.Parse(typeof(Parity), cbbox_paritybit.Text);
                dataout = textBox_senddata.Text;
                serialPort1.WriteLine(dataout);
            }
        }

        private void button_readdata_Click(object sender, EventArgs e)
        {
            //texbox_receiver.Text = serialPort1.ReadExisting();
        }

        private void serial_dataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            dataIn = serialPort1.ReadExisting();
            this.Invoke(new EventHandler(Showdata)); //this method show data serial into textbox
        }

        private void Showdata(object sender, EventArgs e)
        {
            texbox_receiver.Text += dataIn; //cho text dài ra được chứ ko chỉ hiện 1 kí tự
        }

        private void texbox_receiver_TextChanged(object sender, EventArgs e)
        {
            string data = serialPort1.ReadExisting();
            texbox_receiver.Invoke((MethodInvoker)delegate {
                texbox_receiver.AppendText(data);
            });
        }

        private void bt_on1_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E }; 
                byte[] controlbyte = {0x0C};
                byte[] databyte = {0x01};  
                byte[] endbyte = {0x0D};  

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on2_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x02 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x04 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on4_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x08 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on5_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x10 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];


                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);


                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on6_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x20 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on7_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x40 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_on8_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0C };
                byte[] databyte = { 0x80 };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_off1_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //1 frame cần send gồm 4 bytes
                byte[] startbyte = { 0x7E };
                byte[] controlbyte = { 0x0E };
                byte[] databyte = { 0xFE };
                byte[] endbyte = { 0x0D };

                byte[] bytesToSend = new byte[startbyte.Length + controlbyte.Length + databyte.Length + endbyte.Length];
                startbyte.CopyTo(bytesToSend, 0);
                controlbyte.CopyTo(bytesToSend, startbyte.Length);
                databyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length);
                endbyte.CopyTo(bytesToSend, startbyte.Length + controlbyte.Length + databyte.Length);
                serialPort1.Write(bytesToSend, 0, bytesToSend.Length);
            }
        }

        private void bt_off2_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("B");
        }

        private void bt_off3_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("C");
        }

        private void bt_off4_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("D");
        }

        private void bt_off5_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("E");
        }

        private void bt_off6_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("F");
        }

        private void bt_off7_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("G");
        }

        private void bt_off8_Click(object sender, EventArgs e)
        {
            /*
            byte[] flag_bytes = { 0x7E }; //đưa con trỏ về index thứ 0 của buffer data
            byte[] startbytes = { 0x0A };
            byte[] databytes = { 0, 0, 0, 0, 0, 0, 0, 0 };
            byte[] endbytes = { 0x0D };
            byte[] bytesToSend = new byte[flag_bytes.Length + startbytes.Length + databytes.Length + endbytes.Length];
            flag_bytes.CopyTo(bytesToSend, 0);
            startbytes.CopyTo(bytesToSend, flag_bytes.Length);
            databytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length);
            endbytes.CopyTo(bytesToSend, flag_bytes.Length + startbytes.Length + databytes.Length);
            serialPort1.Write(bytesToSend, 0, bytesToSend.Length);*/
            serialPort1.Write("H");
        }

        private void button1_Click(object sender, EventArgs e)
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
            byte[] checkSum = CRC16(frame);
            frame[6] = checkSum[0];
            frame[7] = checkSum[1];
            serialPort1.Write(frame, 0, frame.Length); 
        }
        private static byte[] CRC16(byte[] data)
        {
            byte[] checkSum = new byte[2];
            ushort reg_crc = 0XFFFF;
            for (int i = 0; i < data.Length - 2; i++)
            {
                reg_crc ^= data[i]; //reg_crc xor với byte thứ i trong data
                for (int j = 0; j < 8; j++)
                {
                    if ((reg_crc & 0x01) == 1) //trong lý thuyết, chỗ này là so sánh số ở đầu của byte, 0 hoặc 1 

                    {
                        reg_crc = (ushort)((reg_crc >> 1) ^ 0xA001); //XOR với đa thức sinh
                    }
                    else
                    {
                        reg_crc = (ushort)(reg_crc >> 1); //dịch phải 1 bit, XOR với 00000000 cũng ra tương tự
                    }
                }
            }
            checkSum[1] = (byte)((reg_crc >> 8) & 0xFF); // tại sao lại phải and với FF mà ko lấy luôn giá trị sau khi dịch
            //vì sau khi dịch thì nó vẫn là 16bit, mà mình cần là 8bit (byte thấp) dùng để tính toán checksum, nên 
            // and với FF một cái nữa để lấy giá trị byte thấp (8bit) 


            checkSum[0] = (byte)(reg_crc & 0xFF);
            /*
             *     1111111111111111    <-- giá trị 0xFFFF (16 bit)
                 & 0000000011111111    <-- giá trị 0xFF (đã được đưa lên 16 bit)
                 -----------------
                   0000000011111111    <-- kết quả phép AND bit

             */
            return checkSum;
        }

    }
}
