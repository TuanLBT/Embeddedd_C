#INCLUDE <16F887.H>
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
#ifndef LCD
#define LCD
#define LCD_RS PIN_D1                        
#define LCD_RW PIN_D2
#define LCD_EN PIN_D3
#define LCD_D4 PIN_D4                
#define LCD_D5 PIN_E0
#define LCD_D6 PIN_E1
#define LCD_D7 PIN_E2
#endif
void LCD_Enable(void)
{
   output_high(LCD_EN);
   delay_us(3);
   output_low(LCD_EN);
   delay_us(50);
}
void LCD_Send4Bit( unsigned char Data ) //KHAI BAO DU LIEU DATA GOM 8 BIT, GIOI HAN TU 0:225
{
   output_bit(LCD_D4,Data&0x01); //XUAT GIA TRI SAO KHI SO SANH DATA VOI 0X01
   output_bit(LCD_D5,(Data>>1)&1); //DICH GIA TRI DATA SANG PHAI 1 BIT VA AND VOI 1 (KQ SE LA 1)
   output_bit(LCD_D6,(Data>>2)&1); // DICH SANG 2 VA.... KQ TUONG TU
   output_bit(LCD_D7,(Data>>3)&1); //DICH SANG 3 VA.... KQ TUONG TU
   // MUC DICH CUA 4 DONG TREN CHI LA DUA GIA TRI BIT 1 VAO CAC CHAN LCD
} 
void LCD_SendCommand (unsigned char command ) //KHAI BAO DU LIEU command GOM 8 BIT, GIOI HAN TU 0:225
{
   LCD_Send4Bit  ( command >>4 );// Gui 4 bit cao 
   LCD_Enable () ;
   LCD_Send4Bit  ( command  );   // Gui 4 bit thap
   LCD_Enable () ;
}
void LCD_Init (void)
{
   output_low(LCD_RS);
   output_low(LCD_RW);
   delay_ms(20);
   
   LCD_Send4Bit(0x03);
   LCD_Enable();
   delay_ms(10);
   
   LCD_Send4Bit(0x03);
   LCD_Enable();
   delay_ms(10);
   
   LCD_Send4Bit(0x03);
   LCD_Enable();
   delay_ms(10);
   
   LCD_Send4Bit(0x02);
   LCD_Enable();
   delay_ms(10);
   
   LCD_SendCommand( 0x28 );      // giao thuc 4 bit, hien thi 2 hang, ki tu 5?8  
                                    //Function Set: 8-bit, 1 Line, 5?7 Dots   0x30
                                    //Function Set: 8-bit, 2 Line, 5?7 Dots   0x38
                                    //Function Set: 4-bit, 1 Line, 5?7 Dots   0x20
                                    //Function Set: 4-bit, 2 Line, 5?7 Dots   0x28
   LCD_SendCommand( 0x0C);    //Display on Cursor on: 0x0E   0x0F
                                  //Display on Cursor off: 0x0C
                                  //Display on Cursor blinking: 0x0F
   LCD_SendCommand( 0x06 );   // tang ID, khong dich khung hinh  Entry Mode
   LCD_SendCommand( 0x01 );   //  Clear Display  (also clear DDRAM content)
   delay_ms(10);
}
void LCD_PutChar ( unsigned char Data )
{
   output_high(LCD_RS);
   LCD_SendCommand( Data );
   output_low(LCD_RS);
}

void LCD_Clear()
{
  LCD_SendCommand(0x01);  
  delay_ms(10);
}
void LCD_Gotoxy(unsigned char row, unsigned char col)
{
  unsigned char address;
  if(!row)
  address = (0x80 + col);
  else
  address = (0xC0 + col);
  delay_us(500);
  LCD_SendCommand(address);
  delay_us(50);
}

void LCD_PutString (char *s)
{
    //thuc hien gui tung ki tu len LCD
   while (*s)   
   {
      LCD_PutChar(*s);
      s++;
   }
}
