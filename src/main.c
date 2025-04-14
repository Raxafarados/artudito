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

  //uint8_t butt1;
 
  while (1) {

    write_pin(&PORTD,PD5,1);
    _delay_ms(500);
    write_pin(&PORTD,PD5,0);
    _delay_ms(500);
      
  }
}


//      TODO
//  1. Wprowadzić SetPinIn / SetPinOut

void setup(){
  //lcd_init(LCD_ADDR);
  set_pin_out(&DDRD, PD5);

  //PORTD |= (1 << PD7); //pull-up
}

//         ARDUINO
//       PRO MICRO
//
//  |        PINY           |
//  |AVR      |  ARDUINO    |
//  |---------|-------------|
//  |PB0      |     D17     |  (SS)     (RXLED, nie wyprowadzony na header)
//  |PB1      |     D15     |  (SCK)
//  |PB2      |     D16     |  (MOSI)
//  |PB3      |     D14     |  (MISO)
//  |PB4      |     D8      |  (TXLED, nie wyprowadzony na header)
//  |PB5      |     D9      |
//  |PC6      |     D5      |
//  |PD0      |     D3      |
//  |PD1      |     D2      |
//  |PD2      |     D0      |  (RX)
//  |PD3      |     D1      |  (TX)
//  |PD4      |     D4      |
//  |PD5      |     D6      |  (LED_BUILTIN na Pro Micro!)
//  |PD6      |     D7      |
//  |PD7      |     D10     |
//  |PE6      |     D7      |  (tak, też czasem jako alternatywa)
//  |PF4      |     A3      |
//  |PF5      |     A2      |
//  |PF6      |     A1      |
//  |PF7      |     A0      |

//         ARDUINO
//           UNO
//  
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
