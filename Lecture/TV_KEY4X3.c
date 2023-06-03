CONST UNSIGNED CHAR MAQUETHANG[4]= {0xFE,0xFD,0xFB,0XF7};
UNSIGNED INT QUET_MT_PHIM()
{
   SIGNED INT8 MAPHIM, HANG, COT;
   MAPHIM=COT=0XFF; // DAT MOT GIA TRI CHO COT VA MAPHIM
   FOR(HANG=0;HANG<4;HANG++) //cho giá tri HANG chay tu 0 -> 3, moi gia tri thi quet 1 cot 
   {
      OUTPUT_B(MAQUETHANG[HANG]); // moi lan quet thi sex xuat ra ma quet hang o port B
      IF (!INPUT(PIN_A0))      {COT=1; BREAK;} //an nut o cot A0
      ELSE IF (!INPUT(PIN_A1)) {COT=2; BREAK;} //an nut o cot A1
      ELSE IF (!INPUT(PIN_A2)) {COT=3; BREAK;} //an nut o cot A2
   }
   IF (COT!=0XFF) MAPHIM = HANG*3 + COT; //neu COT KHAC GIA TRI 0XFF BAN DAU, THI SE THUC HIEN PHEP TINH GIA TRI MAPHIM
   RETURN(MAPHIM); //LUU TRU GIA TRI MAPHIM CUA HAM QUET_MY_PHIM()
}
// PHAN DUOI DAY GIONG TRONG SACH, KO DOI
UNSIGNED INT KEY_4X3()
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
