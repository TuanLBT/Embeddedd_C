#INCLUDE <16F887.H>
#USE DELAY(CLOCK=20M)
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#INCLUDE <LCD_4chan.C>

unsigned int16 RPM=0, PULSE=0 /**, BDT=0**/;

/**void dele_1s(){
   do{
      IF (TMR0IF==1) 
      { 
         TMR0IF=0; 
         SET_TIMER0(61); 
         BDT++;
      }
   }
   while(BDT<100);
}**/


void main()
{
   SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 ); 
   SET_TIMER1(0);
   /**SETUP_TIMER_0(T0_INTERNAL | T0_DIV_256); 
   SET_TIMER0(61);**/ 
   SET_TRIS_D(0X00);
   LCD_Init();
   LCD_Gotoxy(1,0);
   LCD_PutChar("RPM:");
   LCD_Gotoxy(0,0);
   LCD_PutChar("PULSE:");
   
   while(TRUE)
   {
      SET_TIMER1(0);
      //dele_1s();
      delay_ms(1000);
      PULSE = GET_TIMER1();
      RPM = (PULSE)*60/24;
      LCD_Gotoxy(0,6);
      LCD_PutChar(PULSE/10 +0x30);
      LCD_PutChar(PULSE%10 +0x30);
      LCD_Gotoxy(1,4);
      LCD_PutChar(RPM/10 +0x30);
      LCD_PutChar(RPM%10 +0x30);
      //BDT=0;
   }
}
