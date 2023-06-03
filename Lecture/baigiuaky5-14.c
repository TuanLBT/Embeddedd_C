#INCLUDE<TV_16F887.C>
#INCLUDE<TV_LCD.C>
UNSIGNED CHAR I, GIAY, PHUT, GIO;
const unsigned char HANG1[6]={"CLOCK:"};
const unsigned char HANG2[5]={"SUNNY"};
VOID LCD_HIENTHI()
{
PHUT = 59;
   LCD_COMMAND(0x88); DELAY_US(10);
   LCD_DATA((GIO/10)+0X30);
   LCD_DATA((GIO%10)+0X30);
   LCD_DATA(":");
   LCD_DATA((PHUT/10)+0X30);
   LCD_DATA((PHUT%10)+0X30);
   LCD_DATA(":");
   LCD_DATA((GIAY/10)+0X30);
   LCD_DATA((GIAY%10)+0X30);
}
VOID MAIN()
{
   WHILE(TRUE)
   {
      SET_TRIS_E(0x00); SET_TRIS_D(0x00);
      LCD_SETUP();
      LCD_COMMAND(ADDR_LINE1); DELAY_US(10);
FOR (I=0;I<6;I++) { LCD_DATA(HANG1[I]);}
LCD_COMMAND(ADDR_LINE2); DELAY_US(10);
FOR (I=0;I<5;I++) { LCD_DATA(HANG2[I]);}
      LCD_HIENTHI();
      DELAY_MS(1000);
      GIAY++;
      IF (GIAY>=60)
         {
         GIAY = 0;
         PHUT++;
            IF (PHUT >=60) 
            {
               PHUT=0;
               GIO ++;
                  IF (GIO >=24)
                  {GIO = 0;}
            }
         }
   }
 
}
