#INCLUDE <16F887.H>
#DEVICE ADC=10
#FUSES NOWDT, PUT, HS, NOPROTECT, NOLVP
#USE DELAY(CLOCK=20M)
UNSIGNED CHAR MA7DOAN [16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,
0x80,0x90,0x88,0x83,0XC6,0xA1,0x86,0x8E};
#ifndef _LCD_
#define _LCD_
#define LCD_RS PIN_D1                        
#define LCD_RW PIN_D2
#define LCD_EN PIN_D3
#define LCD_D4 PIN_D4                
#define LCD_D5 PIN_D5
#define LCD_D6 PIN_D6
#define LCD_D7 PIN_D7
#endif
void LCD_Enable(void)
{
output_high(LCD_EN);
delay_us(3);
output_low(LCD_EN);
delay_us(50);
}
void LCD_Send4Bit( unsigned char Data )
{
output_bit(LCD_D4,Data&0x01);
output_bit(LCD_D5,(Data>>1)&1);
output_bit(LCD_D6,(Data>>2)&1);
output_bit(LCD_D7,(Data>>3)&1);
}
void LCD_SendCommand (unsigned char command )
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

//VOID MAIN(){
 
//SET_TRIS_D(0x00);
//LCD_Init();
//delay_ms(10);

//LCD_Gotoxy(0,0);
//LCD_PutChar(" DH SP KY THUAT ");
///LCD_Gotoxy(1,0);

//LCD_PutChar(" TP HO CHI MINH ");
//while(TRUE) {}
//}
