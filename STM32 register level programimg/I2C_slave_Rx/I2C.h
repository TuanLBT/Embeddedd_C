#include "stm32f10x.h"



void I2C_Config(void);

void I2C_start(void);

void I2C_Stop(void);

void I2C_Write(uint8_t data);

void I2C_Address (uint8_t address);


void I2C_Writemulti(uint8_t *data, uint8_t size);

void I2C_Read(uint8_t address, uint8_t *buffer, uint8_t size);



