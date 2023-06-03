#include <16F887.h>
#FUSES NOWDT,PUT,HS,NOPROTECT,NOLVP
#USE DELAY(CLOCK=20M)
#DEFINE SANG PIN_A1
#DEFINE TAT PIN_A0
#DEFINE DAO PIN_A2
UNSIGNED INT16 X;

void nut1(){
   if(!input(SANG))
   {
      delay_ms(20);
         if(!input(SANG))
         { X = 0XFF;}
         output_A(X);
         delay_ms(100);
         while(!input(SANG));
   }
}

void nut2(){
   if(!input(TAT))
   {
      delay_ms(20);
         if(!input(TAT))
         { X = 0x00;}
         output_A(X);
         delay_ms(100);
         while(!input(TAT));}
}

void nut3()
{ 
   if(!input(DAO))
    {
      delay_ms(20);
      if(!input(DAO))
      {X = ~ X;}//Dao chieu
      output_A(X);
      delay_ms(100);
      while(!input(DAO));}
    }
void main()
{
   SET_TRIS_A(0x07);
   OUTPUT_A(X);
   DELAY_MS(100);
   X=0XFF;

   while(TRUE)
   {
   nut1();
   nut2();
   nut3();
   }

}
