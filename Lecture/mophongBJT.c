#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE UP PIN_A0
void main()
{
   while(true)
   {
      if (!input(UP))
         {
         DELAY_MS(10);
         if (!input(UP)){OUTPUT_HIGH(PIN_C0);}
         }
         else{OUTPUT_low(PIN_C0);}
   }

}
