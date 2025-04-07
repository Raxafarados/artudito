#ifndef RW_PIN
#define RW_PIN
#include <stdint.h>

uint8_t read_pin(volatile uint8_t *PINx, uint8_t pin);
void write_pin(volatile uint8_t *PORTx, uint8_t pin, uint8_t value);//e.g. write_pin(&PORTB,PB5);


#endif