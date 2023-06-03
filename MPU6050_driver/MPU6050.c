#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <wiringPiSPI.h>
#include "MPU6050.h"
uint8_t who;


//check I2C connection
void check_connect(int mpu)
{
   // mpu = wiringPiI2CSetup(0x68);
   // test I2C conection
   who = wiringPiI2CReadReg8(mpu,0x75);

   if(who!=0x68){
        printf("Connection fail. \n");
   }
   else{
        printf("Connection successful. \n");
   }
}


//read value from resgister of sensor
int16_t readSensor(int mpu,uint8_t address){
    uint8_t high,low;
    int16_t value;
    high = wiringPiI2CReadReg8(mpu,address);
    low = wiringPiI2CReadReg8(mpu,address+1);
    value = ((high<<8)|low);
    return value;
    
}

//read temperature
float temperature(int mpu) //numbers of digits display after demical dot
{
    float temp; int16_t value;
    value = readSensor(mpu,0x41);
    temp = value/340.0 +36.53;
    return temp;
}
//read accelerator
float roll(int mpu)
{
    float AccX,AccY,AccZ; float roll;
    AccX = readSensor(mpu,0x3B) / 16384.0;
    AccY = readSensor(mpu,0x3D) / 16384.0;
    AccZ = readSensor(mpu,0x3F) / 16384.0;

    roll = (atan((AccY) / sqrt(pow((AccX), 2) + pow((AccZ), 2))) * 180 / M_PI);
    return roll;
}
float pitch(int mpu)
{
    float AccX,AccY,AccZ; float pitch;
    AccX = readSensor(mpu,0x3B) / 16384.0;
    AccY = readSensor(mpu,0x3D) / 16384.0;
    AccZ = readSensor(mpu,0x3F) / 16384.0;
    pitch = (atan(-1 * (AccX) / sqrt(pow((AccY), 2) + pow((AccZ), 2))) * 180 / M_PI);
    return pitch;
}

// int main(void){
//     //set up i2c 
//    mpu = wiringPiI2CSetup(0x68);
//    // test I2C conection

//    //Configuration mpu
//    iniMpu();
//    // setup SPI interface
//     wiringPiSPISetup(spi0, 10000000);
//     // set operational mode for max7219
//     Init();
//    // Read temperature value and display on max7219
//    while(1){
    
//    }
//    return 0;
// }
