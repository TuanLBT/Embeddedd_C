#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE UP PIN_B0
#DEFINE DW PIN_B1

SIGNED INT16 VAR;

VOID MAIN()
{
   SET_TRIS_D(0X00); SET_TRIS_B(0XFF); //SET I/O
   //KHOI TAO LCD, KHONG CO 2 DONG NAY LCD KO CHAY
   LCD_Init();
   delay_ms(10);
   
   WHILE(TRUE)
   {
      IF (!INPUT(UP))
      {
         DELAY_MS(10);
         IF (!INPUT(UP))
         {
            VAR++;
            DO{}WHILE (!INPUT(UP));
         }
      }
      
      IF (!INPUT(DW))
      {
         DELAY_MS(10);
         IF (!INPUT(DW))
         {
            VAR--;
            DO{}WHILE (!INPUT(DW));
         }
      }
      LCD_Gotoxy(0,0);
      LCD_PutChar(VAR/10 + 0X30);
      LCD_PutChar(VAR%10 + 0X30);
   }
}
