#INCLUDE <16F887.H>
#FUSES NOWDT,PUT,HS,NOPROTECT,NOLVP
#USE DELAY(CLOCK=20M)
UNSIGNED INT8 I, X;
VOID MAIN()
{ SET_TRIS_D(0x00);
X=0X00; OUTPUT_D(X);
DELAY_MS(500);
WHILE(TRUE)
{ FOR (I=0;I<8;I++)
{ X = (X<<1)+0X01; OUTPUT_D(X); DELAY_MS(500);}
FOR (I=0;I<8;I++)
{ X = (X<<1); OUTPUT_D(X); DELAY_MS(500);}
}
}
