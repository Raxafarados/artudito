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

  uint8_t butt1;
 
  while (1) {
    

      butt1 = read_pin(&PIND, PD7);
      


      write_pin(&PORTB,PB5,butt1);
      
  }
}


//      TODO
//  1. Wprowadzić SetPinIn / SetPinOut

void setup(){
  //lcd_init(LCD_ADDR);
  DDRB |= (1 << PB5);  // PB5(D13) jako wyjście 
  DDRB |= (1 << PB4);  // d12 wyjście
  DDRD &= ~(1 << PD7); //d7 wejście
  DDRD &= ~(1 << PD6); // d6 wejście

  PORTD |= (1 << PD7); //pull-up
  
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
