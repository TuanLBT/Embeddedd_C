#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR0IF = 0x0B.2 
#BIT TMR1IF = 0x0C.0
#BIT TMR2IF = 0x0C.1

UNSIGNED INT16 DEM1=0,BDT=0,V,S;

VOID HIENTHISOXUNG()
{
   LCD_Gotoxy(0,0);
   LCD_PutChar("XUNG:");
   LCD_PutChar(DEM1/10+0X30);
   LCD_PutChar(DEM1%10+0X30);
   
}

VOID TINHTOCDO()
{
   S = DEM1;
   V = (FLOAT)(S*60.00*1000.00*5) / (300.00);
   LCD_Gotoxy(1,8);
   LCD_PutChar((V/1000)/100 +0X30);
   LCD_PutChar(((V/1000)/10)%10+0X30);
   LCD_PutChar((V/1000)%10+0X30);
   LCD_PutChar("RPM");
   SET_TIMER1(0);
}
VOID MAIN()
{
   SET_TRIS_D(0x00); SET_TRIS_C(0XFF);
   LCD_Init();
   delay_ms(10);  
   
   SETUP_TIMER_2(T2_DIV_BY_16, 255,16); //TU 131->255 LA  400uS, NHUNG QUA 16 LAN MOI NGAT => DINH THOI 6.4mS
   SET_TIMER2(130); 
   SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 );
   SET_TIMER1(0);
   
   WHILE(TRUE)
   {
      DEM1 = GET_TIMER1();
      LCD_Gotoxy(1,0);
      LCD_PutChar("SPEED:");
      IF (TMR2IF==1)
      {
         TMR2IF=0; SET_TIMER2(130); BDT++; //xuong day luu y: thoi gian BDT + 1 = 6.4mS x 2.
         IF (BDT== 78/5 ) //78 = 1 giay: 6.4ms x2 x 78
         {  
            BDT=0;
            TINHTOCDO();
         }
      }
   }
}

