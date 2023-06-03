#INCLUDE<TV_16F887.C>
#INCLUDE<TV_LCD.C>
UNSIGNED INT16 BIEN_TOC_DO, I;
const unsigned char HANG1[20]={"RE TRAI DI ONII-CHAN"};
const unsigned char HANG2[20]={"RE PHAI DI ONII-CHAN"};
const unsigned char HANG3[20]={"DI DUNG ROI ONI-CHAN"};
const unsigned char HANG4[14]={"DANG TIM DUONG"};

VOID LCD_HIENTHI1()
{
   LCD_SETUP();   
   LCD_COMMAND(ADDR_LINE1); DELAY_US(10);
   FOR (I=0;I<20;I++) { LCD_DATA(HANG1[I]);}
}
VOID LCD_HIENTHI2()
{
   LCD_SETUP();   
   LCD_COMMAND(ADDR_LINE2); DELAY_US(10);
   FOR (I=0;I<20;I++) { LCD_DATA(HANG2[I]);}
}
VOID LCD_HIENTHI3()
{
   LCD_SETUP();   
   LCD_COMMAND(ADDR_LINE3); DELAY_US(10);
   FOR (I=0;I<20;I++) { LCD_DATA(HANG3[I]);}
}
VOID LCD_HIENTHI4()
{
   LCD_SETUP();   
   LCD_COMMAND(ADDR_LINE4); DELAY_US(10);
   FOR (I=0;I<14;I++) { LCD_DATA(HANG4[I]);}
}
VOID DI_THANG()
{     
OUTPUT_HIGH(PIN_C4);
   OUTPUT_HIGH(PIN_C5);
      OUTPUT_HIGH(PIN_C0);
      OUTPUT_LOW(PIN_C1);
      OUTPUT_HIGH(PIN_C2);
      OUTPUT_LOW(PIN_C3);
      LCD_HIENTHI3();
      DELAY_MS(100);
}
VOID XOAY_TIMDUONG()
{
OUTPUT_HIGH(PIN_C4);
   OUTPUT_HIGH(PIN_C5);
      OUTPUT_LOW(PIN_C0);
      OUTPUT_HIGH(PIN_C1);
      OUTPUT_HIGH(PIN_C2);
      OUTPUT_LOW(PIN_C3);
      LCD_HIENTHI4();
      DELAY_MS(100);
}
VOID XOAY_TRAI()
{     
      OUTPUT_HIGH(PIN_C4);
   OUTPUT_HIGH(PIN_C5);
      OUTPUT_LOW(PIN_C0);
      OUTPUT_HIGH(PIN_C1);
      OUTPUT_HIGH(PIN_C2);
      OUTPUT_LOW(PIN_C3);
      LCD_HIENTHI1();
      DELAY_MS(100);
}
VOID XOAY_PHAI()
{
OUTPUT_HIGH(PIN_C4);
   OUTPUT_HIGH(PIN_C5);
      OUTPUT_HIGH(PIN_C0);
      OUTPUT_LOW(PIN_C1);
      OUTPUT_LOW(PIN_C2);
      OUTPUT_HIGH(PIN_C3);
      LCD_HIENTHI2();
      DELAY_MS(100);
}
void main()
{
   SET_TRIS_C(0x00);
   SET_TRIS_D(0x00);
   SET_TRIS_B(0xFF);
   SET_TRIS_E(0x00);
   OUTPUT_C(0x00);
   OUTPUT_D(0x00);
   
   OUTPUT_HIGH(PIN_C4);
   OUTPUT_HIGH(PIN_C5);
    WHILE(TRUE)
    {
      
      IF ((INPUT_STATE(PIN_B2) == 1) && (INPUT_STATE(PIN_B1) == 1) && (INPUT_STATE(PIN_B3) == 1) && (INPUT_STATE(PIN_B4) == 1) && (INPUT_STATE(PIN_B0) == 1))
      {
      XOAY_TIMDUONG();
      }
      ELSE IF ((INPUT_STATE(PIN_B2) == 0))
      {
      DI_THANG();
      }
      ELSE IF ((INPUT_STATE(PIN_B2) == 1)) 
      {
         OUTPUT_C(0x00);
         IF ((INPUT_STATE(PIN_B0) == 0) || (INPUT_STATE(PIN_B1) == 0))
         {
         XOAY_TRAI();
         }
         IF ((INPUT_STATE(PIN_B3) == 0) || (INPUT_STATE(PIN_B4) == 0))
         {
         XOAY_PHAI(); 
         }
      }
    }
 }


