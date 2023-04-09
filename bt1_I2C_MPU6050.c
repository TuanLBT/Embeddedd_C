#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "MAX7219.h"
#include "MPU6050.h"
#define spio 0 
void arrow(int dir);
unsigned char data[2]; //khai bao ham
uint8_t hex[8] =    {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};
int mpu;
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;

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
        GyroX = readSensor(mpu,0x43) / 131.0; // For a 250deg/s range we have to divide first the raw value by 131.0, according to the datasheet
        GyroY = readSensor(mpu,0x45) / 131.0;
        GyroZ = readSensor(mpu,0x47) / 131.0;
        if ( (fabs(GyroX)>3) && GyroX>0)
        {
            arrow(1);
        }
        else if ((fabs(GyroX)>3) && GyroX<0)
        {
            arrow(2);
        }
        else if ((fabs(GyroY)>3) && GyroY<0)
        {
            arrow(3);
        }
        else if (((fabs(GyroY)>3) && GyroY>0))
        {
            arrow(4);
        }
        else
        {
            clear_8x8();
            for (int i =0;i<8;i++)
            {
                sendData(i+1,hex[i]);
            }
        }
        // printf("X:");
        // printf("%f \n",GyroX);
        // printf("Y:");
        // printf("%f \n",GyroY);
        // printf("Z:");
        // printf("%f \n",GyroZ);
    }
    return 0;
}



