#include "RCC.h"
#include "delay_F103.h"

void ADC_Init(void);


void ADC_Init(void)
{
	/******************step to follow***********************
	1. enable ADC and GPIO clock
	2. set the prescaler in the Common control regster (CCR)
	3. Set the scan mode and resolution in the control register 1 (CR1)
	4. set the continous Conversion, EOC, and DAta Aligment in COntrol Register 2 (CR2)
	5. set the Sampling time for the channels in ADC SMPRx
	6. set the regular channel sequence length in ADC_SQR1
	7. Set the respective GPIO Pins in the analog Mode
	*******************************************************/
	
	//enable the GPIO and ADC clock (using 2 channel connect to port A)
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // enable clock GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //enable ADC1
	
	
	//set the prescaler in the Common control regster (CFGR)
	RCC->CFGR |= RCC_CFGR_ADCPRE_1; ADC1; // (10) prescaler by 6 -> 72/6 = 12Mhz
	
	
	//scan mode and resolution (resolution of blue pill is fixed at 12 bit)
	ADC1->CR1 |= ADC_CR1_SCAN; //enable scan mode
	
	
	//set the continous Conversion, EOC, and DAta Aligment in COntrol Register 2 (CR2)
	ADC1->CR2 |= ADC_CR2_CONT;//continous conversion mode
	//f103c8t6 don't have EOCS (End of conversion selection, it setup automatively on this board
	ADC1->CR2 |= ADC_CR2_ALIGN;// data alignment (RIGHT)
	//Right when process all 12 bit data
	//left when process a part of 12 bit data
	
	
	//set the Sampling time for the channels in ADC SMPRx (Using channel 0 and 1)
	ADC1->SMPR2 |= ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP1_2; //(100) 41.5 cycles -> Total conversion time is 4.5us (channel 1 and 2)
	
	
	//set the regular channel sequence length in ADC_SQR1
	ADC1->SQR1 |= ADC_SQR1_L_0; //(001) total number of conversions in the regular channel (2)
	
	//Set the respective GPIO Pins in the analog Mode
	//pin A1
	GPIOA->CRL &= ~(GPIO_CRL_MODE1); //input mode
	GPIOA->CRL &= ~(GPIO_CRL_CNF1); // (00) analog mode
	//pin A2
	GPIOA->CRL &= ~(GPIO_CRL_MODE2); //input mode
	GPIOA->CRL &= ~(GPIO_CRL_CNF2); // (00) analog mode
	
}


void ADC_Enable(void)
{
	/***************step to follow***************
	1. Enable the ADC by setting ADON bit in CR2
	2. Wait for ADC to stabilize (approx 10us for f4 in video, but blue pill max is 1us)
	********************************************/
	ADC1->CR2 |= ADC_CR2_ADON; //enable ADC
	
	uint32_t delay = 10000;
	while(delay--); //wait for 1us to stablilize
}

void ADC_Start(int channel)
{
	/*************step to follow*************
	1. set the channel Sequence in the SQR register 
	2. Clear the Status registerr
	3. Start the conversion by setting the SWSTART bit in CR2
	******************************************/
	
	//keep one channel in the sequence at a time
	ADC1->SQR3 = 0; //reset the bits
	ADC1->SQR3 |= (channel<<0); //bring the channel to the 1th conversion in regular sequence
	ADC1->CR2 |= ADC_CR2_EXTSEL_0 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_2; // (000) select is as the external trigger source with the EXTSEL bits (value of 0b111)
	ADC1->CR2 |= ADC_CR2_SWSTART; //start conversion of the regular channel
	ADC1->CR2 |= ADC_CR2_ADON; //enable ADC
}

void ADC_WaitForConv(void)
{
	/*******************
	the EOC flag will be set, once the conversion is finished
	********************/
	while(!(ADC1->SR & ADC_SR_EOC)); //wait for the EOC flag to be set
}

uint16_t ADC_GetVal(void)
{
	return ADC1->DR; //read the data register 
}

void ADC_Disable(void)
{
	ADC1->CR2 &= ~ADC_CR2_ADON; //disble the ADC (ADON)
}

uint16_t ADC_VAL[2] = {0,0};

int main(void)
{
	SysClockConfig();
	ADC_Init();
	ADC_Enable();
	
	while(1)
	{
		ADC_Start(1);
		ADC_WaitForConv();
		ADC_VAL[0] = ADC_GetVal();
		
		ADC_Start(2);
		ADC_WaitForConv();
		ADC_VAL[1] = ADC_GetVal();
		
	}
	
}
