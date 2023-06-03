#INCLUDE <TV_16F887.C>
#BIT TMR1IF = 0x0C.0
UNSIGNED INT8 X, BDT;
VOID MAIN()
{
   SET_TRIS_D(0x00); X=0; BDT=0; OUTPUT_D(X);
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   WHILE(TRUE)
   {
      IF (TMR1IF==1)
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
            IF (BDT ==30)
               {X=~X;OUTPUT_D(X); BDT = 0;}
            
            ELSE 
            {
            IF (BDT ==10)
              {
              X=~X;OUTPUT_D(X);
              }
            }
            
         
      }
      }
   }

