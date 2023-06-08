#include "I2C.h"

void I2C_Config(void)
{
	/**************step to follow (F4XX)****************
	1. Enable the I2c clock and GPIO clock
	2. configure the i2c pins for Alternate functions
		a. Select the alternate function in MODER register
		b. select open drain output
		c. select high speed for the pins
		d. select pull up for both the pins
		e. configure the alterante funtion in AFR register
	3. reset the I2c
	4. programe the peropheral input clock in I2C_CR2 register in order to generate correct timings
	5. configure the clock control registers
	6. configre the rise time registers
	7. programe the I2C_CR1 register to enable the peripheral
	********************************************/
	
	//1. enable the I2c clock and GPIO port B clock (I2c using port B pins)
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN; //enable I2C clock
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; //enable the GPIO port B clock
	
	//2. configure the I2C pins (PB7 SDA; PB6 SCL)
	GPIOB->CRL &= ~(GPIO_CRL_CNF6  | GPIO_CRL_MODE6);   //reset pin B6
	GPIOB->CRL &= ~(GPIO_CRL_CNF7  | GPIO_CRL_MODE7);	//reset pin B7
	
	GPIOB->CRL |= GPIO_CRL_MODE7_0 | GPIO_CRL_MODE7_1;//0b11: output open drain, 50Mhz (PB7-SDA)
	GPIOB->CRL |= GPIO_CRL_CNF7_0 | GPIO_CRL_CNF7_1;  //0b11: Alternate function output Open-drain
	
	GPIOB->CRL |= GPIO_CRL_MODE6_0 | GPIO_CRL_MODE6_1;//0b11: output open drain, 50Mhz (PB6-SCL)
	GPIOB->CRL |= GPIO_CRL_CNF6_0 | GPIO_CRL_CNF6_1; //0b11: Alternate function output Open-drain
	
	//3. reset the I2C
	I2C1->CR1 |= I2C_CR1_SWRST; // put the I2c peripheral under reset state
	I2C1->CR1 &= ~I2C_CR1_SWRST; //put in out of the reset state
	
	//4. programe the peripheral input clock in I2C_CR2 register in order to generate correct timings
	I2C1->CR2 |= I2C_CR2_FREQ_2 | I2C_CR2_FREQ_5; //36Mhz of APB1 clock frequency
	
	//5. configure the clock control registers
	//I2C1->CCR |= (1<<15); // Sm mode (Standard mode)
	I2C1->CCR |= 180; //CRR value after calculated
	
	//6. configre the rise time registers
	I2C1->TRISE |= 9; //filter value after calculated (caculated value not work, so pick 9 instead
	
	//7. programe the I2C_CR1 register to enable the peripheral
	I2C1->CR1 |= I2C_CR1_PE;
	
}

void I2C_start(void)
{
	/*************step to follow***************
	1. Send the START condition
	2. Wait for the SB (bit 0 in SR1) to set. This indicate that the start condition is generated
	*******************************************/
	I2C1->CR1 |= I2C_CR1_ACK; // enable the ACK
	I2C1->CR1 |= I2C_CR1_START; //generate start
	while(!(I2C1->SR1 & I2C_SR1_SB)); //wait for the SB bit to set

	
}

void I2C_Write(uint8_t data)
{
	/****************step to follow**************
	1. wait for the TXE (bit 7 in SR1) to set. This indicates that the DR is emty
	2. send the DATA to the DR register
	3. wait for the BTF (bit 2 in SR1) to set. This indicates the end of LAST DATA transmission
	*********************************************/
	while(!(I2C1->SR1 & I2C_SR1_TXE )); //wait for the TXE bit to set
	I2C1->DR = data; //write the data to the DR register
	while(!(I2C1->SR1 & I2C_SR1_BTF )); //wait for the BTF bit to set
}

void I2C_Address (uint8_t address)
{
	/***************step to follow****************
	1. Send the Slave address to the DR register
	2. wait for the ADDR (bit in SR1) to set. This indicates the end of address transmission
	3. clear the ADDR by reading the SR1 and SR2
	**********************************************/
	
	I2C1->DR = address; //send the address
	while(!(I2C1->SR1 & (1<<1))); //wait for the ADDR bit to set
	uint8_t temp = I2C1->SR1 | I2C1->SR2; //read the SR1 and Sr2 to clear the ADDR bit
	
}

void I2C_Stop(void)
{
	I2C1->CR1 |= I2C_CR1_STOP; // stop I2C
}

void I2C_Writemulti(uint8_t *data, uint8_t size)
{
	/*********************step to follow********************
	1. wait for the TXE (bit 7 in SR1) to set. This indicates that the DR is emty
	2. keep sending DATA to the DR register after performing the check if the TXE bit is set
	3. Once the DATA transfer is complete, Wait for the bit (bit 2 in SR1) to set. This indicates the end of LAST DATA transmission
	*******************************************************/
	while(!(I2C1->SR1 & I2C_SR1_TXE )); //wait for the TXE bit to set
	while(size)
	{
		while(!(I2C1->SR1 & I2C_SR1_TXE ));//wait for the TXE bit to set
		I2C1->DR = (volatile uint32_t)*data++; // send data
		size--;
	}
	
	while(!(I2C1->SR1 & I2C_SR1_BTF )); //wait for the BTF bit to set
	
}

void I2C_Read(uint8_t address, uint8_t *buffer, uint8_t size)
{
	/**************steps follow****************************8
	1. If only 1 byte needs to be read
		a. Write the salve address, and wait for the ADDR bit (bit 1 in SR1) to be set
		b. the acknowlegde disble is made during EV6 (before ADDR falg is cleared flag is cleared ) and the STOp condition generation is made after EV6
		c. wait for the RXNE (Receive buffer not emty ) bit to set
		d. read the data frome the DR
	
	2. if multiple bytes needs to be read
		a. write the slave address, and wait for the ADDR bit to be set
		b. clear the ADDR bit by readng the SR1 and SR2 registers
		c. wait for the RXNE (Receive buffer not emty) bit to set
		d. read the data from the DR
		e. Generate the Acknowledgment by setting the ACK (bit 10 in SR1)
		f. to gennerate the noacknowledge pulse after the last recerived data byte, the ACK bit must be cleared after reading 
			the second last data byte (after secon last ExNE event)
		g. In order to generate the Stop/Restart condition, softwate must set the Stop/START bit after reading the second last data byte 
			(after the second last RXNE event)
	************************************************/
	
	int remaining = size;
	/*1 bytes*/
	if (size == 1)
	{
		//step a
		I2C1->DR = address; // send the address
		while(!(I2C1->SR1 & I2C_SR1_ADDR)); // wait for ADDR bit to set
		
		//step b
		I2C1->CR1 &= ~I2C_CR1_ACK; // clear the ACK bit 
		uint8_t temp = I2C1->SR1 | I2C1->SR2; //read SR1 and Sr2 to clear the ADDR bit (EV6 condition)
		I2C1->CR1 |= I2C_CR1_STOP; //stop the I2C
		
		//step c
		while(!(I2C1->SR1 & I2C_SR1_RXNE)); //wait for the RXNE bit to be set
		
		//step d
		buffer[size-remaining] = I2C1->DR; //after the RXNE set, read the data from the data register
	}
	
	/*Multiple bytes*/
	else
	{
		//step a
		I2C1-> DR = address; // send the address
		while(!(I2C1->SR1 & I2C_SR1_ADDR)); //wait for the ADDr bit to set
		
		//step b
		uint8_t temp = I2C1->SR1 | I2C1->SR2; //read SR1 and SR2 to clear the ADDR bit
		
		
		// reading the second last data byte (after secon last ExNE event)
		while(remaining>2) 
		{
			//step c
			while(!(I2C1->SR1 & I2C_SR1_RXNE)); //wait for the RXNE bit to be set
			
			//step d
			buffer[size-remaining] = I2C1->DR; //after the RXNE set, read the data from the data register
			
			//step e 
			I2C1->CR1 |= I2C_CR1_ACK; //set the ACK bit in CR1 register to acknowledge the data received
			
			remaining--;
		}
		
		
		/*after reading the second last data byte, clear ACK bit in order to gennerate the noacknowledge 
		pulse after the last recerived data byte (step f)*/
		I2C1->CR1 &= ~I2C_CR1_ACK;
		
		//step g
		I2C1->CR1 |= I2C_CR1_STOP; //stop the I2C
		
		remaining--;
		
		//read the last BYTE
		while(!(I2C1->SR1 & I2C_SR1_RXNE)); //wait for the RxNE to set
		buffer[size-remaining] = I2C1->DR; // copy the data in to the buffer
	}
}