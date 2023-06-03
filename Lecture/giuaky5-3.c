#INCLUDE <16F887.H>
#FUSES NOWDT,PUT,HS,NOPROTECT,NOLVP
#USE DELAY(CLOCK=20M)
UNSIGNED INT8 I, X, Y;
VOID MAIN()
{ 
      SET_TRIS_D(0x00);
      X=0X00; Y = 0X00; 
      OUTPUT_D(X); OUTPUT_B(Y);
      DELAY_MS(500);
while(True)
   {
         FOR (I=0;I<8;I++)
         { X = (X<<1)+0X01; OUTPUT_D(X); DELAY_MS(1000);}
         FOR (I=0;I<8;I++)
         { Y = (Y<<1)+0X01; OUTPUT_B(Y); DELAY_MS(1000);}
         FOR (I=0;I<8;I++)
         { X = (X<<1); OUTPUT_D(X); DELAY_MS(1000);}
         FOR (I=0;I<8;I++)
         { Y = (Y<<1); OUTPUT_B(Y); DELAY_MS(1000);}
   }
}

