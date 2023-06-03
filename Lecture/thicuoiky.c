#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE UP PIN_A1
#DEFINE READ PIN_A0
#BIT TMR0IF = 0x0B.2 
#BIT TMR1IF = 0x0C.0
#BIT TMR2IF = 0x0C.1
SIGNED INT16 DEM=0,VAR,VAR1,VAR2,VAR4,VAR3;
VOID MAIN()
{
   SET_TRIS_A(0X07); SET_TRIS_C(0X00); SET_TRIS_E(0XFF);
   LCD_Init();
   delay_ms(10);
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(SAN7);
   SET_ADC_CHANNEL(7);
   SETUP_CCP1(CCP_PWM);
   setup_timer_2(T2_DIV_BY_16, 249, 1);
   SET_PWM1_DUTY(0);

   WHILE(TRUE)
   {
   IF (!INPUT(UP))
      {
         DELAY_MS (10);
         IF(!INPUT(UP))
            {
               DEM++;
               LCD_Gotoxy(1,7);
                     LCD_PutChar(DEM/10 + 0X30);
                     LCD_PutChar(DEM%10 + 0X30);
               IF (DEM>9){DEM=0;}
               IF (DEM%2==0) 
               {
               OUTPUT_LOW(PIN_A4);
               }
               ELSE
               {
               OUTPUT_HIGH(PIN_A4);
               }
               
               DO {} WHILE (!INPUT(UP));
            }
      }
    IF (!INPUT(READ))
            {
               DELAY_MS (10);
               IF(!INPUT(READ))
                  {
                     OUTPUT_HIGH(PIN_C3);
                     OUTPUT_LOW(PIN_C4);
                     VAR = READ_ADC();
                     VAR1 = (FLOAT)((VAR)*(5.00/1023.00))*1000.0;
                     VAR2 = VAR1/1000.000;
                     VAR3 = VAR2*200.00;
                     VAR4 = VAR3/10.00;
                     SET_PWM1_DUTY(VAR3);
                     
                     
                     /*
                     LCD_Gotoxy(1,0);
                     LCD_PutChar((VAR1/1000)%10 + 0X30);//DONVI
                     LCD_PutChar(".");//CHAMTHAPPHAN
                     LCD_PutChar((VAR1%1000)/100 +0X30);
                     LCD_PutChar(((VAR1%1000)/10)%10 +0X30);
                     LCD_PutChar("V");*/
                     LCD_Gotoxy(1,0);
                     LCD_PutChar(VAR2/1000 + 0X30);
                     LCD_PutChar((VAR2/100)%10 + 0X30);
                     LCD_PutChar((VAR2/10)%10 + 0X30);
                     LCD_PutChar(VAR2%10 + 0X30);
                     DO {} WHILE (!INPUT(UP));
                     
                  }
            }
           LCD_Gotoxy(0,0);
                     LCD_PutChar("PWM:");
                     LCD_PutChar(VAR4/100 + 0X30);
                     LCD_PutChar((VAR4/100)%10 + 0X30);
                     LCD_PutChar(VAR4%10 + 0X30);
                     LCD_PutChar("%");
   }
}
