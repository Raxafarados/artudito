#include "i2c.h"
#include <util/delay.h>
#include <avr/io.h>

static uint8_t lcd_addr;
static uint8_t backlight = 0x08; // Backlight ON

uint8_t smiley[8] = {
    0b00000,
    0b01010,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
  };

  uint8_t gtfback[8] = {
    0b00100,
    0b01110,
    0b11111,
    0b00100,
    0b00100,
    0b00111,
    0b00000,
    0b00000
  };

  uint8_t amogus[8] = {
    0b00000,
    0b01110,
    0b00010,
    0b01111,
    0b01111,
    0b01110,
    0b01010,
    0b00000
  };

void lcd_send(uint8_t data, uint8_t rs) {
    uint8_t high = data & 0xF0;
    uint8_t low = (data << 4) & 0xF0;

    uint8_t data_arr[4] = {
        high | rs | backlight | 0x04,
        high | rs | backlight,
        low | rs | backlight | 0x04,
        low | rs | backlight
    };
    
    i2c_start();
    i2c_write(lcd_addr);
    for (uint8_t i = 0; i < 4; i++) {
        i2c_write(data_arr[i]);
    }
    i2c_stop();
    _delay_ms(2);
}

void lcd_write_cmd(uint8_t cmd) {
    lcd_send(cmd, 0);
}

void lcd_write_char(char chr) {
    lcd_send(chr, 1);
}

void lcd_write_str(const char* str) {
    while (*str) {
        lcd_write_char(*str++);
    }
}

void lcd_clear(void) {
    lcd_send(0x01, 0);
    _delay_ms(2);
}

void lcd_goto(uint8_t row, uint8_t col) {
    uint8_t addr[] = {0x00, 0x40, 0x14, 0x54}; // dla LCD 20x4
    lcd_write_cmd(0x80 | (addr[row] + col));
}

void lcd_init(uint8_t addr) {
    lcd_addr = addr << 1;
    i2c_init();
    _delay_ms(50);

    lcd_send(0x30, 0);
    _delay_ms(5);
    lcd_send(0x30, 0);
    _delay_ms(1);
    lcd_send(0x30, 0);
    _delay_ms(10);
    lcd_send(0x20, 0); // 4-bit mode

    lcd_write_cmd(0x28); // 2 lines
    lcd_write_cmd(0x0C); // Display ON
    lcd_write_cmd(0x06); // Entry mode
    lcd_write_cmd(0x01); // Clear
    _delay_ms(2);
///     Custom chars
    lcd_write_cmd(0x40);
    for (int i = 0; i < 8; i++)
        lcd_write_char(smiley[i]);// char 0
    for (int i = 0; i < 8; i++)
        lcd_write_char(gtfback[i]);//char 1
    for (int i = 0; i < 8; i++)
        lcd_write_char(amogus[i]);//char 2

    lcd_write_cmd(0x80);
}


