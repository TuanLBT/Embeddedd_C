#include "S32K144.h"

void PORT_init (void);
void SOSC_init_8MHz(void);
void SPLL_init_160MHz(void);
void NormalRUNmode_80MHz(void);
void FLEXCAN0_init(void);
void FLEXCAN0_receive_msg (void);
void FLEXCAN0_transmit_msg (void);

/*ADC:
Potential on node A, node A send data of Potential

Node B read value send from node A, use that value for PWM on node B
*/

void init_ADC0(void);
uint32_t read_ADC(void);
void init_EPWM(void);
void change_EPWM(uint32_t ADC_value);

static uint32_t RxCODE; /* Received message buffer code */
static uint32_t RxID; /* Received message ID */
static uint32_t RxLENGTH; /* Received message number of data bytes */
static uint32_t RxDATA[2]; /* Received message data (2 words) */
static uint32_t RxTIMESTAMP; /* Received message time */

static uint32_t value_ADC = 0;





int main(void){
	
}