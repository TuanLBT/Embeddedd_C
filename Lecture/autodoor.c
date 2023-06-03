#INCLUDE <16F887.H>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
VOID MAIN()
{ 
      SET_TRIS_D(0x00);
      WHILE(TRUE)
      {
      IF (INPUT(PIN_B0) == 1)
            {OUTPUT_HIGH(PIN_D0);}
      ELSE
            {OUTPUT_LOW(PIN_D0);}
      }
}
