#include "main.h"

int main(void) {
  DDRB |= (1 << PB5);  // PB5 jako wyjście (LED na Arduino UNO)
  lcd_init(LCD_ADDR); //

  lcd_goto(0, 0);
  lcd_write_str("Siema Joł");
  lcd_goto(1, 0);
  lcd_write_str("Bober kurwa");
  lcd_goto(2,0);
  lcd_write_str("xd");
  lcd_goto(3,0);
  lcd_write_str("skibidi pop");


  while (1) {
      PORTB ^= (1 << PB5);  // Przełącz LED
      _delay_ms(500);
  }
}