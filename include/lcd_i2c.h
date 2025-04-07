#ifndef LCD_I2C_H
#define LCD_I2C_H
#define LCD_ADDR 0x27

void lcd_init(uint8_t addr);
void lcd_write_cmd(uint8_t cmd);
void lcd_write_char(char chr);
void lcd_write_str(const char* str);
void lcd_goto(uint8_t row, uint8_t col);
void lcd_clear(void);

#endif
