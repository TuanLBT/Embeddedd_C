#INCLUDE <LCD4CHAN(CUATHAY).C>
UNSIGNED INT16 I, J,T,KQADC,n;
VOID LCD()
{
              T=READ_ADC();
               DELAY_MS(1);
               T= T /2.046;
   LCD_Gotoxy(0,7);
   LCD_PutChar(T/10 + 0X30);//HANGCHUC
   LCD_PutChar(T%10 +0X30);//DONVI
   LCD_PutChar(" *C");//DONVI
}
VOID SOPHONG()
{
   LCD_Gotoxy(0,0);
   LCD_PutChar("ROOM");//HANGCHUC
   LCD_PutChar(n + 0X30);//HANGCHUC
}

VOID MAIN()
{
   SET_TRIS_A(0XFF);
   SET_TRIS_B(0XFF);
   SET_TRIS_D(0x00); 
   LCD_Init();
   delay_ms(10); 
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(SAN0|SAN1|SAN2|SAN3|SAN4|SAN13);

   WHILE(TRUE)
   {
         T = 0; 
         IF (INPUT(PIN_B0)) { n = 0;}
         IF (INPUT(PIN_B1)) { n = 1;}
         IF (INPUT(PIN_B2)) { n = 2;}
         IF (INPUT(PIN_B3)) { n = 3;}
         IF (INPUT(PIN_B4)) { n = 13;}
         SET_ADC_CHANNEL(n);
    
               LCD();
               SOPHONG();
         }
         
   
}
