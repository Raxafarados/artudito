#include <avr/io.h>
#define F_SCL 100000UL // 100kHz
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

void i2c_init(void) {
    TWSR = 0x00;
    TWBR = (uint8_t)TWBR_val;
}

void i2c_start(void) {
    TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
    while (!(TWCR & (1<<TWINT)));
}

void i2c_stop(void) {
    TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
}

void i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
}