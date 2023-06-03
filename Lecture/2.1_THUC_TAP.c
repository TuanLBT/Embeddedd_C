#INCLUDE <TV_16F887.C>
#DEFINE START PIN_E0
#DEFINE STOP PIN_E1
SIGNED INT16 DEM;
INT1 CHOPHEP = 0;
VOID MAIN()
{
   SET_TRIS_E(0xFF);
   SET_TRIS_C(0x00);
   SET_TRIS_D(0x00);
   SET_TRIS_B(0x00);
   CHOPHEP=0;
   WHILE(TRUE)
   {
      FOR (DEM=0;DEM<1000;DEM++)
      {
            OUTPUT_C(MA7DOAN[DEM%10]); //DON VI
            OUTPUT_D(MA7DOAN[(DEM/10)%10]); //CHUC
            OUTPUT_B(MA7DOAN[(DEM/100)]); //TRAM
            DELAY_MS(10);
            DO
            {
               IF (!INPUT(START)) 
               {CHOPHEP=1;}
               ELSE IF (!INPUT(STOP) ) 
               {CHOPHEP=0;}
            }
         WHILE(CHOPHEP==0);
      }
   }
}
