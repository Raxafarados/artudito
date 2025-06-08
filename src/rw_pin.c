#include <avr/io.h>
#include "OUT_PORTx.h"

uint8_t read_pin(volatile uint8_t *PINx, uint8_t pin){
    if(*PINx & (1 << pin)){
         return 1; 
        } else return 0;
} ;

void write_pin(uint8_t OUT_PORT, uint8_t pin, uint8_t value){
    switch(OUT_PORT){
        case 0:
            write_pin_PORTB(pin, value);
            break;
        case 1:
            write_pin_PORTC(pin, value);
            break;
        case 2:
            write_pin_PORTD(pin, value);
            break;
        case 3:
            write_pin_PORTE(pin, value);
            break;
        case 4:
            write_pin_PORTF(pin, value);
            break;
    }
};

void write_pin_PORTB(uint8_t pin, uint8_t value){
    if(value){
        PORTB |= (1 << pin);
    } else {
        PORTB &= ~(1 << pin);
    }
};

void write_pin_PORTC(uint8_t pin, uint8_t value){
    if(value){
        PORTC |= (1 << pin);
    } else {
        PORTC &= ~(1 << pin);
    }
};

void write_pin_PORTD(uint8_t pin, uint8_t value){
    if(value){
        PORTD |= (1 << pin);
    } else {
        PORTD &= ~(1 << pin);
    }
};

void write_pin_PORTE(uint8_t pin, uint8_t value){
    if(value){
        PORTE |= (1 << pin);
    } else {
        PORTE &= ~(1 << pin);
    }
};

void write_pin_PORTF(uint8_t pin, uint8_t value){
    if(value){
        PORTF |= (1 << pin);
    } else {
        PORTF &= ~(1 << pin);
    }
};


void set_pin_in(volatile uint8_t *DDRx, uint8_t pin){
    *DDRx &= ~(1 << pin);
};

void set_pin_in_pullup(volatile uint8_t *DDRx, volatile uint8_t *PORTx, uint8_t pin){
    *DDRx &= ~(1 << pin);    // wejście
    *PORTx |= (1 << pin);    // podciągnięcie do Vcc
}

void set_pin_out(uint8_t OUT_PORT, uint8_t pin){
    switch(OUT_PORT){
        case 0:
            set_pin_out_PORTB(pin);
            break;
        case 1:
            set_pin_out_PORTC(pin);
            break;
        case 2:
            set_pin_out_PORTD(pin);
            break;
        case 3:
            set_pin_out_PORTE(pin);
            break;
        case 4:
            set_pin_out_PORTF(pin);
            break;
    }
};

void set_pin_out_PORTB(uint8_t pin){
    DDRB |= (1 << pin);
};

void set_pin_out_PORTC(uint8_t pin){
    DDRC |= (1 << pin);
};

void set_pin_out_PORTD(uint8_t pin){
    DDRD |= (1 << pin);
};

void set_pin_out_PORTE(uint8_t pin){
    DDRE |= (1 << pin);
};

void set_pin_out_PORTF(uint8_t pin){
    DDRF |= (1 << pin);
};