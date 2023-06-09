#INCLUDE<TV_16F887.C>
#BIT TMR1IF = 0x0C.0
UNSIGNED INT16 KQADC1, KQADC2;
UNSIGNED INT J, BDT,MATRAM1, MATRAM2;
VOID HIEN_THI_1()
{
   MATRAM1 = MA7DOAN_4X4[KQADC1/100];
   IF (MATRAM1 == 0XC0) MATRAM1=0XFF;
   OUTPUT_B(MA7DOAN_4X4[KQADC1%10]);
   OUTPUT_C(MA7DOAN_4X4[KQADC1/10%10]);
   OUTPUT_D(MATRAM1);
}
VOID HIEN_THI_2()
{
   MATRAM2 = MA7DOAN_4X4[KQADC2/100];
   IF (MATRAM2 == 0XC0) MATRAM2=0XFF;
   OUTPUT_B(MA7DOAN_4X4[KQADC2%10]);
   OUTPUT_C(MA7DOAN_4X4[KQADC2/10%10]);
   OUTPUT_D(MATRAM2);
}
VOID MAIN()
{
   SET_TRIS_B(0x00); SET_TRIS_D(0x00);
   SET_TRIS_C(0x00); SET_TRIS_A(0xFF);
      BDT=0;
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   SETUP_ADC(ADC_CLOCK_DIV_8);
   SETUP_ADC_PORTS(ALL_ANALOG);
   WHILE(TRUE)
   {
   KQADC1=0; KQADC2=0;
      SET_ADC_CHANNEL(0);
      KQADC1=READ_ADC();
      DELAY_MS(1);
      KQADC1= KQADC1 /2.046;
      HIEN_THI_1();
      IF (TMR1IF==1)
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
         IF (BDT == 10)
         {
         
         SET_ADC_CHANNEL(1);
         KQADC2=READ_ADC();
         DELAY_MS(1);
         KQADC2= KQADC2 /2.046;
         HIEN_THI_2();
         DELAY_MS(1000);
         BDT = 0;
         }
      }
   }
}
