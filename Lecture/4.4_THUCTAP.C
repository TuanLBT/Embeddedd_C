#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR1IF = 0x0C.0
UNSIGNED INT16 I, J,T,KQADC,n,BDT;
VOID LCD()
{T = 0; 
              T=READ_ADC();
               DELAY_MS(1);
               T= T /2.046;
   LCD_Gotoxy(0,7);
   LCD_PutChar(T/10 + 0X30);//HANGCHUC
   LCD_PutChar(T%10 +0X30);//DONVI
}
VOID SOPHONG()
{
   LCD_Gotoxy(0,0);
   LCD_PutChar("ROOM");//HANGCHUC
   LCD_PutChar(n + 0X30);//HANGCHUC
}

VOID MAIN()
{
   BDT=0;
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   
   SET_TRIS_A(0XFF);
   SET_TRIS_B(0XFF);
   SET_TRIS_D(0x00); 
   LCD_Init();
   delay_ms(10); 
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(SAN0|SAN1|SAN2|SAN3|SAN4);

   WHILE(TRUE)
   {
         
      SET_ADC_CHANNEL(n);
      LCD();
      SOPHONG();
      IF (TMR1IF==1) //KHI TRAN THI GIA TRI CO NGAT SE LEN 1
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
         
          IF (BDT == 10)
          {n++;BDT =0;
          IF (n>=5)
          {n=0;}}
          
    
      }
   }
         
   
}
