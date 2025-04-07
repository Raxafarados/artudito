#include "main.h"

int main(void) {
  setup();

  // lcd_goto(0, 0);
  // lcd_write_str("Siema Joł");
  // lcd_goto(1, 0);
  // lcd_write_str("Bober kurwa");
  // lcd_goto(2,0);
  // lcd_write_str("xd");
  // lcd_goto(3,0);
  // lcd_write_str("skibidi pop");


  while (1) {
      write_pin(&PORTB,PB5,1);
      _delay_ms(500);
      write_pin(&PORTB,PB5,0);
      _delay_ms(500);
  }
}




void setup(){
  //lcd_init(LCD_ADDR);
  DDRB |= (1 << PB5);  // PB5(D13) jako wyjście 
  
}



//  |        PINY           |
//  |AVR      |     ARDUINO |
//  |---------|-------------|
//  |PB5      |     D13     |
//  |PB4      |     D12     |
//  |PB3      |     D11     |
//  |PB2      |     D10     |
//  |PB1      |     D9      |
//  |PB0      |     D8      |
//  |PD7      |     D7      |
//  |PD6      |     D6      |
//  |PD5      |     D5      |
//  |PD4      |     D4      |
//  |PD3      |     D3      |
//  |PD2      |     D2      |
//  |PD1      |     D1      |
//  |PD0      |     D0      |
