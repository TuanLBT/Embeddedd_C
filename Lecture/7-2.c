#INCLUDE<TV_16F887.C>
#BIT TMR1IF = 0x0C.0
UNSIGNED INT16 KQADC, CHANNEL;
UNSIGNED INT BDT,MATRAM;
VOID HIEN_THI()
{
   MATRAM = MA7DOAN[KQADC/100];
   IF (MATRAM == 0XC0) MATRAM=0XFF;
   OUTPUT_B(MA7DOAN[KQADC%10]);
   OUTPUT_C(MA7DOAN[KQADC/10%10]);
   OUTPUT_D(MATRAM);
}
VOID MAIN()
{
   SET_TRIS_B(0x00); SET_TRIS_D(0x00);
   SET_TRIS_C(0x00); SET_TRIS_A(0xFF);
      BDT=0; CHANNEL = 0;
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(ALL_ANALOG);
   WHILE(TRUE)
   {
      KQADC=0;
      SET_ADC_CHANNEL(CHANNEL);
      KQADC=READ_ADC();
      DELAY_MS(1);
      KQADC= KQADC /2.046;
      HIEN_THI();
      IF (TMR1IF==1)
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
         IF (BDT % 10 == 0)
         {
         CHANNEL++;
         SET_ADC_CHANNEL(CHANNEL);
         KQADC=READ_ADC();
         DELAY_MS(1);
         KQADC= KQADC /2.046;
         HIEN_THI();
         
         IF (BDT >= 80)
         {BDT = 0; CHANNEL =0;}
         }
      }
   }
}
