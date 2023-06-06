
#include "RCC.h"







/*SETTING (1 TIMES)*/
void SysClockConfig(void)
{
	/*****Step follow to configguration of system clock**********
		1. ENABLE HSE and wait for the HSE to become ready
		2. set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
		3. configure the FLASH PREFETCH and the LATENCY Related Settings
		4. configure the PRESCALES HCLK, PCLK1, PCLK2
		5. configure the MAIN PLL
		6. enable the PLL and wait for it to become ready
		7. select the clock source and wait for it to be set
	
	*************************************************************/

	/*1. ENABLE HSE and wait for the HSE to become ready (In Clock control register (RCC_CR))*/
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); /*indicate the HSE crystal is on*/
	
	
	/*2.1 set the POWER ENABLE CLOCK and VOLTAGE REGULATOR (in APB1 peripheral clock enable register (RCC_APB1ENR)*/
	RCC->APB1ENR |= RCC_APB1ENR_PWREN; 
	/*2.2 set the VOLTAGE REGULATOR (in power control register (PWR_CR) BLue Pill dont have this so skip this part*/

	
	/*3. configure the FLASH PREFETCH and the LATENCY Related Settings (FLASH_ACR and*/
	FLASH->ACR |= FLASH_ACR_PRFTBS | FLASH_ACR_LATENCY_2;
	
	/*4. configure the PRESCALES HCLK, PCLK1, PCLK2 (RCC_CFGR)*/
	/* AHB prescaler */
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 
	/* AHB1 prescaler */
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	/* AHB2 prescaler */
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
	
	/*4. configure the MAIN PLL (RCC_PLLCFGR)*/
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9;

	/*6. enable the PLL and wait for it to become ready(RCC_CR)*/
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	/*7. select the clock source and wait for it to be set*/
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS) != (RCC_CFGR_SWS_PLL));
}


