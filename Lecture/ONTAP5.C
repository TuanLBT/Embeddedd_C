#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE THUAN PIN_B0
#DEFINE NGHICH PIN_B1
SIGNED INT16 VAR=0,CAL;
VOID PHIM_THUAN()
{
   IF (!INPUT(THUAN))
      {
         DELAY_MS(10);
         IF(!INPUT(THUAN))
         {
            OUTPUT_HIGH(PIN_C3);
            OUTPUT_LOW(PIN_C4);
         }
      }
}
VOID PHIM_NGHICH()
{
   IF (!INPUT(NGHICH))
      {
         DELAY_MS(10);
         IF(!INPUT(NGHICH))
         {
            OUTPUT_LOW(PIN_C3);
            OUTPUT_HIGH(PIN_C4);
         }
      }
}
      
VOID MAIN()
{
   SET_TRIS_D(0X00); SET_TRIS_B(0XFF);SET_TRIS_C(0X00); //SET I/O
   //KHOI TAO LCD, KHONG CO 2 DONG NAY LCD KO CHAY
   LCD_Init();
   delay_ms(10);
   //SET UP ADC
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(SAN5);
   SET_ADC_CHANNEL(5);
   //KHOI TAO PWM2:
   SETUP_CCP1(CCP_PWM); 
   setup_timer_2(T2_DIV_BY_16, 21, 1); 
   //PERIODPWM = [(PR2) + 1]*4*TOSC*PVTMR2 = 83333nS 
   // PERIODPWM = 1/f (f de cho)
   // TOSC  = 1/f thach anh = 1/20Mhz
   // PVTMR2 = 1/4/16, (chon 16)
   // => PR2 = 26 
   SET_PWM1_DUTY(0); 
   //
   WHILE (TRUE)
   {
      VAR = READ_ADC();
      CAL = 83.33 - VAR*(83.33/1023.00); //CON SO 83.33, muon biet no o dau ra thi tra trang 233 giao trinh 16f887
      SET_PWM1_DUTY(CAL);
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
      PHIM_NGHICH();
      PHIM_THUAN();
   }
}
