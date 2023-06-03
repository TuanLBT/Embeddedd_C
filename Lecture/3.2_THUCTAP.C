#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR1IF = 0x0C.0
UNSIGNED INT8 X, BDT;
UNSIGNED int1 n;
VOID MAIN()
{
      SET_TRIS_A(0x00);
      X=0xff;
      OUTPUT_A(X);
      BDT=0; n= 0;
      SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8); //EXTERNAL: XUNG NGOAI (dem xung) / INTERNAL: XUNG NOI (dinh thoi)
      //20MHZ/4 = 5MHZ/8 = 0.625Mhz => T (CHU KY CUA 1 XUNG) = 1/f = 1/0.625MHZ = 1.6us
      SET_TIMER1(3036); //TAO GIA TRI SO XUNG BAN DAU LA 3036, MAX XUNG CUA TIMER 1 DEM DUOC LA 65536, VI VAY NEN TIMER 1 SE DEM 65536-3036 = 62500 XUNG
   WHILE(TRUE)
 {
   IF (TMR1IF==1) //MOI LAN 62500 XUNG DC DEM THI SE NGAT 1 LAN
   {
      TMR1IF=0; SET_TIMER1(3036); BDT++; 
      IF ((BDT ==20)&&(n==1))
      {
         X=~X;
         OUTPUT_A(X); BDT = 0;n=0;
      }
      else if ((BDT ==10)&&(n==0))
      {
         X=~X;
         OUTPUT_A(X); BDT = 0; n=1;
      }
     }
   }
}
            

