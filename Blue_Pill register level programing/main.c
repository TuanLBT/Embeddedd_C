/*include the library here */
#include "stm32f10x.h"
#include "RCC.h"
#include "delay_F103.h"
#include <stdint.h>


/*add the prototype (declare functions) at here*/
void GPIO_Config(void);
//void delay(uint32_t time);
void Uart2Config(void);


/*all functions here*/
void GPIO_Config(void)
{
	/*********STEPS FOLLOW*****************
	1. Enable the GPIO clock
	2. set the pin as output
	3. configure the output mode
	***************************************/
	
	/*1. Enable the GPIO clock (APB1 peripheral clock enable register (RCC_APB1ENR)*/
	RCC->APB2ENR |= (1<<4); /*PORT C ENABLE*/
	/*2. set the pin as output*/
	GPIOC->CRH |= (1<<20); /*Pin c13, (bits 21:20 as output, maxspeed 2Mhz (10)*/ 
	/*3. configure the output mode*/
	//GPIOC->CRH |= ((0<<23) | (0<<22)); /*bit 23:22 as general output push-pull (00)*/ 0 value so dont need to set this line
}
	
void Uart2Config(void)
{
	/**********step to follow****************
	1. Enable the UART clock and GPIO clock
	2. configure the UART PINS for Alternate Function
	3. Enable the UART by writing the UE bit in UART_CR1 register to 1
	4. Program the M bit in UART_CR1 to define the word length
	5. Select the desired baud rate using the UART_BRR register
	6. Enable the transmitter/Receiver by setting the TE and RE bits in UART_CR1 register
	*****************************************/
	
	//1.1 Enable clock of UART2
	RCC->APB1ENR |= (1<<17);
	//1.2 Enable the GPIO port A pin (UART2 is on A pin)
	RCC->APB1ENR |= (1<<2);
	//2.configure the UART PINS for Alternate Function Pin A3 (RX) and A2 (TX)
	GPIOA->CRL |= (1<<11); //output mode: alternate function push pull Pin A2(Tx)
	GPIOA->CRL |= ((1<<9) | (1<<8)); //output speed: 50Mz (pinA2)
	
	GPIOA->CRL |= ((0<<13) | (0<<12)); //input mode for pinA3 (Rx)
	GPIOA->CRL |= (1<<15); //input with pull-up, pull-down pin A3
	//3. enable the UART 
	USART2->CR1 |= 0; //clear all
	USART2->CR1 |= (1<<13); //enable the UART
	//4. Program the M bit in UART_CR1 to define the word length
	USART2->CR1 |= ~(1<<12); //1 start bit, 8 databit, n stop bit
	//5. select the baundrate using USART_BRR register
	USART2->BRR |= ((19<<4) | (8<<0)); //baundrate 115200, PCLK1 at 36Mhz
	//6. enable the Transmitter and receiver in USART_CR1 register
	USART2->CR1 |= ((1<<3) | (1<<2)); //Tx (bit3), Rx (bit2)
}

void UART2_Sendchar(uint8_t c)
{
	/************step follow******************
	1. write the data to send in the UART_DR register (this clears the TXE bit). Repeat this 
		for each data to be transmitted in case of single buffer
	2. After writing the last data into the USART_DR register, wait until TC=1. This indicates
		that the transmission of the last frame is complete. This is required for instance when 
		that USART is disabled or enters the Halt mode to avoid corrupting the last transmission
	*****************************************/
	
	USART2->DR |= c; //write the data in to the DR register
	while(!(USART2->SR & (1<<6))); //wait for the TC bit to SET.. this indicates that the data has been transmitted
}
/*main function*/
int main(void)
{
	
	SysClockConfig ();
	TIM2_Config();
	//GPIO_Config ();
	Uart2Config();
	while(1)
	{
		/* blink led program
		GPIOC->BSRR |= (1<<13);
		delay_ms(1000);
		GPIOC->BSRR |= (1<<29);
		//or this code work the same GPIOA->BSRR |= ((1<<5) << 16);
		delay_ms(1000);
		*/
		
		UART2_Sendchar('T');
		delay_ms(1000);
	}
}
