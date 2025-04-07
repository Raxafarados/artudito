#include <avr/io.h>

uint8_t read_pin(volatile uint8_t *PINx, uint8_t pin){
    if(*PINx & (1 << pin)){
         return 1; 
        } else return 0;
} ;

void write_pin(volatile uint8_t *PORTx, uint8_t pin, uint8_t value){
    if(value){
        *PORTx |= (1 << pin);
    } else {
        *PORTx &= ~(1 << pin);
    }
};