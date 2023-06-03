#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR1IF = 0x0C.0 //DAT CO NGAT TIMER1
#DEFINE UP PIN_A0
#DEFINE DW PIN_A1
#DEFINE STOP PIN_A2
#DEFINE INV PIN_A3
SIGNED INT16 CAPDO=0, n=1,BDT,X; 
/*
n: bien trung gian cua nut INV
bdt: bien trung gian timer1
x: bien xac dinh trang thai tang hay giam
*/
VOID HIENTHI_CAP_TOCDO ()
   {
      LCD_Gotoxy(0,0);
      LCD_PutChar("cap do");
      LCD_Gotoxy(0,9);
      LCD_PutChar(CAPDO/10 + 0X30);
      LCD_PutChar(CAPDO%10 + 0X30);
      IF (X == 0) {LCD_Gotoxy(1,6);LCD_PutChar("TANG");} 
      IF (X == 1) {LCD_Gotoxy(1,6);LCD_PutChar("GIAM");} 
   }
VOID PHIM_UP()
   {
      IF (!INPUT(UP))
      {
         DELAY_MS (20);
         IF(!INPUT(UP))
            {
            SETUP_CCP1(CCP_PWM);
            X=0;
            DO{}WHILE (!INPUT(UP));
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
         X=1;
         DO{}WHILE (!INPUT(DW));
         }
      }
      
}
VOID TANG()
{
            IF (CAPDO<10)
                  {
                  CAPDO++; SET_PWM1_DUTY(CAPDO*10);
                  HIENTHI_CAP_TOCDO ();
                  }
}
VOID GIAM()
{
            IF (CAPDO>0)
                  {
                  CAPDO--; SET_PWM1_DUTY(CAPDO*10);
                  HIENTHI_CAP_TOCDO ();
                  }
}
VOID PHIM_INV()
{
   IF (!INPUT(INV))
   {
      delay_ms(10);
      if(!input(INV))
      {
         OUTPUT_TOGGLE(PIN_C0);
         n++;
         DO {} WHILE (!INPUT(INV));
      }
   }
}
VOID PHIM_STOP()
{
   IF (!INPUT(STOP))
      {
         DELAY_MS(20);
         IF(!INPUT(STOP))
         {
         SETUP_CCP1(CCP_OFF);
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
   BDT=0; X=2; // dat x= may cung duoc, mien la dung bang 1 hay 0.
   //SET TRIS
   SET_TRIS_C(0X00); SET_TRIS_A(0XFF);SET_TRIS_D(0x00);
   //KHOI TAO LCD
   LCD_Init();
   delay_ms(10);
   //SETUP PWM
   SETUP_CCP1(CCP_PWM); //khoi tao chan CCP1 o che do PWM 
   setup_timer_2(T2_DIV_BY_16, 249, 1); //khoi tao pwm
   
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8); //khoi tao timer1
   SET_TIMER1(3036); //dat so xung ban dau cua timer1
   
   SET_PWM1_DUTY(CAPDO*10);
   
   HIENTHI_CAP_TOCDO ();
   WHILE(TRUE)
   {
      IF (TMR1IF==1) //KHI TRAN THI GIA TRI CO NGAT SE LEN 1
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
         
          IF (BDT == 10) //dem dc 1 giay
          {
          BDT=0;
          IF (X==0) {TANG();} //sang che do auto tang cap do pwm
          IF (X==1) {GIAM();} //sang che do auto giam cap do pwm
          HIENTHI_CAP_TOCDO ();
          }
      PHIM_UP();   
      PHIM_DW();
      PHIM_INV();
      PHIM_STOP();
      HIENTHI_CHIEU();
      }
   }
}
