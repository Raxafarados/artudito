#include "main.h"
//#include "UARTcomm.h"

uint8_t buttonUPlaststate= 1; // Stan przycisku UP na początku
uint8_t buttonDOWNlaststate= 1; // Stan przycisku DOWN na początku
uint8_t buttonBACKlaststate= 1; // Stan przycisku BACK na początku
uint8_t buttonENTERlaststate= 1; // Stan przycisku ENTER na początku
uint8_t diode1= 1; // Flaga diody, która będzie migać
uint8_t diode2 = 1; // Flaga diody, która będzie migać

int main() {
  setup();
  // UART initialization
  //uart_init();

  lcd_goto(0, 0);
  lcd_write_str("Kinda sus");
  lcd_goto(0, 10);
  lcd_write_char(2);

    write_pin(OUT_PORTC, PC6, 1);
    write_pin(OUT_PORTD, PD4, 1);


  _delay_ms(1000);
  lcd_clear(); 
  display_menu();
 
  while (1) {    
    



    handle_menu_navigation();

      
  }
  return 0;
}




void setup(){
  lcd_init(LCD_ADDR);
  set_pin_out(OUT_PORTC, PC6);  //ERROR DIODE
  set_pin_out(OUT_PORTD, PD4);  //ALERT DIODE

  

  set_pin_in_pullup(&DDRD, &PORTD, PD7);   //BACK KEY
  set_pin_in_pullup(&DDRD, &PORTE, PE6);   //ENTER KEY
  set_pin_in_pullup(&DDRB, &PORTB, PB4);   //DOWN KEY
  set_pin_in_pullup(&DDRB, &PORTB, PB5);   //UP KEY

  set_pin_out(OUT_PORTB, PB2);   //SELECT DISK
  set_pin_out(OUT_PORTB, PB6);   //POWER DISK
    
  
}
// to do zamienione power disk z select disk
//         ARDUINO
//       PRO MICRO
//
//  |        PINY           |
//  |AVR      |  PRO MICRO  |
//  |---------|-------------|
//  |PB0      |     D17     |  (SS)     (RXLED, nie wyprowadzony na header)
//  |PB1      |     D15     |  (SCK)
//  |PB2      |     D16     |  (MOSI)                                 [POWER DISK]
//  |PB3      |     D14     |  (MISO)
//  |PB4      |     D8      |  (TXLED, nie wyprowadzony na header)    [DOWN KEY]
//  |PB5      |     D9      |                                         [UP KEY]
//  |PC6      |     D5      |                                         [ERROR DIODE]
//  |PD0      |     D3      |   SCL   [Wyswietlacz LCD]
//  |PD1      |     D2      |   SDA   [Wyswietlacz LCD]
//  |PD2      |     D0      |  (RX)
//  |PD3      |     D1      |  (TX)
//  |PD4      |     D4      |                                         [ALERT DIODE]
//  |PD7      |     D6      |  (LED_BUILTIN na Pro Micro!)            [BACK KEY]
//  |PE6      |     D7      |                                         [ENTER KEY]
//  |PB6      |     D10     |                                         [SELECT DISK]
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
