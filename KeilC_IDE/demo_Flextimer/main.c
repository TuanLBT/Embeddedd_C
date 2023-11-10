#include "S32K144.h"

/*define variable start */
#define ChanPOL0		0x01
#define ChanPOL1		0x02
#define ChanPOL2		0x04
#define ChanPOL3		0x08
#define ChanPOL4		0x10
#define ChanPOL5		0x20
#define ChanPOL6		0x40
#define ChanPOL7		0x80
static uint32_t CurrentCaptureVal = 0;
static uint32_t PriorCaptureVal = 0;
static uint32_t DeltaCapture = 0;
/*define variable end */




/*function declare here start*/
void Init_Flextimer0(void);
void start_FTM0_counter (void);
void PORT_init (void);
void Init_OSC_8MHZ(void);
void Init_PLL_160MHZ(void);
void NormalRUNmode_80MHz (void);
void FTM0_CH0_OC_init(void);
void FTM0_CH0_output_compare(void);
void FTM0_CH1_EPWM_init(void);
void FTM0_CH6_IC_init(void);
void FTM0_CH6_input_capture(void);
/*function declare end*/



int main(void)
{
	Init_OSC_8MHZ();
	Init_PLL_160MHZ();
	NormalRUNmode_80MHz();
	Init_Flextimer0();
	//FTM0_CH0_OC_init();
	FTM0_CH1_EPWM_init();
	PORT_init();
	start_FTM0_counter();
	while(1)
	{
		//FTM0_CH0_output_compare();
	}
}

void Init_Flextimer0 (void){
	/*Disable the clock for configuration (CGC bit).*/
	PCC->PCCn[PCC_FTM0_INDEX] |= 0 << 30; //CGC bit = 0  - disable the clock
	
	/*configure the source clock for module FTM0 (PCS bit)*/
	PCC->PCCn[PCC_FTM0_INDEX] |= PCC_PCCn_PCS(6);// choose SPLLDIV1_CLK as source (5Mhz)
	
	/*Enable the clock for FTM0*/
	PCC->PCCn[PCC_FTM0_INDEX] |= 1 << 30; 
	
	/*Disable Write Protection for configuration (WPDIS)*/
	FTM0->MODE |= (1<<2); 
	
	/*configure the SC register*/
	FTM0->SC |= FTM_SC_PS(7) | // prescaler = 128, 5Mhz/128 = 39.0625kHz
	FTM_SC_CLKS(0)					| //00b - No clock selected. This in effect disables the FTM counter.
	(0<<5) 									| //0b - FTM counter operates in Up Counting mode
	//(0<<6)									| //Reload point interrupt is disabled
	//(0<<7)									| //reload flag, 2 bit nay lien quan toi nhau, không sử dụng nên không quan tâm 
	(0<<8)									| //time overflow interrupt disabled
	FTM_SC_PWMEN0_MASK 			| //chanel 0 output PWM enable
	FTM_SC_PWMEN1_MASK			 //chanel 1 output PWM enable
	;
	
	/*configuration of pair channel (0 and 1). Config in first 8 bits (Make it default)*/
	//FTM0->COMBINE |= 0x00000000; không xài nên khỏi ghi vô cũng được 
	
	/*config Polarity for 8 PWM channel (default is high)*/
	//FTM0->POL |= 0x00000000;
	
	/*config giá trị module của FMT counter - giá trị mà counter sẽ đếm tới tối đa rồi bắt đầu 1 chu kỳ đếm mới (lưu ý là chỉ có 16bit (35k tối đa)) */
	FTM0->MOD = 390 - 1; 
	/* FTM1 Period = MOD-CNTIN+0x0001 ~= 390 ctr clks (1 clock counter sẽ đếm được 390 giá trị */
	// 39.0625Khz / 390 = 1kHz per tick
}


void FTM0_CH0_OC_init(void) {
 FTM0->CONTROLS[0].CnSC = 0x00000014; /* FTM0 ch0: Output Compare, toggle output on match */
 /* CHIE (Chan Interrupt Ena)= 0 (default) */
 /* MSB:MSA (chan Mode Select)= 0b01, Output Compare */
 /* ELSB:ELSA (chan Edge or Level Select)= 0b01, toggle*/
 FTM0->CONTROLS[0].CnV= 3906; /* FTM0 ch 0 Compare Value= 3906 clks, ~100ms toggle*/
 FTM0->POL &= ~FTM_POL_POL0_MASK; /* FTM0 ch 0 polarity = 0 (Default, active high) */
}



void FTM0_CH0_output_compare(void){
	if (1==((FTM0->CONTROLS[0].CnSC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT)) 
		{
		 /* If chan flag is set */
		 FTM0->CONTROLS[0].CnSC &= ~FTM_CnSC_CHF_MASK; /* Clear flag: read reg then set CHF=0 */
			
			
		 if( FTM0->CONTROLS[0].CnV>=35156) /* If count at last value before end*/
			{ 
				FTM0->CONTROLS[0].CnV= 0 ; /* Update compare value: to 0*/
			}
		 else 
			{
				FTM0->CONTROLS[0].CnV= FTM0->CONTROLS[0].CnV + 3906 ; /* Update compare value: add 3906 to current value*/
			}
	 }
}





void FTM0_CH1_EPWM_init(void) {
 FTM0->CONTROLS[1].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
 /* CHIE (Chan Interrupt Ena) = 0 (default) */
 /* MSB:MSA (chan Mode Select)=0b10, Edge Align PWM*/
 /* ELSB:ELSA (chan Edge/Level Select)=0b10, low true */
 FTM0->CONTROLS[1].CnV = 385  ; /* FTM0 ch1 compare value (~2% duty cycle) */
	/*lưu ý là logic đèn của board này bị ngược*/
}

void FTM0_CH6_IC_init(void) {
 FTM0->CONTROLS[6].CnSC = 0x0000000C; /* FTM0 ch6: Input Capture rising or falling edge */
 /* CHIE (Chan Interrupt Ena) = 0 (default) */
 /* MSB:MSA (chan Mode Select)=0b00, Input Capture */
 /* ELSB:ELSA (ch Edge/Level Select)=0b11, rise or fall*/
}


void FTM0_CH6_input_capture(void) {
 if (1==((FTM0->CONTROLS[6].CnSC & FTM_CnSC_CHF_MASK)>>FTM_CnSC_CHF_SHIFT)) {
 /* If chan flag is set */
 FTM0->CONTROLS[6].CnSC &= ~FTM_CnSC_CHF_MASK; /* Clear flag: read reg then set CHF=0 */
 PriorCaptureVal = CurrentCaptureVal; /* Record value of prior capture */
 CurrentCaptureVal = FTM0->CONTROLS[6].CnV; /* Record value of current capture */
 DeltaCapture = CurrentCaptureVal - PriorCaptureVal;
 /* Will be 3906 clocks (100 msec) if connected to FTM0 CH0 */
 }
}


void PORT_init (void) {
 PCC->PCCn[PCC_PORTD_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTD */
 PCC->PCCn[PCC_PORTE_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTE */
 PORTE->PCR[8]|=PORT_PCR_MUX(2); /* Port E8: MUX = ALT2, FTM0CH6 */
 PORTD->PCR[15]|=PORT_PCR_MUX(2); /* Port D15: MUX = ALT2, FTM0CH0 */
 PORTD->PCR[16]|=PORT_PCR_MUX(2); /* Port D16: MUX = ALT2, FTM0CH1 */
}


void Init_OSC_8MHZ(void){
	/*initialize the desired SOCS divider*/
	SCG->SOSCDIV = 0x00000101; //Divided by 1
	
	/*configure range, high gain, reference*/
	SCG->SOSCCFG = SCG_SOSCCFG_EREFS(1) | SCG_SOSCCFG_HGO(0) | SCG_SOSCCFG_RANGE(3);
	
	/*Ensure the SOSC control and status register is unlock (the lock bit is 0)*/
	while(SCG->SOSCCSR & SCG_SIRCCSR_LK_MASK);
	
	/*enable the oscillator*/
	SCG->SOSCCSR=0x00000001;
		
		/*wait SOSC to be valid (valid bit is 1)*/
	while(!(SCG->SOSCCSR & SCG_SIRCCSR_SIRCVLD_MASK)){}
}


void Init_PLL_160MHZ(void){
	/*ensure SPLL is disble to allow configuration*/
	SCG->SPLLCSR = 0x00000000;
	
	/*Initialize CLK source, PLL divider, PLL multiplier*/
	/*
	-> MULT +16 = 40 for PREDIV + 1 = 1;
	*/
	SCG->SPLLCFG = 0x00180000;
	
	/*Initialize desired SPLL dividers, SPLLDIV1 : 32 */
	SCG->SPLLDIV = SCG_SPLLDIV_SPLLDIV1(6);//
	
	/*Ensure SPLLCSR unlocked*/
	while( (SCG->SPLLCSR &  SCG_SPLLCSR_LK_MASK) ) {}
		
	/*Enable SPLL*/
	SCG->SPLLCSR |= SCG_SPLLCSR_SPLLEN_MASK;
		
	/*wait for SPLL valid*/
	while( !(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK) ) {}
}



void start_FTM0_counter (void) {
 FTM0->SC |= FTM_SC_CLKS(3);
 /* Start FTM0 counter with clk source = external clock (PLLDIV1_CLK)*/
}



void NormalRUNmode_80MHz (void) { /* Change to normal RUN mode with 8MHz SOSC, 80 MHz PLL*/
 SCG->RCCR=SCG_RCCR_SCS(6) /* PLL as clock source*/
 |SCG_RCCR_DIVCORE(1) /* DIVCORE=1, div. by 2: Core clock = 160/2 MHz = 80 MHz*/
 |SCG_RCCR_DIVBUS(1) /* DIVBUS=1, div. by 2: bus clock = 40 MHz*/
 |SCG_RCCR_DIVSLOW(2); /* DIVSLOW=2, div. by 3: SCG slow, flash clock= 26 2/3 MHz*/
 while (((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT ) != 6) {}
 /* Wait for sys clk src = SPLL */
}
