#include <wiringPiSPI.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>

#define spi0   0
uint8_t buf[2];

//HAM INIT

void Init(void){ 
    // set decode mode: 0x09FF
    sendData(0x09,0xFF);
    // set intensity: 0x0A09
    sendData(0x0A, 9);
    // scan limit: 0x0B  (07) Display digits 0 1 2 3 4 5 6 7 table 8.  Scan-Limit Register Format (Address (Hex) = XB)
    sendData(0x0B, 7);
    // no shutdown, turn off display test
    sendData(0x0C, 1);
    sendData(0x0F, 0);
}


//HAM GUI DATA

void sendData(uint8_t address, uint8_t data){ 
    buf[0] = address;
    buf[1] = data;
    wiringPiSPIDataRW(spi0, buf, 2);
}

//gui data va hienthi
void sendData_SHOW(uint8_t data[], uint8_t datasize)
{
    for (int i=0; i<datasize;i++)
    {
        send_data(i+1, data[datasize - 1 -i]);
    }
}

//HAM HHIEN THI SO
void display_number(uint32_t num){ 
    // count the number of digits
    uint8_t count=1;
    uint32_t n = num;
    while(n/10){ //lap lai den khi n/10 = 0
        count++;
        n = n/10;
    }
    // set scanlimit
    sendData(0x0B, count-1); //0x0B chi la cai dia chi thanh ghi thoi, count-1 la so luong number hien thi dc cung luc tren den led
    // dislay number
    for(int i=0; i<count;i++){ //vong for de dua tung chu so cua number len hien thi
        sendData(i+1,num%10); //senddata(table2-datasheet, table-5-register_data)
        num = num/10;
    }
}


//hàm dịch nội dung trên module led 7 đoạn sang trái, phải.
void shift_data(uint8_t data[], uint8_t datasize , uint8_t solandich, uint8_t dir)
{ 
    switch(dir)
    {   case 0:
        //chay vo ben trai
        for(j = 0; j<= solandich ;j++)
        {
            if(j==0)
            {
                for (int i=j; i<datasize ;i++)
                {
                    send_data(i + 1 -j, data[datasize - 1 -i]);
                }
            }
            if(j>0)
            {   
                
                for (int i=j; i<datasize ;i++)
                {
                    send_data(i + 1 -j, data[datasize - 1 -i]);
                }
                send_data(9-j, 15); //15 la ki hieu rong (null)
            }
            delay(500);
        }
        //chayra tu ben trai
        for(int k = 0; k<= solandich ;k++) //vong lap dich data
        {   
            for (int l = 0;l<k;l++)
            {
                send_data(datasize-l, data[datasize - k +l]);
            }
            delay(500);
        }
        break;




        case 1:
        //dich sang ben phai
        for(j=0;j<=solandich;j++)
        {
            if(j==0)
            {
                for (int i=datasize; i>j ;i--)
                {
                    send_data(i, data[datasize-i+j]);
                }
            }
            if(j>0)
            {   
                
                for (int i=datasize; i>j ;i--)
                {
                    send_data(i, data[datasize-i+j]);
                }
                send_data(j, 15); //15 la ki hieu rong (null)
            }
            delay(1000);
        }
        //dich lai tu benb phai qua (neu solandich = 8)
        for(int m = 0; m< solandich ;m++) //vong lap dich data
        {   
            for (int n = 0;n<=m;n++)
            {
                send_data(n+1, data[m-n]);
            }
            delay(1000);
        }
        break;
    }
}
