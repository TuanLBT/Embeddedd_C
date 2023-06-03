#INCLUDE<TV_16F887.C>
#BIT TMR2IF = 0x0C.1
UNSIGNED INT8 X, BDT, GIAY;
VOID MAIN()
{
   SET_TRIS_B(0x00); SET_TRIS_C(0x00); 
   BDT=0; GIAY =0; OUTPUT_B(0XFF);OUTPUT_C(0XFF);
   SETUP_TIMER_2(T2_DIV_BY_16, 255,16);
   SET_TIMER2(130);
   WHILE(TRUE)
   {
      IF (TMR2IF==1)
      {
         TMR2IF=0; SET_TIMER2(130); BDT++;
         IF (BDT== 78)
         {
            GIAY++;
            OUTPUT_B(MA7DOAN[(GIAY/10)]); 
            OUTPUT_C(MA7DOAN[GIAY%10]);
         }
      }
   }
}
