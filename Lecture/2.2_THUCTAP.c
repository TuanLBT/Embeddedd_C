#INCLUDE<TV_16F887.C>
#DEFINE START PIN_E0
#DEFINE STOP PIN_E1
#DEFINE INV PIN_E2
UNSIGNED INT16 DEM, I, X;
INT1 CHOPHEP = 0;
INT1 DAO = 0;
VOID HIENTHI_DELAY()
{
   FOR (I=0;I<200;I++)
      {
         OUTPUT_B(MA7DOAN_4X4[DEM %10]);   OUTPUT_HIGH(PIN_A0);
         DELAY_MS(1);                  OUTPUT_LOW(PIN_A0);
         OUTPUT_B(MA7DOAN_4X4[DEM /10]);   OUTPUT_HIGH(PIN_A2);
         DELAY_MS(1);                  OUTPUT_LOW(PIN_A2);
         IF (!INPUT(START)) 
            {CHOPHEP=1;}
         ELSE IF (!INPUT(STOP) ) 
            {CHOPHEP=0;}
         IF (!INPUT(INV))
            {DAO = ~DAO;}
      }
}
VOID MAIN()
{ 
   SET_TRIS_B(0x00); SET_TRIS_A(0x00);
   OUTPUT_A(0XFF);
   CHOPHEP=0;
   DEM=0; 
   WHILE(TRUE)
      {
         IF (CHOPHEP == 1)
            {
               IF (DAO == 0)      DEM++;
               ELSE IF (DAO == 1) DEM--;
            }
         IF (DEM >=100)
            {DEM=0;}
            HIENTHI_DELAY();
         
      }
}
