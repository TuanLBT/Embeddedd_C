#INCLUDE <16F887.H>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
VOID MAIN()
SET_TRIS_D(0x00);
{ 
      WHILE(TRUE)
      {
            OUTPUT_HIGH(PIN_D0); DELAY_MS(1000);
            OUTPUT_LOW(PIN_D0); DELAY_MS(1000);
      }
}