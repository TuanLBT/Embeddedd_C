#INCLUDE <LCD4CHAN(CUATHAY).C>
SIGNED INT16 VAR=0,CAL;
VOID MAIN()
{
   SET_TRIS_D(0X00); SET_TRIS_B(0XFF); //SET I/O
   //KHOI TAO LCD, KHONG CO 2 DONG NAY LCD KO CHAY
   LCD_Init();
   delay_ms(10);
   //SET UP ADC
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(SAN5);
   SET_ADC_CHANNEL(5);
   //KHOI TAO PWM2:
   SETUP_CCP2(CCP_PWM); 
   setup_timer_2(T2_DIV_BY_16, 26, 1); 
   //PERIODPWM = [(PR2) + 1]*4*TOSC*PVTMR2 = 83333nS 
   // PERIODPWM = 1/f (f de cho)
   // TOSC  = 1/f thach anh = 1/20Mhz
   // PVTMR2 = 1/4/16, (chon 16)
   // => PR2 = 26 
   SET_PWM2_DUTY(0); //trang 233 giao trinh 16f887
   //
   WHILE (TRUE)
   {
      VAR = READ_ADC();
      CAL = 100 - VAR*(100.00/1023.00);
      SET_PWM2_DUTY(CAL);
      LCD_Gotoxy(0,0);
      LCD_PutChar("ADC:");
      LCD_PutChar(VAR/1000 + 0X30);
      LCD_PutChar((VAR/100)%10 + 0X30);
      LCD_PutChar((VAR/10)%10 + 0X30);
      LCD_PutChar(VAR%10 + 0X30);
      
      LCD_Gotoxy(1,0);
      LCD_PutChar("PULSEWIDTH:");
      LCD_PutChar(CAL/100 + 0X30);
      LCD_PutChar((CAL/10)%10 + 0X30);
      LCD_PutChar(CAL%10 + 0X30);
      LCD_PutChar("%");
   }
}
