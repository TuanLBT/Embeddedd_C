#INCLUDE<TV_16F887.C>
#INCLUDE<TV_KEY4X4.C>
SIGNED INT16 MP, SOTHU1, SOTHU0, UNDO;
VOID MAIN()
{
   SET_TRIS_D(0x00); SET_TRIS_C(0x00);
   SET_TRIS_B(0xF0); PORT_B_PULLUPS(0XF0);
   SOTHU0=0X7F; SOTHU1=0XFF;
   OUTPUT_D(SOTHU0); OUTPUT_C(SOTHU1);
   WHILE(TRUE)
   {
      MP= KEY_4X4();
      IF (MP!=0XFF)
      {
         IF (MP>=10) 
         {
            IF (MP == 12)
            {
               SOTHU0=0X7F; SOTHU1=0XFF;
               OUTPUT_D(SOTHU0); OUTPUT_C(SOTHU1);
            }
            IF (MP ==13 )
            {
               IF (SOTHU0 == 0X7F) {}
               ELSE
               {
               SOTHU0 = SOTHU1;
               SOTHU1 = UNDO;
               OUTPUT_D(SOTHU0); OUTPUT_C(SOTHU1);
               }
            }
            ELSE {}
         }
         ELSE
         {
         UNDO = SOTHU1;
         SOTHU1=SOTHU0;
         SOTHU0=MA7DOAN[MP];
         OUTPUT_D(SOTHU0); OUTPUT_C(SOTHU1);
         }
      }
   }
}

