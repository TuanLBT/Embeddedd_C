#include "S32K144.h" /* include peripheral declarations S32K144 */

static int idle_counter = 0; /* main loop idle counter */
static int lpit0_ch0_flag_counter = 0; /* LPIT0 chan 0 timeout counter */
static int PORTC_flag_counter = 0; /* PORTC interrupt counter */

void LPIT0_Ch0_IRQHandler (void);
void PORTC_IRQHandler(void);

void NVIC_init_IRQs_LPIT0 (void);
void NVIC_init_IRQs_PORTC (void);
void PORT_init (void);
void LPIT0_init (void);
void SOSC_init_8MHz(void);
void SPLL_init_160MHz(void);

void NormalRUNmode_80MHz (void);

int main(void) {
  /* Configure ports */
	PORT_init();
 SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
 SPLL_init_160MHz(); /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
 NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
	NVIC_init_IRQs_LPIT0(); /* Enable LPIT0 interrupts and priorities */
 LPIT0_init(); /* Initialize PIT0 for 1 second timeout */
	
 NVIC_init_IRQs_PORTC(); /* Enable PORTC interrupts and priorities */
	
 while(1) {
 idle_counter++;
 }
}





/*Start code interrupt vector handle*/
void LPIT0_Ch0_IRQHandler (void) {
 LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
 /* Perform read-after-write to ensure flag clears before ISR exit */
 lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
 PTD->PTOR |= 1<<16; /* Toggle output on port D16 (blue LED) */
}


void PORTC_IRQHandler(void)
{
	PORTC->ISFR |= PORT_PCR_ISF_MASK; //clear PORTC flag 
	//PORTC->PCR[n] |= 1<<24; interrupt on specific pin n th
	PORTC_flag_counter++;
	PTD->PTOR |= 1<<0;/* Toggle output on port D0 (blue LED) */
}


/*End code interrupt vector handle*/

void NVIC_init_IRQs_LPIT0 (void) {
	/***********step followw***************************/
	
	//1. watch the S32K1xx_[module]_INT_mapping.xlsm table for the following vector table using
	/*
	Vì đây là LPIT0 nên theo manual thì bit field của thanh ghi cấu hình sẽ là:
	
	NVICISER1, NVICICER1, NVICISPR1, NVICICPR1, NVICIABR1 bit location =
	IRQ mod 32 = 16 (48 % 32)
	
• NVICISER1[16]
• NVICICER1[16]
• NVICISPR1[16]
• NVICICPR1[16]
• NVICIABR1[16]
	
	NVICIPR12 bitfield starting location = 8 × (IRQ mod 4) + 4 = 8 x 0 + 4 = 4
• NVICIPR12[7:4]
	
	*/
	
 S32_NVIC->ICPR[1] = 1 << (48 % 32); /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
 S32_NVIC->ISER[1] = 1 << (48 % 32); /* IRQ48-LPIT0 ch0: enable IRQ */
 S32_NVIC->IP[48] =10; /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}

void NVIC_init_IRQs_PORTC (void) 
{
	S32_NVIC->ICPR[1] = 1 << (61 % 32); //clr any pending IRQ
	S32_NVIC->ISER[1] = 1 << (61 % 32); // Enable IRQ
	S32_NVIC->IP[61] =13; /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}




void PORT_init (void) {
 PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
 PTD->PDDR |= 1<<0; /* Pin D0: Data Direction= output */
 PTD->PDDR |= 1<<16; /* Pin D0: Data Direction= output */
 PORTD->PCR[0] |= 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
 PORTD->PCR[16] |= PORT_PCR_MUX(1);
	
	//Port C configuration for interreupt
	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;// Enable clock for PORT C 
	PTC->PDDR |= 0<<12;
	PORTC->PCR[12] |= PORT_PCR_MUX(1); // Port C: MUX = ALT1, GPIO
	PORTC->PCR[12] |= PORT_PCR_IRQC(9); //ISF flag and Interrupt on rising-edge

}
void LPIT0_init (void) {
 PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(1); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
 PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
	
	
	
 LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
 /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
/* SW_RST=0: SW reset does not reset timer chans, regs */
 /* M_CEN=1: enable module clk (allow writing other LPIT0 regs) */
 LPIT0->MIER = 0x00000001; /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
 LPIT0->TMR[0].TVAL = 8000000; /* Chan 0 Timeout period: 80M clocks */
 LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
 /* CHAIN=0: channel chaining is disabled */
/* MODE=0: 32 periodic counter mode */
/* TSOT=0: Timer decrements immediately based on restart */
/* TSOI=0: Timer does not stop after timeout */
/* TROT=0 Timer will not reload on trigger */
/* TRG_SRC=0: External trigger source */
/* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}




void SOSC_init_8MHz(void) {
 SCG->SOSCDIV=0x00000101; /* SOSCDIV1 & SOSCDIV2 =1: divide by 1 */
 SCG->SOSCCFG=SCG_SOSCCFG_EREFS(1) | SCG_SOSCCFG_HGO(0) | SCG_SOSCCFG_RANGE(3);//SCG_SOSCCFG_EREFS(1) | SCG_SOSCCFG_HGO(0) | SCG_SOSCCFG_RANGE(3);//0x00000024; /* Range=2: Medium freq (SOSC between 1MHz-8MHz)*/
 /* HGO=0: Config xtal osc for low power */
/* EREFS=1: Input is external XTAL */
 while(SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK); /* Ensure SOSCCSR unlocked */
 SCG->SOSCCSR=0x00000001; /* LK=0: SOSCCSR can be written */
 /* SOSCCMRE=0: OSC CLK monitor IRQ if enabled */
/* SOSCCM=0: OSC CLK monitor disabled */
/* SOSCERCLKEN=0: Sys OSC 3V ERCLK output clk disabled */
/* SOSCLPEN=0: Sys OSC disabled in VLP modes */
/* SOSCSTEN=0: Sys OSC disabled in Stop modes */
/* SOSCEN=1: Enable oscillator */
 while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK)); /* Wait for sys OSC clk valid */
}


void SPLL_init_160MHz(void) {
 while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK); /* Ensure SPLLCSR unlocked */
 SCG->SPLLCSR = 0x00000000; /* SPLLEN=0: SPLL is disabled (default) */
 SCG->SPLLDIV = 0x00000302;//SCG_SPLLDIV_SPLLDIV1(1) | SCG_SPLLDIV_SPLLDIV2(2);  // /* SPLLDIV1 divide by 2; SPLLDIV2 divide by 4 */
 SCG->SPLLCFG = SCG_SPLLCFG_PREDIV(0) | SCG_SPLLCFG_MULT(23) ;//SCG_SPLLCFG_PREDIV(0) | SCG_SPLLCFG_MULT(2) ;//0x00180000 /* PREDIV=0: Divide SOSC_CLK by 0+1=1 */
 /* MULT=24: Multiply sys pll by 4+24=40 */
/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz */
 while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK); /* Ensure SPLLCSR unlocked */
 SCG->SPLLCSR = 0x00000001; /* LK=0: SPLLCSR can be written */
 /* SPLLCMRE=0: SPLL CLK monitor IRQ if enabled */
/* SPLLCM=0: SPLL CLK monitor disabled */
/* SPLLSTEN=0: SPLL disabled in Stop modes */
/* SPLLEN=1: Enable SPLL */
 while(!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK)); /* Wait for SPLL valid */
}
void NormalRUNmode_80MHz (void) { /* Change to normal RUN mode with 8MHz SOSC, 80 MHz PLL*/
 SCG->RCCR=SCG_RCCR_SCS(1) /* SOCS as clock source (8Mhz)*/
 |SCG_RCCR_DIVCORE(0) /* DIVCORE=0, div. by 1: Core clock = 8 MHz*/
 |SCG_RCCR_DIVBUS(0) /* DIVBUS=0, div. by 1: bus clock = 8 MHz*/
 |SCG_RCCR_DIVSLOW(1); /* DIVSLOW=1, div. by 2: SCG slow, flash clock= 4 MHz*/
 while (((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT ) != 1) {}
 /* Wait for sys clk src = SPLL */
}











