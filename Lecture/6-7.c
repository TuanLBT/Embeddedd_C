#INCLUDE <TV_16F887.C>
#INCLUDE<TV_LCD.C>
UNSIGNED INT16  I, DEM1, DEM2;
const unsigned char HANG1[2]={"TO"};
const unsigned char HANG2[2]={"T1"};
VOID LCD_HIENTHI()
{
   LCD_COMMAND(0x88); 
   LCD_DATA((DEM1/1000)+0X30);
   LCD_DATA((DEM1/100)%10+0X30);
   LCD_DATA((DEM1/10)%10+0X30);
   LCD_DATA((DEM1%10)+0X30);
   
   LCD_COMMAND(0xC8); 
   LCD_DATA((DEM2/1000)+0X30);
   LCD_DATA((DEM2/100)%10+0X30);
   LCD_DATA((DEM2/10)%10+0X30);
   LCD_DATA((DEM2%10)+0X30);
}
VOID MAIN()
{
   DEM1=0; DEM2=0;
   SETUP_TIMER_0(T0_EXT_L_TO_H | T0_DIV_1);
   SET_TIMER0(0);
   SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 );
   SET_TIMER1(0);
   WHILE(TRUE)
   {
   SET_TRIS_E(0x00); SET_TRIS_D(0x00);
   LCD_SETUP();
   LCD_COMMAND(ADDR_LINE1); DELAY_US(10);
   FOR (I=0;I<2;I++) { LCD_DATA(HANG1[I]);}
   LCD_COMMAND(ADDR_LINE2); DELAY_US(10);
   FOR (I=0;I<2;I++) { LCD_DATA(HANG2[I]);}
   LCD_HIENTHI();
   DELAY_MS(100);
   IF (GET_TIMER0()==1)
   {
      SET_TIMER0(0);
      DEM1++;
   IF (DEM1>=10000)
   {
      DEM1 = 0;
   }
   }
   DEM2 = GET_TIMER1();
         IF(DEM2 == 1000) 
         {
         SET_TIMER1(0);
         }
   }
}

