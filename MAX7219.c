#include <wiringPiSPI.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "MAX7219.h"
#define spi0   0
uint8_t buf[2];

//display float fuction (copy hàm của thầy)
void display_float(float num, uint8_t dec){
    int16_t integerPart = num;
    int16_t fractionalPart = (num - integerPart) * pow(10,dec);
    int16_t number = integerPart*pow(10,dec) + fractionalPart;
    // count the number of digits
    uint8_t count=1;
    int16_t n = number;
    while(n/10){
        count++;
        n = n/10;
    }
    // set scanlimit
    sendData(0x0B, count-1);
    // dislay number
    for(int i=0; i<count;i++){
        if(i==dec)
            sendData(i+1,(number%10)|0x80); // turn on dot segment 
        else
            sendData(i+1,number%10);
        number = number/10;
    }
}

//****************************************************************7 segments led**********************************************************************
//Init function (hàm khởi tạo led 7 đoạn)
int j;
void Init_7segments(void){ 
    // set decode mode: 0x09 FF (địa chỉ thanh ghi là 0x09)
    sendData(0x09,0xFF);
    // set intensity: 0x0A 09
    sendData(0x0A, 9);
    // scan limit: 0x0B  hiển thị cùng lúc 8 ô led 7 đoạn table 8.  Scan-Limit Register Format (Address (Hex) = XB)
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

//gui 1 chuỗi data va hienthi lên led 
void sendData_SHOW(uint8_t data[], uint8_t datasize)
{
    for (int i=0; i<datasize;i++)
    {
        sendData(i+1, data[datasize - 1 -i]);
    }
}

//Hàm hiển thị số (số nhiều hàng đơn vị)
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

//ham hien thi led matrix



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
                    sendData(i + 1 -j, data[datasize - 1 -i]);
                }
            }
            if(j>0)
            {   
                
                for (int i=j; i<datasize ;i++)
                {
                    sendData(i + 1 -j, data[datasize - 1 -i]);
                }
                sendData(9-j, 15); //15 la ki hieu rong (null)
            }
            delay(500);
        }
        //chayra tu ben trai
        for(int k = 0; k<= solandich ;k++) //vong lap dich data
        {   
            for (int l = 0;l<k;l++)
            {
                sendData(datasize-l, data[datasize - k +l]);
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
                    sendData(i, data[datasize-i+j]);
                }
            }
            if(j>0)
            {   
                
                for (int i=datasize; i>j ;i--)
                {
                    sendData(i, data[datasize-i+j]);
                }
                sendData(j, 15); //15 la ki hieu rong (null)
            }
            delay(1000);
        }
        //dich lai tu benb phai qua (neu solandich = 8)
        for(int m = 0; m< solandich ;m++) //vong lap dich data
        {   
            for (int n = 0;n<=m;n++)
            {
                sendData(n+1, data[m-n]);
            }
            delay(1000);
        }
        break;
    }
}


//****************************************************************8x8 matrix**********************************************************************

//Khởi tạo led ma trận 8x8 
void Init_8x8matrix(void){ 
    // set decode mode: 0x09FF
    sendData(0x09,0x00);
    // set intensity: 0x0A09
    sendData(0x0A, 9);
    // scan limit: 0x0B  
    sendData(0x0B, 7);
    // no shutdown, turn off display test
    sendData(0x0C, 1);
    sendData(0x0F, 0);
}

//Hàm clear hết những gì có trên led 8x8
void clear_8x8(void)
{
    for(int i=0; i<8;i++){
        sendData(i+1,0);
    }
}
