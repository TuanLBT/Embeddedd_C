
#include "delay_F103.h"
uint32_t i=0;
void TIM2_Config(void)
{
	/*************step to follow**************
	1. Enable the timer clock
	2. set the prescaler and the ARR
	3. Enable the timer, and wait for the update flag to exet
	*******************************************/
	//1. enable the clock for timer2
	RCC->APB1ENR |= (1<<0); 
	//2.1 set the prescaler of the timer
	TIM2->PSC |= (72-1); //prescale at 72 time, 72Mhz/72 = 1Mhz (The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).)
	//2.2 Set the ARR value (maxium value of 16 bit register)
	TIM2->ARR |= 0xffff-1;
	//3.1 Enable the timer 2:
	TIM2->CR1 |= (1<<0);
	//3.2 Waiting the timer 2 to be enable (UIF BIT TO BE SET)
	while(!(TIM2->SR & (1<<0))); 
}

void delay_us(uint32_t us)
{
	/**********step to follow***********
	1. RESET the counter
	2. wait for the counter to reach the entered value. As each count will take 1 us, 
	the total waiting time will be the required us delay
	*/
	
	//1. reset the counter (VALUE = 0)
	TIM2->CNT = 0;
	//2. wait for the counter to reach the entered value input
	while(TIM2->CNT < us);
}

void delay_ms(uint32_t ms)
{
	for(i=0; i<ms; i++)
	{
		delay_us(1000); // delay of 1ms
	}
}

