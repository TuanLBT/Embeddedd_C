#INCLUDE <LCD4CHAN(CUATHAY).C>
UNSIGNED INT8 DEM1, DEM2;
VOID MAIN()
{
   SET_TRIS_D(0x00);
   LCD_Init();
   DEM1=0; DEM2=0;
   SETUP_TIMER_0(T0_EXT_L_TO_H | T0_DIV_1); //T0_EXT_L_TO_H XUNG NGOAI CUA T0
   SET_TIMER0(0);
   SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 );//EXTERNAL: XUNG NGOAI / INTERNAL: XUNG NOI
   SET_TIMER1(0);
   WHILE(TRUE)
   {
    DEM1 = GET_TIMER0();
            LCD_Gotoxy(0,1);
            LCD_PutChar(DEM1%10+0X30);
            LCD_Gotoxy(0,0);
            LCD_PutChar(DEM1/10+0X30);
    DEM2= GET_TIMER1();
            LCD_Gotoxy(1,1);
            LCD_PutChar(DEM2%10+0X30);
            LCD_Gotoxy(1,0);
            LCD_PutChar(DEM2/10+0X30);
   
   }
}
