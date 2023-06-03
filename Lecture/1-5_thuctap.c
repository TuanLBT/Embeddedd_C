#include <16f887.h>
#FUSES NOWDT,PUT,HS,NOPROTECT,NOLVP
#USE DELAY(CLOCK=20M) 
UNSIGNED INT16 I, X, A=0,time;
void dela(time){  //DUNG DE CHONG DELAY
   for(i=0;i<time+1;i++){
   delay_ms(1);
      if ( input(pin_a0)==0)X=1;
      if ( input(pin_a1)==0)X=2;
      if ( input(pin_a2)==0)X=3;
      }
}
VOID MAIN()
{ 
SET_TRIS_A(0x07);
X=0XFF;
 OUTPUT_A(X);
DELAY_MS(500);

 WHILE(TRUE)
 { 
      if ( input(pin_a0)==0)X=1;
      if ( input(pin_a1)==0)X=2;
      if ( input(pin_a2)==0)X=3;
      if(X==1){
         output_HIGH(PIN_A3);dela(200);
         output_LOW(PIN_A3);
         output_HIGH(PIN_A4);dela(200);
         output_LOW(PIN_A4);
         
         }
         else if(X==2){
         output_HIGH(PIN_A3);
         output_HIGH(PIN_A4);
         dela(500);
         output_LOW(PIN_A3);
         output_LOW(PIN_A4);
         dela(500);
         }
            else if(X==3){
            output_HIGH(PIN_A3);
            output_LOW(PIN_A4);
            dela(700);
            output_LOW(PIN_A3);
            output_HIGH(PIN_A4);
            dela(100);
            }}
}
