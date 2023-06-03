#INCLUDE <LCD4CHAN(CUATHAY).C>
#BIT TMR1IF = 0x0C.0
#DEFINE UP PIN_b2
#DEFINE DW PIN_b3
#DEFINE Quay_thuan PIN_b0
#DEFINE Quay_nghich PIN_b1
SIGNED INT16 CAPDO;
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
                  DO {} WHILE (!INPUT(UP));
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
            DO{}WHILE (!INPUT(DW));
            }
}
      }
}
vOID quaythuan()
   {
      IF (!INPUT(quay_thuan))
      {
         DELAY_MS (20);
         IF(!INPUT(quay_thuan))
            {
            SETUP_CCP1(CCP_PWM);
           output_high(pin_c3);
           output_low(pin_c4);
           WHILE (!INPUT(quay_thuan));
            }
      }
    }
    vOID quaynghich()
   {
      IF (!INPUT(quay_nghich))
      {
         DELAY_MS (20);
         IF(!INPUT(quay_nghich))
            {
            SETUP_CCP1(CCP_PWM);
           output_high(pin_c4);
           output_low(pin_c3);
            DO{}WHILE (!INPUT(quay_nghich));
            }
      }
    }
VOID MAIN()
{
   SET_TRIS_C(0X00); 
   SET_TRIS_B(0XFF);
   SETUP_CCP1(CCP_PWM);
   setup_timer_2(T2_DIV_BY_16, 249, 1);
   SET_PWM1_DUTY(0);
WHILE(TRUE)
{  
PHIM_UP();
PHIM_DW ();
quaythuan();
quaynghich();
}
}            
