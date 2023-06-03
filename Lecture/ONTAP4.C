#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE UP PIN_B2
#DEFINE DW PIN_B3
#DEFINE THUAN PIN_B0
#DEFINE NGHICH PIN_B1
SIGNED INT16 CAPDO,n=1;

VOID HIENTHI_CAP_TOCDO ()
   {
      LCD_Gotoxy(0,0);
      LCD_PutChar("cap do");
      LCD_Gotoxy(0,9);
      LCD_PutChar(CAPDO/10 + 0X30);
      LCD_PutChar(CAPDO%10 + 0X30);
   }
VOID PHIM_UP()
   {
      IF (!INPUT(UP))
      {
         DELAY_MS (10);
         IF(!INPUT(UP))
            {
            IF (CAPDO<10)
               {
                  CAPDO++; SET_PWM1_DUTY(CAPDO*100);
                  HIENTHI_CAP_TOCDO ();
                  DO {} WHILE (!INPUT(UP));//TRONG LUC NHAN NUT, SE KHONG BI THUC THI IF NHIEU LAN
               }
         }
      }
   }
VOID PHIM_DW ()
{
   IF (!INPUT(DW))
      {
      DELAY_MS (20);
      IF(!INPUT(DW))
         {
         IF (CAPDO>0)
            {
            CAPDO--;
            SET_PWM1_DUTY(CAPDO*100);
            HIENTHI_CAP_TOCDO ();
            DO{}WHILE (!INPUT(DW));
            }
         }
      }
}
VOID PHIM_THUAN()
{
   IF (!INPUT(THUAN))
      {
         DELAY_MS(10);
         IF(!INPUT(THUAN))
         {
            OUTPUT_HIGH(PIN_C3);
            OUTPUT_LOW(PIN_C4);
         }
      }
}
VOID PHIM_NGHICH()
{
   IF (!INPUT(NGHICH))
      {
         DELAY_MS(10);
         IF(!INPUT(NGHICH))
         {
            OUTPUT_LOW(PIN_C3);
            OUTPUT_HIGH(PIN_C4);
         }
      }
}

VOID MAIN()
{
   SET_TRIS_C(0X00); SET_TRIS_A(0XFF);
   SET_TRIS_D(0x00);
   LCD_Init();
   delay_ms(10);
   SETUP_CCP1(CCP_PWM);
   setup_timer_2(T2_DIV_BY_16, 249, 1);
   SET_PWM1_DUTY(0);
   HIENTHI_CAP_TOCDO ();
   WHILE(TRUE)
      {
         PHIM_UP();
         PHIM_DW();
         PHIM_THUAN();
         PHIM_NGHICH();
      }
}
