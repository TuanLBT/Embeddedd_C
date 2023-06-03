#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR1IF = 0x0C.0 
#DEFINE TIEN PIN_A0
#DEFINE LUI PIN_A1
#DEFINE TRAI PIN_A2
#DEFINE PHAI PIN_A3
SIGNED INT16 CAPDO=0,BDT=0,i=0;
VOID KIEM_TRA()
{
   IF (INPUT(TIEN)&&INPUT(LUI)&&INPUT(TRAI)&&INPUT(PHAI))
   {  
      CAPDO=0;
      SETUP_CCP1(CCP_OFF); OUTPUT_LOW(PIN_C1);
      SETUP_CCP2(CCP_OFF); OUTPUT_LOW(PIN_C2);
   }
}
VOID HIENTHI_CAP_TOCDO ()
   {
      LCD_Gotoxy(0,0);
      LCD_PutChar("cap do");
      LCD_Gotoxy(0,9);
      LCD_PutChar(CAPDO/10 + 0X30);
      LCD_PutChar(CAPDO%10 + 0X30);
   }
VOID TIEN_LEN()
{
   IF (!INPUT(TIEN))
   {
      DELAY_MS(20);
      IF (!INPUT(TIEN))
      {  
         LCD_Gotoxy(1,1);
         LCD_PutChar("for");
         OUTPUT_HIGH(PIN_C3);
         OUTPUT_HIGH(PIN_C4);
         SETUP_CCP1(CCP_PWM);
         SETUP_CCP2(CCP_PWM);
         SET_PWM1_DUTY(CAPDO*10);
         SET_PWM2_DUTY(CAPDO*10);
         IF (CAPDO<10)
         {
            CAPDO++;
            HIENTHI_CAP_TOCDO ();
         }
      }
   }
}
VOID DI_LUI()
{
   IF (!INPUT(LUI))
   {
      DELAY_MS(20);
      IF (!INPUT(LUI))
      {  
         LCD_Gotoxy(1,1);
         LCD_PutChar("var");
         OUTPUT_LOW(PIN_C3);
         OUTPUT_LOW(PIN_C4);
         SETUP_CCP1(CCP_PWM);
         SETUP_CCP2(CCP_PWM);
         SET_PWM1_DUTY(CAPDO*10);
         SET_PWM2_DUTY(CAPDO*10);
         IF (CAPDO<10)
         {
            CAPDO++;

            HIENTHI_CAP_TOCDO ();
         }
      }
   }
}
VOID DI_PHAI()
{
   IF (!INPUT(PHAI))
   {
      DELAY_MS(20);
      IF (!INPUT(PHAI))
         {
            LCD_Gotoxy(1,1);
            LCD_PutChar("REPHAI");
            IF (CAPDO<10)
            {
               CAPDO++;i++;            
               SETUP_CCP1(CCP_PWM);
               SETUP_CCP2(CCP_PWM);
               SET_PWM1_DUTY((CAPDO - i + 1)*10);
               SET_PWM2_DUTY(CAPDO*10);
               HIENTHI_CAP_TOCDO ();
            }
         }
   }
}
VOID DI_TRAI()
{
   IF (!INPUT(TRAI))
   {
      DELAY_MS(20);
      IF (!INPUT(TRAI))
         {
            LCD_Gotoxy(1,1);
            LCD_PutChar("RETRAI");
            IF (CAPDO<10)
            {
               CAPDO++;i++;            
               SETUP_CCP1(CCP_PWM);
               SETUP_CCP2(CCP_PWM);
               SET_PWM2_DUTY((CAPDO - i + 1)*10);
               SET_PWM1_DUTY(CAPDO*10);
               HIENTHI_CAP_TOCDO ();
            }
         }
   }
}
VOID MAIN()
{
   SET_TRIS_C(0X00); SET_TRIS_A(0XFF);
   OUTPUT_C(0XF9);
   LCD_Init();
   delay_ms(10);
   SETUP_CCP1(CCP_PWM);
   SETUP_CCP2(CCP_PWM);
   setup_timer_2(T2_DIV_BY_16, 249, 1);
   SET_PWM1_DUTY(CAPDO*10);
   SET_PWM2_DUTY(CAPDO*10);
   
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8); //khoi tao timer1
   SET_TIMER1(3036);
   HIENTHI_CAP_TOCDO ();
   WHILE(TRUE)
   {
   IF (TMR1IF==1) //KHI TRAN THI GIA TRI CO NGAT SE LEN 1
      {
         TMR1IF=0; SET_TIMER1(3036); BDT++;
         
          IF (BDT == 10) //dem dc 1/2 giay
          {
          BDT=0;
          TIEN_LEN();
          DI_LUI();  
          DI_PHAI();
          DI_TRAI();
          }
      }
    KIEM_TRA();
   }
}
