#ifndef RW_PIN
#define RW_PIN
#include <stdint.h>

uint8_t read_pin(volatile uint8_t *PINx, uint8_t pin);
void write_pin(uint8_t OUT_PORT, uint8_t pin, uint8_t value);
void write_pin_PORTB(uint8_t pin, uint8_t value);
void write_pin_PORTC(uint8_t pin, uint8_t value);
void write_pin_PORTD(uint8_t pin, uint8_t value);
void write_pin_PORTE(uint8_t pin, uint8_t value);
void write_pin_PORTF(uint8_t pin, uint8_t value);
void set_pin_in(volatile uint8_t *DDRx, uint8_t pin);
void set_pin_in_pullup(volatile uint8_t *DDRx, volatile uint8_t *PORTx, uint8_t pin); // e.g. set_pin_in_pullup(&DDRD, &PORTD, PD5);
void set_pin_out(uint8_t OUT_PORT, uint8_t pin);
void set_pin_out_PORTB(uint8_t pin);
void set_pin_out_PORTC(uint8_t pin);
void set_pin_out_PORTD(uint8_t pin);
void set_pin_out_PORTE(uint8_t pin);
void set_pin_out_PORTF(uint8_t pin);



#endif