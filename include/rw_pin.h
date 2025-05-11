#ifndef RW_PIN
#define RW_PIN
#include <stdint.h>

uint8_t read_pin(volatile uint8_t *PINx, uint8_t pin);
void write_pin(volatile uint8_t *PORTx, uint8_t pin, uint8_t value);//e.g. write_pin(&PORTB,PB5);
void set_pin_in(volatile uint8_t *DDRx, uint8_t pin);
void set_pin_in_pullup(volatile uint8_t *DDRx, volatile uint8_t *PORTx, uint8_t pin); // e.g. set_pin_in_pullup(&DDRD, &PORTD, PD5);
void set_pin_out(volatile uint8_t *DDRx, uint8_t pin);//e.g. set_pin_out(&DDRD, PD4);


#endif