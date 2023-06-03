#INCLUDE <LCD4CHAN(CUATHAY).C>
#DEFINE UP PIN_A0
#DEFINE DW PIN_A1
#DEFINE STOP PIN_A2
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
         DELAY_MS (20);
         IF(!INPUT(UP))
            {
            SETUP_CCP1(CCP_PWM);
            IF (CAPDO<10)
               {
                  CAPDO++; SET_PWM1_DUTY(CAPDO*10);
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
         SETUP_CCP1(CCP_PWM);
         IF (CAPDO>0)
            {
            CAPDO--;
            SET_PWM1_DUTY(CAPDO*10);
            HIENTHI_CAP_TOCDO ();
            DO{}WHILE (!INPUT(DW));
            }
         }
      }
}
VOID PHIM_STOP()
{
   IF (!INPUT(STOP))
      {
         DELAY_MS(50);
         IF(!INPUT(STOP))
         {
         SETUP_CCP1(CCP_OFF);
         n++;  
         OUTPUT_TOGGLE(PIN_C0);
         DO{}WHILE (!INPUT(STOP));
         }
      }
}
VOID HIENTHI_CHIEU()
{
 IF (n%2 == 0)
   {
   LCD_Gotoxy(1,1);
   LCD_PutChar("REV");
   }
 ELSE 
   {
   LCD_Gotoxy(1,1);
   LCD_PutChar("FOR");
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
   SET_PWM1_DUTY(CAPDO*10);
   OUTPUT_HIGH(PIN_C0);
   HIENTHI_CAP_TOCDO ();
   WHILE(TRUE)
      {
         PHIM_UP();
         PHIM_DW();
         PHIM_STOP();
         HIENTHI_CHIEU();
      }
}
