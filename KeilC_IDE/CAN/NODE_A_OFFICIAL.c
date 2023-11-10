#include "S32K144.h" /* include peripheral declarations S32K144 */

#define NODE_A

/**************Function declaration start***************/
void PORT_init (void);
void SOSC_init_8MHz(void);
void SPLL_init_160MHz(void);
void NormalRUNmode_80MHz(void);
void FLEXCAN0_init(void);
void FLEXCAN0_receive_msg (void);
void FLEXCAN0_transmit_msg (void);
void init_ADC0(void);
uint32_t read_ADC(void);
void init_EPWM(void);
void change_EPWM(uint32_t ADC_value);

void PORTC_IRQHandler(void);
void NVIC_init_IRQs_PORTC (void);

void DELAY_MS(uint32_t delaytime);

/***************Function declaration end***************/






/**************Variable declaration start***************/
static uint8_t mode = 0;
static uint32_t dummy_timer=0;
static uint32_t RxCODE; /* Received message buffer code */
static uint32_t RxID; /* Received message ID */
static uint32_t RxLENGTH; /* Received message number of data bytes */
static uint32_t RxDATA[2]; /* Received message data (2 words) */
static uint32_t RxTIMESTAMP; /* Received message time */
static uint32_t value_ADC = 0;
/**************Variable declaration end***************/

/**************START CLOCK FUNCTION INIT***************/
void SOSC_init_8MHz(void){
	SCG->SOSCDIV |= SCG_SOSCDIV_SOSCDIV1(1)| SCG_SOSCDIV_SOSCDIV2(1); 
								//SOSCDIV1-2 (System OSC Clock Divide 1-2):	001 Divide by 1
								// with SOSC_CLK = 8MHz => SOSCDIV1_CLK = SOSCDIV2_CLK = 8MHz
								
	SCG->SOSCCFG |= SCG_SOSCCFG_EREFS(1)| SCG_SOSCCFG_HGO(0) | SCG_SOSCCFG_RANGE(3) ;
								//EREFS (External Reference Select) : 1 Internal crystal oscillator of OSC selected
								//HGO		(High Gain Oscillator Select):	0 Configure crystal oscillator for low-gain operation
								//RANGE	(System OSC Range Select)		:	11 High frequency range selected for the crystal oscillator
	
	SCG->SOSCCSR |= SCG_SOSCCSR_LK(0);  //LK (Lock Register):	0 Control Status Register can be written
	
	SCG->SOSCCSR |= SCG_SOSCCSR_SOSCEN(1); //SOSCEN	(System OSC Enable):	1 System OSC is enabled
	
	while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK)); 
								// SOSCVLD(System OSC Valid)	:			0 System OSC is not enabled or clock is not valid
}
void SPLL_init_160MHz(void){
	SCG->SPLLCSR |= SCG_SPLLCSR_SPLLEN(0);	//SPLLEN (System PLL Enable)	:	0 System PLL is disabled
	
	SCG->SPLLDIV |= SCG_SPLLDIV_SPLLDIV1(1)| SCG_SPLLDIV_SPLLDIV2(1);	
								//SPLLDIV1-2 (System PLL Clock Divide 1-2)	:	001 Divide by 1
								 
	SCG->SPLLCFG = SCG_SPLLCFG_MULT(24) | SCG_SPLLCFG_PREDIV(0); 
								//MULT (System PLL Multiplier)	:	11000	=> mult = 24+16 = 40 
								//PREDIV (PLL Reference Clock Divider)	:	000 => prediv = 0+1 = 1
								
	SCG->SPLLCSR |= SCG_SPLLCSR_LK(0); //LK (Lock Register): 0 Control Status Register can be written.
	
	SCG->SPLLCFG &= ~(1u<<0);  //SOURCE (Clock Source)	: 	0 System OSC (SOSC)
	
	//select source SOSC_CLK for system PLL => VCO_CLK: 8Mhz*40/1 = 320MHz => SPLL_CLK = 320MHz/2 = 160MHz
	//with SPLL_CLK = 160MHz => SPLLDIV1_CLK = SPLL_CLK/1 = 160MHz
														//SPLLDIV2_CLK = SPLL_CLK/1 = 160MHz
	
	SCG->SPLLCSR |= SCG_SPLLCSR_SPLLEN(1);	//SPLLEN(System PLL Enable):	1 System PLL is enabled
	
	while (!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK));
									//SPLLVLD (System PLL Valid):	0 System PLL is not enabled or clock is not valid
						
}

void NormalRUNmode_80MHz(void){
	SCG->RCCR = SCG_RCCR_DIVSLOW(2) | SCG_RCCR_DIVBUS(1) | SCG_RCCR_DIVCORE(1) | SCG_RCCR_SCS(6);
						//DIVSLOW (Slow Clock Divide Ratio):	0010 Divide-by-3
						//DIVBUS (Bus Clock Divide Ratio):	0001 Divide-by-2
						//DIVCORE (Core Clock Divide Ratio):	0001 Divide-by-2
						//SCS (System Clock Source):	0110 System PLL (SPLL_CLK)
	
	//with SPLL_CLK = 160MHz 	=> CORE_CLK = SYS_CLK = 160MHz/2 = 80MHz
													//=> BUS_CLK	=	 80MHz/2 = 40MHz
													//=>FLASH_CLK = 80MHz/3 = 26.67MHz (max)
	
	while(((SCG->CSR & SCG_CSR_SCS_MASK)>>SCG_CSR_SCS_SHIFT)!=6);
						// waiting for system clock source = SPLL_CLK
}
/**************END CLOCK FUNCTION INIT***************/

/**************START PORT FUNCTION INIT***************/
void PORT_init (void){
	
	
	
	
	/*GPIO GREEN LED*/
//	PCC->PCCn[PCC_PORTD_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTD */
//	PORTD->PCR[15] = 0x00000100; /* Port D15: MUX = GPIO (to red LED) */
//  PTD->PDDR |= 1<<15; /* Port D16: Data direction = output */
	
	
	
	
	
	
	/*Port C configuration for interreupt (Pin 12, 13 - Button 0, 1 - SW2, SW3)*/
	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;// Enable clock for PORT C 
	//SW2
	PTC->PDDR |= 0<<12;
	PORTC->PCR[12] |= PORT_PCR_MUX(1); // Port C: MUX = ALT1, GPIO
	PORTC->PCR[12] |= PORT_PCR_IRQC(9); //ISF flag and Interrupt on rising-edge
	//SW3
	PTC->PDDR |= 0<<13;
	PORTC->PCR[13] |= PORT_PCR_MUX(1); // Port C: MUX = ALT1, GPIO
	PORTC->PCR[13] |= PORT_PCR_IRQC(9); //ISF flag and Interrupt on rising-edge
	
	
	
	
	
	/**************CAN_TX_RX***************/
	PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORTE */
	PORTE->PCR[4] |= PORT_PCR_MUX(5); /* Port E4: MUX = ALT5, CAN0_RX */
	PORTE->PCR[5] |= PORT_PCR_MUX(5); /* Port E5: MUX = ALT5, CAN0_TX */
	
	
	
	
}
void init_EPWM(void){
	PCC->PCCn[PCC_PORTD_INDEX] 	|= 	PCC_PCCn_CGC_MASK; // enable clock for PORTD
	
	PCC->PCCn[PCC_FTM0_INDEX] 	|=	PCC_PCCn_PCS(1)	|	PCC_PCCn_CGC_MASK; //choose SOSCDIV1_CLK, enable clock

	PORTD->PCR[16] |= PORT_PCR_MUX(2); //alt2: FTM0_CH1, GREEN LED
	PORTD->PCR[15] |= PORT_PCR_MUX(2); //alt2: FTM0_CH0, RED LED
	
	FTM0->MODE 	|=	FTM_MODE_WPDIS(1); //DISABLE protect write
	
	while(!((FTM0->MODE&FTM_MODE_WPDIS(1))>>FTM_MODE_WPDIS_SHIFT)); // ensure disable protect write
	
	/*************EPWM****************/
	FTM0->QDCTRL |= FTM_QDCTRL_QUADEN(0); // quadrature decore mode disable
	
	FTM0->COMBINE |= FTM_COMBINE_MCOMBINE0(0)| FTM_COMBINE_COMBINE0(0)  | FTM_COMBINE_DECAPEN0(0);//|FTM_COMBINE_COMP0_MASK ;
	
	FTM0->SC |= FTM_SC_CPWMS(0); // counter up
	
	
	FTM0->CONTROLS[1].CnSC |= FTM_CnSC_MSB_MASK;
	FTM0->CONTROLS[0].CnSC |=  FTM_CnSC_MSB_MASK;
	/*********************************/
	
	FTM0->CNTIN = FTM_CNTIN_INIT(0); // counter init: 0
	
	FTM0->MOD		= FTM_MOD_MOD(1000-1);
	//chan1 
	FTM0->CONTROLS[1].CnSC |=  FTM_CnSC_ELSB_MASK| FTM_CnSC_ELSA_MASK;

	FTM0->CONTROLS[1].CnV = FTM_CnV_VAL(0); // 0%
	
	//chan0
	FTM0->CONTROLS[0].CnSC |=  FTM_CnSC_ELSB_MASK| FTM_CnSC_ELSA_MASK;

	FTM0->CONTROLS[0].CnV = FTM_CnV_VAL(0); // 0%
	
	
	FTM0->CNT = 0; //reset counter
	
	FTM0->DEADTIME = FTM_DEADTIME_DTPS(3) | FTM_DEADTIME_DTVAL(7);
	
	FTM0->SC	|= FTM_SC_CLKS(3)| FTM_SC_PS(3) | FTM_SC_PWMEN1_MASK | FTM_SC_PWMEN0_MASK; //choose SOSCDIV1 , prescale: 8 	8MHz : 8 = 1MHz, CHOSE PWM CHANNEL 1
	
	//=> 10kHz

}

/**************END PORT FUNCTION INIT***************/

/**************START BUTTON INTERRUPT FUNCTION INIT***************/
void PORTC_IRQHandler(void) {//interrupt handler of port C
	//PORTC->ISFR |= PORT_PCR_ISF_MASK; //clear PORTC flag 
	if (PORTC->PCR[12] >>24){
		PORTC->PCR[12] |= 1<<24; //interrupt on specific pin n th
		//PTD->PSOR |= 1<<16;/* Make the GREEN LED go off */
		mode = 1;
	}
	else if(PORTC->PCR[13] >>24){
		PORTC->PCR[13] |= 1<<24; //interrupt on specific pin n th
		//PTD->PCOR |= 1<<16;/* Make the GREEN LED go on */
		mode = 0;
	}
	
}
void NVIC_init_IRQs_PORTC (void) {
	S32_NVIC->ICPR[1] = 1 << (61 % 32); //clr any pending IRQ
	S32_NVIC->ISER[1] = 1 << (61 % 32); // Enable IRQ
	S32_NVIC->IP[61] =13; /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}
/**************END BUTTON INTERRUPT FUNCTION INIT***************/

void change_EPWM(uint32_t ADC_value){
		FTM0->CONTROLS[1].CnV = FTM_CnV_VAL(ADC_value); // 50%
}

void init_ADC0(void){
	PCC->PCCn[PCC_ADC0_INDEX] &= ~PCC_PCCn_CGC_MASK; // disable to configure
	
	PCC->PCCn[PCC_ADC0_INDEX] = PCC_PCCn_CGC_MASK | PCC_PCCn_PCS(1); //enable clock for ADC0; 		 Choose source SOSCDIV2_CLK: 8MHz
	PCC->PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; // enable clock for PortD (use PTC14 to read ADC signal)

	PORTC->PCR[14] |= PORT_PCR_MUX(0)|PORT_PCR_PFE(0); // alt0 : ADC0; 		PFE: 1 enable passive filter
	
	ADC0->CFG1 |= ADC_CFG1_ADICLK(0)|ADC_CFG1_MODE(1)|ADC_CFG1_ADIV(0); //ADICLK: 0 choose alternate clock 1;	MODE: 1 12 bit;	ADIV:0 : div 1
	
	ADC0->CFG2 |= ADC_CFG2_SMPLTS(13); //sample time: 13 clock cycle
	
	ADC0->SC2 = 0x00000000; //all default
	
	ADC0->SC3 = ADC_SC3_ADCO(1)|ADC_SC3_AVGE(1);
	
	ADC0->SC1[0] = ADC_SC1_ADCH(12); //ADCH: choose external channel 12
}
uint32_t read_ADC(void){
	
	uint32_t ADC_value = 0;

	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK)); //waiting to complete
	
	ADC_value = ADC0->R[0];
	ADC_value = 1000*(ADC_value)/0xFFF;
	
	return ADC_value;
}


void FLEXCAN0_init(void){
		#define MSG_BUF_SIZE 4 /* Msg Buffer Size. (CAN 2.0AB: 2 hdr + 2 data= 4 words) */
		 uint32_t i=0;
		 PCC->PCCn[PCC_FlexCAN0_INDEX] |= PCC_PCCn_CGC_MASK; /* CGC=1: enable clock to FlexCAN0 */
		 CAN0->MCR |= CAN_MCR_MDIS_MASK; /* MDIS=1: Disable module before selecting clock */
		 CAN0->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK; /* CLKSRC=0: Clock Source = oscillator (8 MHz) */
		 CAN0->MCR &= ~CAN_MCR_MDIS_MASK; /* MDIS=0; Enable module config. (Sets FRZ, HALT)*/
		 while (!((CAN0->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT)) {}
		 /* Good practice: wait for FRZACK=1 on freeze mode entry/exit */
		 CAN0->CTRL1 = 0x00DB0006; /* Configure for 500 KHz bit time */
		 /* Time quanta freq = 16 time quanta x 500 KHz bit time= 8MHz */
		 /* PRESDIV+1 = Fclksrc/Ftq = 8 MHz/8 MHz = 1 */
		/* so PRESDIV = 0 */
		/* PSEG2 = Phase_Seg2 - 1 = 4 - 1 = 3 */
		/* PSEG1 = PSEG2 = 3 */
		/* PROPSEG= Prop_Seg - 1 = 7 - 1 = 6 */
		/* RJW: since Phase_Seg2 >=4, RJW+1=4 so RJW=3. */
		/* SMP = 1: use 3 bits per CAN sample */
		/* CLKSRC=0 (unchanged): Fcanclk= Fosc= 8 MHz */
		 for(i=0; i<128; i++ ) { /* CAN0: clear 32 msg bufs x 4 words/msg buf = 128 words*/
		 CAN0->RAMn[i] = 0; /* Clear msg buf word for avoid unwanted data in buffer  */
		 }
		 for(i=0; i<16; i++ ) { /* In FRZ mode, init CAN0 16 msg buf filters */
		 CAN0->RXIMR[i] = 0xFFFFFFFF; /* Check all ID bits for incoming messages (cái này dạng như xác định xem 
																		muốn so sánh bao nhiêu bit của cái ID, trường hợp này là so sánh hết 32bit của 
																		đoạn ID trong message
																	) */
		 }
		 CAN0->RXMGMASK = 0x1FFFFFFF; /* Global acceptance mask: check all ID bits */
		 CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] = 0x04000000; /* Msg Buf 4, word 0: Enable for reception */
		 /* EDL,BRS,ESI=0: CANFD not used */
		/* CODE=4: MB set to RX inactive */
		/* IDE=0: Standard ID */
		 /* SRR, RTR, TIME STAMP = 0: not applicable */
		 CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x02c00000; /* Msg Buf 4, word 1: Standard ID = 0xB0 (NODE A receive msg with ID = 0xB0)*/
		 /* PRIO = 0: CANFD not used */
		 CAN0->MCR = 0x0000001F; /* Negate FlexCAN 1 halt state for 32 MBs */
		 while ((CAN0->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT) {}
		 /* Good practice: wait for FRZACK to clear (not in freeze mode) */
		 while ((CAN0->MCR & CAN_MCR_NOTRDY_MASK) >> CAN_MCR_NOTRDY_SHIFT) {}
		 /* Good practice: wait for NOTRDY to clear (module ready) */
}

void FLEXCAN0_transmit_msg (void){ /* Assumption: Message buffer CODE is INACTIVE */
			 CAN0->IFLAG1 = 0x00000001; /* Clear CAN 0 MB 0 flag without clearing others*/
			 CAN0->RAMn[ 0*MSG_BUF_SIZE + 2] = value_ADC; /* MB0 word 2: data word 0 */
			 CAN0->RAMn[ 0*MSG_BUF_SIZE + 3] = 0; /* MB0 word 3: data word 1 */
			 CAN0->RAMn[ 0*MSG_BUF_SIZE + 1] =  0x02800000; /* MB0 word 1: Tx msg with STD ID 0xA0 */
			 CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C400000 | 8 <<CAN_WMBn_CS_DLC_SHIFT; /* MB0 word 0: */
			 /* EDL,BRS,ESI=0: CANFD not used */
			 /* CODE=0xC: Activate msg buf to transmit */
			/* IDE=0: Standard ID */
			/* SRR=1 Tx frame (not req'd for std ID) */
			 /* RTR = 0: data, not remote tx request frame*/
			/* DLC = 8 bytes */
}
void FLEXCAN0_receive_msg (void){
			 uint8_t j;
			 uint32_t dummy;
			 RxCODE = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & 0x07000000) >> 24; /* Read CODE field */
			 RxID = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK) >>CAN_WMBn_ID_ID_SHIFT ;
			 RxLENGTH =(CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK)>>CAN_WMBn_CS_DLC_SHIFT;
			 for (j=0; j<2; j++) { /* Read two words of data (8 bytes) */
			 RxDATA[j] = CAN0->RAMn[ 4*MSG_BUF_SIZE + 2 + j];
			 }
			 RxTIMESTAMP = (CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] & 0x000FFFF);
			 dummy = CAN0->TIMER; /* Read TIMER to unlock message buffers */
			 CAN0->IFLAG1 = 0x00000010; /* Clear CAN 0 MB 4 flag without clearing others*/
			 if(dummy == 0){} /*disable the warning unused dummy variable*/
}
void DELAY_MS(uint32_t delaytime){
	while(delaytime){
		if (FTM0->SC & FTM_SC_TOF_MASK)
		{
			delaytime--; //1ms per tick
			/*clearing the TOF bit*/
			dummy_timer = FTM0->SC;					//1. Reading the SC register
			FTM0->SC &= ~FTM_SC_TOF_MASK;		//1. writing a 0 to the TOF bit
		}	
	}
}



int main(void)
{
	PORT_init();
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	NVIC_init_IRQs_PORTC();
	init_EPWM();
	init_ADC0();
	FLEXCAN0_init();
	while(1)
	{
		value_ADC = read_ADC();				//always update the potential value			
		if ((CAN0->IFLAG1 >> 4) & 1)  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
					{ 
				 FLEXCAN0_receive_msg (); /* Read message */
				 mode = 2; 								//go to mode 2 after read message
		}
		switch (mode)
    {
    	case 1: //CAN is transfering message
				FTM0->CONTROLS[1].CnV = FTM_CnV_VAL(0); 	//Green LEd off
				CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x09000000; //tell the buffer to abort transmitt 
				DELAY_MS(1000);																//DELAY for 1sec after abort
				FLEXCAN0_transmit_msg();											//begin transmitt message
    		break;
			case 2:
				FTM0->CONTROLS[1].CnV = FTM_CnV_VAL(0);					//Green LEd off
				FTM0->CONTROLS[0].CnV = FTM_CnV_VAL(RxDATA[0]); //PWM of RED LED is from the CAN MESSAGE
				break;
    	default:// stop CAN transmission, go to idle state
				FTM0->CONTROLS[1].CnV = FTM_CnV_VAL(1000); //green LED on after reset or stop tsansmitt
				FTM0->CONTROLS[0].CnV = FTM_CnV_VAL(0); //Red LED on after reset or stop tsansmitt
				CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x08000000; //tell the transmitt buffer to go INACTIVE
    		break;
    }
	}
}


