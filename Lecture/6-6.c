#INCLUDE <TV_16F887.C>
#INCLUDE<TV_LCD.C>
UNSIGNED INT16  DEM;
VOID LCD_HIENTHI()
{
   LCD_COMMAND(ADDR_LINE1); 
   LCD_DATA((DEM/1000)+0X30);
   LCD_DATA((DEM/100)%10+0X30);
   LCD_DATA((DEM/10)%10+0X30);
   LCD_DATA((DEM%10)+0X30);
}
VOID MAIN()
{
   DEM=0;
   SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 );
   SET_TIMER1(0);
   WHILE(TRUE)
   {
      SET_TRIS_E(0x00); SET_TRIS_D(0x00);
      LCD_SETUP();
      LCD_HIENTHI();
      DELAY_MS(100);
      DEM = GET_TIMER1();
         IF(DEM == 10000) SET_TIMER1(0); 
      }
   }
   