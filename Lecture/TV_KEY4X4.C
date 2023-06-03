CONST UNSIGNED CHAR MAQUETCOT[4]= {0xFE,0xFD,0xFB,0xF7};
UNSIGNED INT QUET_MT_PHIM()
{
   SIGNED INT8 MAPHIM, HANG, COT;
   MAPHIM=HANG=0XFF;
   FOR(COT=0;COT<4;COT++) //cho giá tri cot chay tu 0 -> 4, moi gia tri thi quet 1 cot 
   {
      OUTPUT_B(MAQUETCOT[COT]);
      IF (!INPUT(PIN_A0))      {HANG=0; BREAK;} //Neu phim nay bi an thi HANG CO GIA TRI LA 0
      ELSE IF (!INPUT(PIN_A1)) {HANG=1; BREAK;}
      ELSE IF (!INPUT(PIN_A2)) {HANG=2; BREAK;}
      ELSE IF (!INPUT(PIN_A3)) {HANG=3; BREAK;}
   }
   IF (HANG!=0XFF) MAPHIM = COT*4 + HANG; 
   RETURN(MAPHIM);
}
UNSIGNED INT KEY_4X4()
{
   UNSIGNED INT8 MPT1,MPT2;
   MPT1=QUET_MT_PHIM();
   IF (MPT1!=0XFF)
   {
      DELAY_MS(10);
      MPT1=QUET_MT_PHIM();
      DO{MPT2=QUET_MT_PHIM();}
      WHILE (MPT2==MPT1);
   }
   RETURN(MPT1);
}
