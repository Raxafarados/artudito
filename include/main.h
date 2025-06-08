#ifndef MAIN_H
#define MAIN_H
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "i2c.h"
#include "lcd_i2c.h"
#include "rw_pin.h"
#include "nav_menu.h"
#include "OUT_PORTx.h"


void setup();

#endif // MAIN_H