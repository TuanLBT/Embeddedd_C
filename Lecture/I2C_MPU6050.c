#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <wiringPiSPI.h>
/*int ds3231;

void d2h(){
    uint8_t h,dv,ch;
    dv = d%10;ch = d/10;
    h = (ch<<4)|dv;
    return h;
}*/
int mpu;
uint8_t who, flag = 0;

#define spi0   0
uint8_t buf[2];

void sendData(uint8_t address, uint8_t data){
    buf[0] = address;
    buf[1] = data;
    wiringPiSPIDataRW(spi0, buf, 2);
}

void Init(void){
    // set decode mode: 0x09FF
    sendData(0x09,0xFF);
    // set intensity: 0x0A09
    sendData(0x0A, 9);
    // scan limit: 0x0B07
    sendData(0x0B, 7);
    // no shutdown, turn off display test
    sendData(0x0C, 1);
    sendData(0x0F, 0);
}
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
int16_t readSensor(uint8_t address){
    uint8_t high,low;
    int16_t value;
    high = wiringPiI2CReadReg8(mpu,address);
    low = wiringPiI2CReadReg8(mpu,address+1);
    value = ((high<<8)|low);
    return value;
    
}

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

int main(void){
    //set up i2c 
   mpu = wiringPiI2CSetup(0x68);
   // test I2C conection
   who = wiringPiI2CReadReg8(mpu,0x75);

   if(who!=0x68){
        printf("Connection fail. \n");
        //printf("%x\n",who);
        //break;
   }
   else
   {
    flag = 1;
   }
   //Configuration mpu
   iniMpu();
   // setup SPI interface
    wiringPiSPISetup(spi0, 10000000);
    // set operational mode for max7219
    Init();
   // Read temperature value and display on max7219
   while(1){
    if(flag == 1)
    {
        float temp;
        temp = readSensor(0x41);
        temp = temp/340.0 +36.53;
        //printf("%f\n",temp);
        display_float(temp,3);
        delay(1000);
    }
    
   }
   return 0;
}
