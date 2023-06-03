#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR0IF = 0x0B.2 
#BIT TMR1IF = 0x0C.0
#BIT TMR2IF = 0x0C.1
#DEFINE ECHO PIN_E1
#DEFINE TR PIN_E2
UNSIGNED INT16 S, BDT=0;
VOID WAITFORPULSE()
{
      OUTPUT_LOW(TR);
      DELAY_MS(3000);
      
   
}
VOID HIENTHIKHIOANGCACH()
{
      LCD_Gotoxy(0,0);
      LCD_PutChar("distance:"); 
}
VOID TINHTOANKHOANGCACH()
{
         //V am thanh: 34300 cm/s
}
VOID MAIN()
{
   SET_TRIS_E(0X00);
   SETUP_TIMER_2(T2_DIV_BY_16, 255,16); //TU 131->255 LA  400uS, NHUNG QUA 16 LAN MOI NGAT => DINH THOI 6.4mS
   SET_TIMER2(130); 
   LCD_Init();
   delay_ms(10);
   HIENTHIKHIOANGCACH();
   WHILE (TRUE)
   {
      IF (TMR2IF==1)
         {
            TMR2IF=0; SET_TIMER2(130); 
            BDT++;
         }
   }
  
}
