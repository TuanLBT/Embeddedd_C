#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "MAX7219.h"
#include "MPU6050.h"
#define spio 0 
void values(float alphaX, int state);
void arrow(int dir);
unsigned char data[2]; //khai bao ham
uint8_t digit1[10] = {0X7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};
int mpu;
float roll_value, pitch_value;

void iniMpu(void){
    //sample rate 100 Hz
    wiringPiI2CWriteReg8(mpu,0x19,9);
    //DLPF: fc = 44 Hz
    wiringPiI2CWriteReg8(mpu,0x1A,0x03);
    //GyRO Configuration: +-500
    wiringPiI2CWriteReg8(mpu,0x1B,0x08);
    // Acc Configuration: +-8g
    wiringPiI2CWriteReg8(mpu,0x1C,0x10);
    // Interrupt: enable data ready interrupt
    wiringPiI2CWriteReg8(mpu,0x38,1);
    // power managment
    wiringPiI2CWriteReg8(mpu,0x6B,0x01);
    //low pass filter
    wiringPiI2CWriteReg8(mpu,0x1A,0x02);
}


int main(void)
{
    //set up SPI interface
    wiringPiSPISetup(spio,10000000);
    //setup i2c interface 
    mpu = wiringPiI2CSetup(0X68);
    //init spi
    Init_8x8matrix();
    //initmpu6050
    iniMpu();
    //test i2c connection
    check_connect(mpu);
    //clear 8x8
    clear_8x8();
    while(1)
    {  
        float roll_value = roll(mpu);
        printf("\r%f",roll_value);
        if(roll_value<10)
        {
            values(roll_value,0);
        }
        else if(0<roll_value<10)
        {
            values(roll_value,1);
        }
        else
        {
            
        }
        
        
    }
    return 0;
}
void values(float alphaX, int state)
{
    int i_alphaX = alphaX*10; 
    i_alphaX = fabs(i_alphaX);
    //lay tung chu so
    uint8_t thapphan_alphaX = i_alphaX%10;
    uint8_t donvi_alphaX = (i_alphaX%100)/10;
    uint8_t chuc_alphaX = i_alphaX/100;

    sendData(6,digit1[thapphan_alphaX]);
    sendData(7,digit1[donvi_alphaX] | 0x80);
    sendData(8,digit1[chuc_alphaX]);

    if(state == 0)
    {
        sendData(1,0x76);
        sendData(2,0x4F);
        sendData(3,0x67);
        sendData(4,0x7E);
        sendData(5,0x00);
    }
    else
    {
        sendData(1,0x4F);
        sendData(2,0x5B);
        sendData(3,0x7E);
        sendData(4,0x0E);
        sendData(5,0x4E);
    }
    
}
/*
//Calculate the accleration in the inertial Z axis
AccZInertial = -sin(AnglePitch*(3.142/180))*AccX + cos(AnglePitch*(3.142/180))*sin(AngleRoll*(3.142/180))*AccY + cos(AnglePitch*(3.142/180))*cos(AngleRoll*(3.142/180))*AccZ;
//conver the accleration to cm/s^2
*/

