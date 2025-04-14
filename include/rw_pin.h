#ifndef RW_PIN
#define RW_PIN
#include <stdint.h>

uint8_t read_pin(volatile uint8_t *PINx, uint8_t pin);
void write_pin(volatile uint8_t *PORTx, uint8_t pin, uint8_t value);//e.g. write_pin(&PORTB,PB5);
void set_pin_in(volatile uint8_t *DDRx, uint8_t pin);//e.g. DDRD &= ~(1 << PD7); //d7 wejście
void set_pin_out(volatile uint8_t *DDRx, uint8_t pin);//e.g. DDRB |= (1 << PB5); //PB5(D9) jako wyjście 


#endif