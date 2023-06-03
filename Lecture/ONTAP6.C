#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE AN3 PIN_B0
#DEFINE AN4 PIN_B1
#DEFINE AN5 PIN_B2
SIGNED INT16 VAR=0,CAL,n;

VOID MAIN()
{
   SET_TRIS_D(0X00); SET_TRIS_B(0XFF); //SET I/O
   //KHOI TAO LCD, KHONG CO 2 DONG NAY LCD KO CHAY
   LCD_Init();
   delay_ms(10);
   //SET UP ADC
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(SAN5|SAN4|SAN3);
   WHILE(TRUE)
   {
   IF (!INPUT(AN3))
      {
         DELAY_MS(10);
         IF(!INPUT(AN3))
         {
         n = 3;
         }
      }
    IF (!INPUT(AN4))
      {
         DELAY_MS(10);
         IF(!INPUT(AN4))
         {
         n = 4;   
         }
      }  
     IF (!INPUT(AN5))
      {
         DELAY_MS(10);
         IF(!INPUT(AN5))
         {
         n = 5;
         }
      } 
            SET_ADC_CHANNEL(n);
            VAR = READ_ADC();
            CAL = VAR*(5.00/1023.00);
      LCD_Gotoxy(0,0);
      LCD_PutChar("VOLTAGE:");
      LCD_PutChar(CAL/1000 + 0X30);
      LCD_PutChar((CAL/100)%10 + 0X30);
      LCD_PutChar((CAL/10)%10 + 0X30);
      LCD_PutChar(CAL%10 + 0X30);
      LCD_Gotoxy(1,0);
      LCD_PutChar("channel:");
      LCD_PutChar(n + 0X30);
   }
}
