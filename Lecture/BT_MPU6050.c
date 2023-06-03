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
        roll_value = roll(mpu);
        pitch_value = pitch(mpu);
        display_2values(roll_value,pitch_value);
        // if ( (fabs(GyroX)>3) && GyroX>0)
        // {
        //     arrow(1);
        // }
        // else if ((fabs(GyroX)>3) && GyroX<0)
        // {
        //     arrow(2);
        // }
        // else if ((fabs(GyroY)>3) && GyroY<0)
        // {
        //     arrow(3);
        // }
        // else if (((fabs(GyroY)>3) && GyroY>0))
        // {
        //     arrow(4);
        // }
        // else
        // {
        //     clear_8x8();
        //     for (int i =0;i<8;i++)
        //     {
        //         sendData(i+1,hex[i]);
        //     }
        // }
        // printf("roll:");
        // printf("%f \n",roll_value);
        // printf("pitch:");
        // printf("%f \n",pitch_value);
        // // printf("Z:");
        // // printf("%f \n",GyroZ);
        // delay(100);
        
    }
    return 0;
}



