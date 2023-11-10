#include "S32K144.h"

static int count=0;

void GPIO_configure(void);


/*Ấn nút 1 lần nhảy 1 màu RBG, và lặp lại*/

int main(void)
{
	GPIO_configure();
	while(1)
	{
		if((PTC->PDIR & (1<<12))) //check if button was press
		{
			if(count > 3) 
				{count = 1;}
			else 
				count++;
			while((PTC->PDIR & (1<<12))) //manual filter for button
			{}
		}
			
		switch (count)
    {
			case 0:
				break;
    	case 1:
			PTD->PCOR |= (1<<15);
			PTD->PSOR |= (1<<16);
			PTD->PSOR |= (1<<0);
    		break;
    	case 2:
			PTD->PCOR |= (1<<16);
			PTD->PSOR |= (1<<15);
			PTD->PSOR |= (1<<0);
    		break;
    	case 3:
			PTD->PCOR |= (1<<0);
			PTD->PSOR |= (1<<16);
			PTD->PSOR |= (1<<15);
    		break;
			
			/* sử dụng thanh ghi PSOR để set ouput mức cao (đèn tắt) 
			và PCOR để output mức thấp (đèn sẽ sáng)*/
    }
	}
}

void GPIO_configure(void)
{
	/*Lưu ý: đèn led khi output mặc định sẽ là mức output 0, nghĩa là nếu set output sẽ mặc định sáng (do nguồn VDD ở 
		ngoài mà mức logic output mặc định là 0*/
	
	
	
	/*PCC_PORTB_INDEX define giá trị là 74, nghĩa là từ địa chỉ base (0x4000) 
	nó sẽ nhảy đến index thứ 74 theo số nguyên của PCC index */
	
	//nguồn xung sử dụng cho GPIO module đó là SYS_CLOCK 
	PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK; // enable clock for port C
	PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK; // enable clock for port D 
	
	PORTD->PCR[15] |= PORT_PCR_MUX(1); //001 of mux is GPIO 
	PTD->PDDR |= 1<<15; //pin 15 as output //led red
	
	PORTD->PCR[0] |= PORT_PCR_MUX(1); //001 of mux is GPIO 
	PTD->PDDR |= 1<<0; //pin 0 as output //led green 
	
	PORTD->PCR[16] |= PORT_PCR_MUX(1); //001 of mux is GPIO 
	PTD->PDDR |= 1<<16; //pin 16  as output //led blue 
	

	
	//button
	PORTC->PCR[12] |= PORT_PCR_MUX(1); //001 of mux is GPIO 
	PTC->PDDR |= ~(1<<12); //switch 0, input (default) 
	
	//passive input filter for digital input configuration
	//PORTC->PCR[12] |= PORT_PCR_PFE_MASK; //ENABLE FILTER
	
			PTD->PSOR |= (1<<15);
			PTD->PSOR |= (1<<16);
			PTD->PSOR |= (1<<0);
	
}