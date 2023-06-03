#INCLUDE<TV_16F887.C>

UNSIGNED INT16 KQADC=0;
UNSIGNED INT MATRAM;
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
SET_TRIS_C(0x00); SET_TRIS_A(0x01);
SETUP_ADC(ADC_CLOCK_DIV_8);
SETUP_ADC_PORTS(SAN0|SAN1);

WHILE(TRUE)
{


SET_ADC_CHANNEL(0);
KQADC=READ_ADC();
DELAY_MS(1);
KQADC= KQADC /2.046;
delay_ms(1000);
HIEN_THI();

SET_ADC_CHANNEL(1);

KQADC=READ_ADC();
DELAY_MS(1);
KQADC= KQADC /2.046;
delay_ms(1000);


HIEN_THI();
}
}
