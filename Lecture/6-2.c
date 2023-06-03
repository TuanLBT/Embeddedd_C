#INCLUDE <TV_16F887.C>
#BIT TMR1IF = 0x0C.0
UNSIGNED INT8 X, BDT, GIAY;
VOID MAIN()
{
   SET_TRIS_B(0x00); SET_TRIS_C(0x00); 
   BDT=0; GIAY =0; OUTPUT_B(0XFF);OUTPUT_C(0XFF);
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   WHILE(TRUE)
   {
      IF (TMR1IF==1)
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
         IF (BDT%10 == 0)
         {
            GIAY++;
            IF (GIAY>=60) {GIAY = 0;}
            OUTPUT_B(MA7DOAN[(GIAY/10)]); 
            OUTPUT_C(MA7DOAN[GIAY%10]);
         }
      }
   }
}
