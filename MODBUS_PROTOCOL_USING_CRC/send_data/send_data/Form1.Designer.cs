namespace send_data
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.button_sendata = new System.Windows.Forms.Button();
            this.button_close = new System.Windows.Forms.Button();
            this.button_open = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cbbox_paritybit = new System.Windows.Forms.ComboBox();
            this.cbbox_stopbit = new System.Windows.Forms.ComboBox();
            this.cbbox_databit = new System.Windows.Forms.ComboBox();
            this.cbbox_baudrate = new System.Windows.Forms.ComboBox();
            this.cbbox_comport = new System.Windows.Forms.ComboBox();
            this.textBox_senddata = new System.Windows.Forms.TextBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.texbox_receiver = new System.Windows.Forms.TextBox();
            this.button_readdata = new System.Windows.Forms.Button();
            this.bt_on1 = new System.Windows.Forms.Button();
            this.bt_on2 = new System.Windows.Forms.Button();
            this.bt_on = new System.Windows.Forms.Button();
            this.bt_on4 = new System.Windows.Forms.Button();
            this.bt_on8 = new System.Windows.Forms.Button();
            this.bt_on7 = new System.Windows.Forms.Button();
            this.bt_on6 = new System.Windows.Forms.Button();
            this.bt_on5 = new System.Windows.Forms.Button();
            this.bt_off8 = new System.Windows.Forms.Button();
            this.bt_off7 = new System.Windows.Forms.Button();
            this.bt_off6 = new System.Windows.Forms.Button();
            this.bt_off5 = new System.Windows.Forms.Button();
            this.bt_off4 = new System.Windows.Forms.Button();
            this.bt_off3 = new System.Windows.Forms.Button();
            this.bt_off2 = new System.Windows.Forms.Button();
            this.bt_off1 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.progressBar1);
            this.groupBox1.Controls.Add(this.button_sendata);
            this.groupBox1.Controls.Add(this.button_close);
            this.groupBox1.Controls.Add(this.button_open);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.cbbox_paritybit);
            this.groupBox1.Controls.Add(this.cbbox_stopbit);
            this.groupBox1.Controls.Add(this.cbbox_databit);
            this.groupBox1.Controls.Add(this.cbbox_baudrate);
            this.groupBox1.Controls.Add(this.cbbox_comport);
            this.groupBox1.Location = new System.Drawing.Point(12, 23);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(397, 348);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Send Data";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(69, 318);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(197, 23);
            this.progressBar1.TabIndex = 13;
            // 
            // button_sendata
            // 
            this.button_sendata.Enabled = false;
            this.button_sendata.Location = new System.Drawing.Point(284, 262);
            this.button_sendata.Name = "button_sendata";
            this.button_sendata.Size = new System.Drawing.Size(109, 80);
            this.button_sendata.TabIndex = 12;
            this.button_sendata.Text = "Send Data";
            this.button_sendata.UseVisualStyleBackColor = true;
            this.button_sendata.Click += new System.EventHandler(this.button_sendata_Click);
            // 
            // button_close
            // 
            this.button_close.Location = new System.Drawing.Point(179, 262);
            this.button_close.Name = "button_close";
            this.button_close.Size = new System.Drawing.Size(87, 46);
            this.button_close.TabIndex = 11;
            this.button_close.Text = "close";
            this.button_close.UseVisualStyleBackColor = true;
            this.button_close.Click += new System.EventHandler(this.button_close_Click);
            // 
            // button_open
            // 
            this.button_open.Location = new System.Drawing.Point(69, 262);
            this.button_open.Name = "button_open";
            this.button_open.Size = new System.Drawing.Size(87, 46);
            this.button_open.TabIndex = 10;
            this.button_open.Text = "open";
            this.button_open.UseVisualStyleBackColor = true;
            this.button_open.Click += new System.EventHandler(this.button_open_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(66, 210);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(59, 16);
            this.label5.TabIndex = 9;
            this.label5.Text = "Parity Bit";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(66, 167);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(49, 16);
            this.label4.TabIndex = 8;
            this.label4.Text = "Stopbit";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(66, 123);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(50, 16);
            this.label3.TabIndex = 7;
            this.label3.Text = "Databit";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(66, 80);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 16);
            this.label2.TabIndex = 6;
            this.label2.Text = "Baud Rate";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(66, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 16);
            this.label1.TabIndex = 5;
            this.label1.Text = "Com port";
            // 
            // cbbox_paritybit
            // 
            this.cbbox_paritybit.Enabled = false;
            this.cbbox_paritybit.FormattingEnabled = true;
            this.cbbox_paritybit.Items.AddRange(new object[] {
            "None",
            "Odd",
            "Even"});
            this.cbbox_paritybit.Location = new System.Drawing.Point(148, 210);
            this.cbbox_paritybit.Name = "cbbox_paritybit";
            this.cbbox_paritybit.Size = new System.Drawing.Size(179, 24);
            this.cbbox_paritybit.TabIndex = 4;
            this.cbbox_paritybit.Text = "None";
            // 
            // cbbox_stopbit
            // 
            this.cbbox_stopbit.Enabled = false;
            this.cbbox_stopbit.FormattingEnabled = true;
            this.cbbox_stopbit.Items.AddRange(new object[] {
            "One",
            "Two"});
            this.cbbox_stopbit.Location = new System.Drawing.Point(148, 167);
            this.cbbox_stopbit.Name = "cbbox_stopbit";
            this.cbbox_stopbit.Size = new System.Drawing.Size(179, 24);
            this.cbbox_stopbit.TabIndex = 3;
            this.cbbox_stopbit.Text = "One";
            // 
            // cbbox_databit
            // 
            this.cbbox_databit.Enabled = false;
            this.cbbox_databit.FormattingEnabled = true;
            this.cbbox_databit.Items.AddRange(new object[] {
            "6",
            "7",
            "8"});
            this.cbbox_databit.Location = new System.Drawing.Point(148, 123);
            this.cbbox_databit.Name = "cbbox_databit";
            this.cbbox_databit.Size = new System.Drawing.Size(179, 24);
            this.cbbox_databit.TabIndex = 2;
            this.cbbox_databit.Text = "8";
            // 
            // cbbox_baudrate
            // 
            this.cbbox_baudrate.Enabled = false;
            this.cbbox_baudrate.FormattingEnabled = true;
            this.cbbox_baudrate.Items.AddRange(new object[] {
            "600",
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200",
            "38400",
            "56000",
            "57600",
            "115200"});
            this.cbbox_baudrate.Location = new System.Drawing.Point(148, 80);
            this.cbbox_baudrate.Name = "cbbox_baudrate";
            this.cbbox_baudrate.Size = new System.Drawing.Size(179, 24);
            this.cbbox_baudrate.TabIndex = 1;
            this.cbbox_baudrate.Text = "9600";
            // 
            // cbbox_comport
            // 
            this.cbbox_comport.FormattingEnabled = true;
            this.cbbox_comport.Location = new System.Drawing.Point(148, 36);
            this.cbbox_comport.Name = "cbbox_comport";
            this.cbbox_comport.Size = new System.Drawing.Size(179, 24);
            this.cbbox_comport.TabIndex = 0;
            // 
            // textBox_senddata
            // 
            this.textBox_senddata.Enabled = false;
            this.textBox_senddata.Location = new System.Drawing.Point(12, 393);
            this.textBox_senddata.Multiline = true;
            this.textBox_senddata.Name = "textBox_senddata";
            this.textBox_senddata.Size = new System.Drawing.Size(156, 50);
            this.textBox_senddata.TabIndex = 1;
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serial_dataReceived);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(9, 374);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(69, 16);
            this.label6.TabIndex = 2;
            this.label6.Text = "Data send";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(171, 374);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(88, 16);
            this.label7.TabIndex = 4;
            this.label7.Text = "Data receiver";
            // 
            // texbox_receiver
            // 
            this.texbox_receiver.Enabled = false;
            this.texbox_receiver.Location = new System.Drawing.Point(174, 393);
            this.texbox_receiver.Multiline = true;
            this.texbox_receiver.Name = "texbox_receiver";
            this.texbox_receiver.ReadOnly = true;
            this.texbox_receiver.Size = new System.Drawing.Size(165, 52);
            this.texbox_receiver.TabIndex = 3;
            this.texbox_receiver.TextChanged += new System.EventHandler(this.texbox_receiver_TextChanged);
            // 
            // button_readdata
            // 
            this.button_readdata.Location = new System.Drawing.Point(345, 389);
            this.button_readdata.Name = "button_readdata";
            this.button_readdata.Size = new System.Drawing.Size(64, 49);
            this.button_readdata.TabIndex = 5;
            this.button_readdata.Text = "Read Data";
            this.button_readdata.UseVisualStyleBackColor = true;
            this.button_readdata.Click += new System.EventHandler(this.button_readdata_Click);
            // 
            // bt_on1
            // 
            this.bt_on1.Enabled = false;
            this.bt_on1.Location = new System.Drawing.Point(415, 23);
            this.bt_on1.Name = "bt_on1";
            this.bt_on1.Size = new System.Drawing.Size(91, 40);
            this.bt_on1.TabIndex = 6;
            this.bt_on1.Text = "ON1";
            this.bt_on1.UseVisualStyleBackColor = true;
            this.bt_on1.Click += new System.EventHandler(this.bt_on1_Click);
            // 
            // bt_on2
            // 
            this.bt_on2.Enabled = false;
            this.bt_on2.Location = new System.Drawing.Point(512, 23);
            this.bt_on2.Name = "bt_on2";
            this.bt_on2.Size = new System.Drawing.Size(91, 40);
            this.bt_on2.TabIndex = 7;
            this.bt_on2.Text = "ON2";
            this.bt_on2.UseVisualStyleBackColor = true;
            this.bt_on2.Click += new System.EventHandler(this.bt_on2_Click);
            // 
            // bt_on
            // 
            this.bt_on.Enabled = false;
            this.bt_on.Location = new System.Drawing.Point(609, 23);
            this.bt_on.Name = "bt_on";
            this.bt_on.Size = new System.Drawing.Size(91, 40);
            this.bt_on.TabIndex = 8;
            this.bt_on.Text = "ON3";
            this.bt_on.UseVisualStyleBackColor = true;
            this.bt_on.Click += new System.EventHandler(this.bt_on_Click);
            // 
            // bt_on4
            // 
            this.bt_on4.Enabled = false;
            this.bt_on4.Location = new System.Drawing.Point(706, 23);
            this.bt_on4.Name = "bt_on4";
            this.bt_on4.Size = new System.Drawing.Size(91, 40);
            this.bt_on4.TabIndex = 9;
            this.bt_on4.Text = "ON4";
            this.bt_on4.UseVisualStyleBackColor = true;
            this.bt_on4.Click += new System.EventHandler(this.bt_on4_Click);
            // 
            // bt_on8
            // 
            this.bt_on8.Enabled = false;
            this.bt_on8.Location = new System.Drawing.Point(706, 69);
            this.bt_on8.Name = "bt_on8";
            this.bt_on8.Size = new System.Drawing.Size(91, 40);
            this.bt_on8.TabIndex = 13;
            this.bt_on8.Text = "ON8";
            this.bt_on8.UseVisualStyleBackColor = true;
            this.bt_on8.Click += new System.EventHandler(this.bt_on8_Click);
            // 
            // bt_on7
            // 
            this.bt_on7.Enabled = false;
            this.bt_on7.Location = new System.Drawing.Point(609, 69);
            this.bt_on7.Name = "bt_on7";
            this.bt_on7.Size = new System.Drawing.Size(91, 40);
            this.bt_on7.TabIndex = 12;
            this.bt_on7.Text = "ON7";
            this.bt_on7.UseVisualStyleBackColor = true;
            this.bt_on7.Click += new System.EventHandler(this.bt_on7_Click);
            // 
            // bt_on6
            // 
            this.bt_on6.Enabled = false;
            this.bt_on6.Location = new System.Drawing.Point(512, 69);
            this.bt_on6.Name = "bt_on6";
            this.bt_on6.Size = new System.Drawing.Size(91, 40);
            this.bt_on6.TabIndex = 11;
            this.bt_on6.Text = "ON6";
            this.bt_on6.UseVisualStyleBackColor = true;
            this.bt_on6.Click += new System.EventHandler(this.bt_on6_Click);
            // 
            // bt_on5
            // 
            this.bt_on5.Enabled = false;
            this.bt_on5.Location = new System.Drawing.Point(415, 69);
            this.bt_on5.Name = "bt_on5";
            this.bt_on5.Size = new System.Drawing.Size(91, 40);
            this.bt_on5.TabIndex = 10;
            this.bt_on5.Text = "ON5";
            this.bt_on5.UseVisualStyleBackColor = true;
            this.bt_on5.Click += new System.EventHandler(this.bt_on5_Click);
            // 
            // bt_off8
            // 
            this.bt_off8.Enabled = false;
            this.bt_off8.Location = new System.Drawing.Point(706, 192);
            this.bt_off8.Name = "bt_off8";
            this.bt_off8.Size = new System.Drawing.Size(91, 40);
            this.bt_off8.TabIndex = 21;
            this.bt_off8.Text = "OFF8";
            this.bt_off8.UseVisualStyleBackColor = true;
            this.bt_off8.Click += new System.EventHandler(this.bt_off8_Click);
            // 
            // bt_off7
            // 
            this.bt_off7.Enabled = false;
            this.bt_off7.Location = new System.Drawing.Point(609, 192);
            this.bt_off7.Name = "bt_off7";
            this.bt_off7.Size = new System.Drawing.Size(91, 40);
            this.bt_off7.TabIndex = 20;
            this.bt_off7.Text = "OFF7";
            this.bt_off7.UseVisualStyleBackColor = true;
            this.bt_off7.Click += new System.EventHandler(this.bt_off7_Click);
            // 
            // bt_off6
            // 
            this.bt_off6.Enabled = false;
            this.bt_off6.Location = new System.Drawing.Point(512, 192);
            this.bt_off6.Name = "bt_off6";
            this.bt_off6.Size = new System.Drawing.Size(91, 40);
            this.bt_off6.TabIndex = 19;
            this.bt_off6.Text = "OFF6";
            this.bt_off6.UseVisualStyleBackColor = true;
            this.bt_off6.Click += new System.EventHandler(this.bt_off6_Click);
            // 
            // bt_off5
            // 
            this.bt_off5.Enabled = false;
            this.bt_off5.Location = new System.Drawing.Point(415, 192);
            this.bt_off5.Name = "bt_off5";
            this.bt_off5.Size = new System.Drawing.Size(91, 40);
            this.bt_off5.TabIndex = 18;
            this.bt_off5.Text = "OFF5";
            this.bt_off5.UseVisualStyleBackColor = true;
            this.bt_off5.Click += new System.EventHandler(this.bt_off5_Click);
            // 
            // bt_off4
            // 
            this.bt_off4.Enabled = false;
            this.bt_off4.Location = new System.Drawing.Point(706, 146);
            this.bt_off4.Name = "bt_off4";
            this.bt_off4.Size = new System.Drawing.Size(91, 40);
            this.bt_off4.TabIndex = 17;
            this.bt_off4.Text = "OFF4";
            this.bt_off4.UseVisualStyleBackColor = true;
            this.bt_off4.Click += new System.EventHandler(this.bt_off4_Click);
            // 
            // bt_off3
            // 
            this.bt_off3.Enabled = false;
            this.bt_off3.Location = new System.Drawing.Point(609, 146);
            this.bt_off3.Name = "bt_off3";
            this.bt_off3.Size = new System.Drawing.Size(91, 40);
            this.bt_off3.TabIndex = 16;
            this.bt_off3.Text = "OFF3";
            this.bt_off3.UseVisualStyleBackColor = true;
            this.bt_off3.Click += new System.EventHandler(this.bt_off3_Click);
            // 
            // bt_off2
            // 
            this.bt_off2.Enabled = false;
            this.bt_off2.Location = new System.Drawing.Point(512, 146);
            this.bt_off2.Name = "bt_off2";
            this.bt_off2.Size = new System.Drawing.Size(91, 40);
            this.bt_off2.TabIndex = 15;
            this.bt_off2.Text = "OFF2";
            this.bt_off2.UseVisualStyleBackColor = true;
            this.bt_off2.Click += new System.EventHandler(this.bt_off2_Click);
            // 
            // bt_off1
            // 
            this.bt_off1.Enabled = false;
            this.bt_off1.Location = new System.Drawing.Point(415, 146);
            this.bt_off1.Name = "bt_off1";
            this.bt_off1.Size = new System.Drawing.Size(91, 40);
            this.bt_off1.TabIndex = 14;
            this.bt_off1.Text = "OFF1";
            this.bt_off1.UseVisualStyleBackColor = true;
            this.bt_off1.Click += new System.EventHandler(this.bt_off1_Click);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.Red;
            this.button1.Location = new System.Drawing.Point(437, 264);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(182, 89);
            this.button1.TabIndex = 22;
            this.button1.Text = "MODBUS";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1145, 587);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.bt_off8);
            this.Controls.Add(this.bt_off7);
            this.Controls.Add(this.bt_off6);
            this.Controls.Add(this.bt_off5);
            this.Controls.Add(this.bt_off4);
            this.Controls.Add(this.bt_off3);
            this.Controls.Add(this.bt_off2);
            this.Controls.Add(this.bt_off1);
            this.Controls.Add(this.bt_on8);
            this.Controls.Add(this.bt_on7);
            this.Controls.Add(this.bt_on6);
            this.Controls.Add(this.bt_on5);
            this.Controls.Add(this.bt_on4);
            this.Controls.Add(this.bt_on);
            this.Controls.Add(this.bt_on2);
            this.Controls.Add(this.bt_on1);
            this.Controls.Add(this.button_readdata);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.texbox_receiver);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBox_senddata);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "C# COM PORTAL CONTROL";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox cbbox_baudrate;
        private System.Windows.Forms.ComboBox cbbox_comport;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbbox_paritybit;
        private System.Windows.Forms.ComboBox cbbox_stopbit;
        private System.Windows.Forms.ComboBox cbbox_databit;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Button button_sendata;
        private System.Windows.Forms.Button button_close;
        private System.Windows.Forms.Button button_open;
        private System.Windows.Forms.TextBox textBox_senddata;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox texbox_receiver;
        private System.Windows.Forms.Button button_readdata;
        private System.Windows.Forms.Button bt_on1;
        private System.Windows.Forms.Button bt_on2;
        private System.Windows.Forms.Button bt_on;
        private System.Windows.Forms.Button bt_on4;
        private System.Windows.Forms.Button bt_on8;
        private System.Windows.Forms.Button bt_on7;
        private System.Windows.Forms.Button bt_on6;
        private System.Windows.Forms.Button bt_on5;
        private System.Windows.Forms.Button bt_off8;
        private System.Windows.Forms.Button bt_off7;
        private System.Windows.Forms.Button bt_off6;
        private System.Windows.Forms.Button bt_off5;
        private System.Windows.Forms.Button bt_off4;
        private System.Windows.Forms.Button bt_off3;
        private System.Windows.Forms.Button bt_off2;
        private System.Windows.Forms.Button bt_off1;
        private System.Windows.Forms.Button button1;
    }
}

