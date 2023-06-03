/*include the library here */
#include "stm32f10x.h"
#include "RCC.h"
#include "delay_F103.h"


/*add the prototype (declare functions) at here*/
void GPIO_Config(void);
void Uart2Config(void);
void UART2_Sendchar(uint8_t c);
void UART2_SendString(char *string);

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
	/*GPIOC->CRH |= ((0<<23) | (0<<22)); bit 23:22 as general output push-pull (00) 0 value so dont need to set this line*/
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
	
	/*1.1 Enable clock of UART2*/
	RCC->APB1ENR |= (1<<17);
	/*1.2 Enable the GPIO port A pin (UART2 is on A pin)*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	
	/*2.configure the UART PINS for Alternate Function Pin A3 (RX) and A2 (TX)*/
	
	GPIOA->CRL &= ~(GPIO_CRL_CNF2  | GPIO_CRL_MODE2);   //reset pin A2
	GPIOA->CRL &= ~(GPIO_CRL_CNF3  | GPIO_CRL_MODE3);	//reset pin A3 
	
	
	GPIOA->CRL |= GPIO_CRL_MODE2_1 | GPIO_CRL_MODE2_0; //0b11 50Mhz output
	GPIOA->CRL |= GPIO_CRL_CNF2_1; //PA2: output @50Mhz - Alt-function Push Pull (Tx)
	GPIOA->CRL |= GPIO_CRL_CNF3_0; //PA3 Rx -mode = 0b00 (input) - CNF = 0b01 (input floating)
	
	
	/*3. enable the UART */
	USART2->CR1 |= 0; /*clear all*/
	USART2->CR1 |= USART_CR1_UE; /*enable the UART*/
	
	
	/*4. Program the M bit in UART_CR1 to define the word length*/
	//USART2->CR1 |= ~(1<<12); /*1 start bit, 8 databit, n stop bit*/
	
	
	/*5. select the baundrate using USART_BRR register*/
	uint32_t baud = (uint32_t)(36000000/115200);
	USART2->BRR |=  baud;//((19<<4) | (8<<0)); /*baundrate 115200, PCLK1 at 36Mhz*/
	
	
	/*6. enable the Transmitter and receiver in USART_CR1 register*/
	USART2->CR1 |= USART_CR1_RE | USART_CR1_TE; /*Tx (bit3), Rx (bit2)*/
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
	
	USART2->DR |= (int)c; /*write the data in to the DR register*/
	while(!(USART2->SR & USART_SR_TC)); /*wait for the TC bit to SET.. this indicates that the data has been transmitted*/
}

void UART2_SendString(char *string)
{
	while(*string)
	{
		UART2_Sendchar(*string++);
	}
	
}

uint16_t UART2_GetChar(void)
{
	/*************step to follow**************
	1. Wait for the RXNE bit to set. It indicates that the data has bee received and can be read.
	2. read the data from USART_DR register. This also clears the RXNE bit
	*****************************************/
	uint16_t temp;
	while (!(USART2->SR & USART_SR_RXNE)); //wait for RXNE to be set (data is ready to be read)
	temp = USART2->DR; //read the data and store the data in to the temp variable
	
	return temp;
}
/*main function*/
int main(void)
{
	SysClockConfig ();
	TIM2_Config();
	Uart2Config();
	while(1)
	{
		//UART2_Sendchar('T');
		//delay_ms(1000);
		
		uint16_t data =  UART2_GetChar();
		UART2_Sendchar(data);
		
	}
}
