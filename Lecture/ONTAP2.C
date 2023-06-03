#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE UP PIN_B0
#DEFINE DW PIN_B1
#BIT TMR1IF = 0x0C.0
SIGNED INT16 VAR,X,BDT;

VOID MAIN()
{
   VAR = 49;
   X=0;
   SET_TRIS_D(0X00); SET_TRIS_B(0XFF); //SET I/O
   //KHOI TAO LCD, KHONG CO 2 DONG NAY LCD KO CHAY
   LCD_Init();
   delay_ms(10);
   
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8); //khoi tao timer1
   SET_TIMER1(3036); //DAT SO XUNG BAN DAU CHO TIMER 1
   
   WHILE(TRUE)
   {  IF (TMR1IF==1) //BANG 1 THI TIMER SE NGAT, KHONG DEM XUNG NUA
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++; //RESET NGAT, DAT LAI SO XUNG BAN DAU
         
          IF (BDT == 3) //BDT DEM LEN 3 DON VI = 300ms
          {
            BDT = 0; 
            IF (VAR == 50)
               {X=~X; OUTPUT_E(X);}
          }
      }
      IF (!INPUT(UP))
      {
         DELAY_MS(10);
         IF (!INPUT(UP))
         {
            VAR++;
            DO{}WHILE (!INPUT(UP));
         }
      }
      IF (VAR>=20 && VAR <=50)
      {
         LCD_Gotoxy(0,0);
         LCD_PutChar(VAR/10 + 0X30);
         LCD_PutChar(VAR%10 + 0X30);
      }
   }
}
