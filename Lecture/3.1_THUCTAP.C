#INCLUDE <LCD4CHAN(CUATHAY).C>
//#BIT TMR0IF = 0x0B.2 //KHAI BAO CO NGAT TIMER 0
#BIT TMR1IF = 0x0C.0 //KHAI BAO CO NGAT TIMER 1
UNSIGNED INT8 BDT, GIAY, PHUT, GIO;
VOID MAIN()
{  GIO = 23;
   PHUT = 59;
   SET_TRIS_D(0x00);
   LCD_Init();
   delay_ms(10);  LCD_Gotoxy(0,0);
   BDT=0; GIAY =50;
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8); //EXTERNAL: XUNG NGOAI / INTERNAL: XUNG NOI
   //20MHZ/4 = 5MHZ/8 = 0.625Mhz => T (CHU KY CUA 1 XUNG) = 1/f = 1/0.625MHZ = 1.6us
   SET_TIMER1(3036); //SO LUONG XUNG BAN DAU, TIMER 1 SE BAT DAU DEM TU GIA TRI 3036 DEN GIA TRI TRAN
   //MAX XUNG CUA TIMER 1 DEM DUOC LA 65536, VI VAY NEN TIMER 1 SE DEM 65536-3036 = 62500 XUNG
   //CHU KY CUA MOI XUNG LA 1.6us NEN SAU 62500 XUNG TUONG DUONG VOI 1.6us*62500 = 100ms
   
   //SETUP_TIMER_0(T0_INTERNAL| T0_DIV_256); //20MHZ/4 (PHANCUNG) = 5MHZ/256 (TU CHO) = 19,53125kHz => T (CHU KY CUA XUNG) = 51,2µs
   //SET_TIMER0(61); //DAT SO XUNG BAN DAU LA 61, TIMER 0 SE DEM TU GIA TRI 61
   //VAY SUY RA THOI GIAN DEN LUC NGAT SE LA = XUNGxT = (256-61)*51,2µs =  9984µs ˜ 10ms
   WHILE(TRUE)
   {
      IF (TMR1IF==1) //KHI TRAN THI GIA TRI CO NGAT SE LEN 1
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++; // RESET LAI GIA TRI 3036 VA BAT DAU DEM TU DO; BDT + 1 GIA TRI 
         IF (BDT%10 == 0) //NGAT 10 LAN THI TUONG DUONG VOI 1S (100ms*10 = 1s)
         {
            GIAY++;
            IF (GIAY>=60) 
            {
            GIAY = 0;
            PHUT++;
               IF (PHUT >= 60) {
               PHUT = 0; GIO++;
               IF (GIO >=24) {GIO =0;}
               }
            }
            LCD_Gotoxy(0,7);
            LCD_PutChar(GIAY%10+0X30);
            LCD_Gotoxy(0,6);
            LCD_PutChar(GIAY/10+0X30);
            
            LCD_Gotoxy(0,5);
            LCD_PutChar(":");
            
            LCD_Gotoxy(0,4);
            LCD_PutChar(PHUT%10+0X30);
            LCD_Gotoxy(0,3);
            LCD_PutChar(PHUT/10+0X30);
            
            LCD_Gotoxy(0,2);
            LCD_PutChar(":");
            
            LCD_Gotoxy(0,1);
            LCD_PutChar(GIO%10+0X30);
            LCD_Gotoxy(0,0);
            LCD_PutChar(GIO/10+0X30);
         }
      }
   }
}
