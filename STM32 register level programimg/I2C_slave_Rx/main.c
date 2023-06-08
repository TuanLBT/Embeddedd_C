#include "RCC.h"
#include "delay_F103.h"
#include "stm32f10x.h"
#include "I2C.h"



void MPU_Init(void);
void MPU_Write(uint8_t address, uint8_t reg, uint8_t data);
void MPU_Read(uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t size);


#define MPU6050_ADDR_WRITE 0xD0 //write data to mpu
//#define MPU6050_ADDR_READ 0xD1 //read data  MPU

#define SMPLRT_DIV_REG 0x19    //The Sample Rate is determined by dividing the gyroscope output rate by this value in this register
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C

#define ACCEL_XOUT_H_REG 0x3B //data of Accelerometer High register
#define ACCEL_XOUT_L_REG 0x3C //data of Accelerometer Low register
#define ACCEL_YOUT_H_REG 0x3D 
#define ACCEL_YOUT_L_REG 0x3E 
#define ACCEL_ZOUT_H_REG 0x3F 
#define ACCEL_ZOUT_L_REG 0x40 

#define GYRO_XOUT_H_REG 0x43 //data of Gyroscope High register
#define GYRO_XOUT_L_REG 0x44 //data of Gyroscope Low register
#define GYRO_YOUT_H_REG 0x45 
#define GYRO_YOUT_L_REG 0x46 
#define GYRO_ZOUT_H_REG 0x47 
#define GYRO_ZOUT_L_REG 0x48 

#define TEMP_OUT_H_reg 0x41   //data of temperature High register
#define TEMP_OUT_L_reg 0x42

#define PWR_MGMT_1_REG 0x6B   //power manager
#define WHO_AM_I_REG 0x75
#define CONFIG 0x1A //configures the FSYNC and DLPF

uint16_t Accel_X_raw = 0;
uint16_t Accel_Y_raw = 0;
uint16_t Accel_Z_raw = 0;

float Ax, Ay, Az, Gx, Gy, Gz;

uint8_t check;


void MPU_Init(void)
{
	uint8_t check=0;
	//check device ID WHO_AM_I (check connect)
	MPU_Read(MPU6050_ADDR_WRITE, WHO_AM_I_REG, &check, 1);
	
	if (check == 0x68)
	{
		//power management 
		/*According to the datasheet, it is highly recommended that the device be configured to use 
		one of the gyroscopes (or an external clock source) as the clock reference for improved stability
		Because of that, choose the PLL (Phase-Locked Loop) with X axis gyroscope reference.  */
		MPU_Write(MPU6050_ADDR_WRITE,PWR_MGMT_1_REG, 0x01); 
		
		//sample rate (1KHz)
		MPU_Write(MPU6050_ADDR_WRITE, SMPLRT_DIV_REG, 0X07);
		
		/*low pass filter 
		Accelerometer: (bandwidth=44Hz; delay_ms=4.9; Fs(kHz)=1)
		Gyroscope: (bandwidth=42Hz; delay_ms=4.8; Fs(kHz)=1)
		*/
		MPU_Write(MPU6050_ADDR_WRITE, CONFIG, 0x03);
		
		//config accelerometer AFS_SEL=(b10) +-8g 
		MPU_Write(MPU6050_ADDR_WRITE, ACCEL_CONFIG_REG, 0x10);
		//config gyrometer +-500
		MPU_Write(MPU6050_ADDR_WRITE, GYRO_CONFIG_REG, 0x08);
	}
}



void MPU_Write(uint8_t address, uint8_t reg, uint8_t data)
{
	I2C_start();
	I2C_Address(address);
	I2C_Write(reg);
	I2C_Write(data);
	I2C_Stop();
}


void MPU_Read(uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t size)
{
	I2C_start();
	I2C_Address(address); //write data to slave
	I2C_Write(reg);
	
	I2C_start(); // reapeat start 
	I2C_Read(address + 0x01, buffer, size); //read data from slave
	I2C_Stop();
}

void MPU6050_read_Accel(void)
{
	uint8_t Rx_data[6];
	
	//read 6 byte of data starting from ACCEL_XOUT_H register
	MPU_Read(MPU6050_ADDR_WRITE, ACCEL_XOUT_H_REG, Rx_data, 6);
	
	Accel_X_raw = (uint16_t)(Rx_data[0] << 8 | Rx_data[1]); //store value of both HIGH and LOW register data 
	Accel_Y_raw = (uint16_t)(Rx_data[2] << 8 | Rx_data[3]);
	Accel_Z_raw = (uint16_t)(Rx_data[4] << 8 | Rx_data[5]);
	
	//convert RAW value to g value
	Ax = Accel_X_raw/4096.0;
	Ay = Accel_Y_raw/4096.0;
	Az = Accel_Z_raw/4096.0;
	
}

int main(void)
{
	SysClockConfig();
	TIM2_Config();
	I2C_Config();
	
	MPU_Init();
	
	while(1)
	{
		MPU6050_read_Accel();
		/*
		I2C_start();
		I2C_Address(MPU6050_ADDR_WRITE); //write data to slave
		//I2C_Stop();
		
		//I2C_start();
		I2C_Write(WHO_AM_I_REG);
		//I2C_Stop();
		
		//I2C_start(); // reapeat start 
		I2C_Read(MPU6050_ADDR_WRITE + 0x01, &check, 1); //read data from slave
		I2C_Stop();*/
		
		/*
		I2C_start();
		I2C_Address(0x40);
		I2C_Write(1);
		I2C_Stop();
		delay_ms(1000);
		*/
	}
}