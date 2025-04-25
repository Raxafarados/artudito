#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "i2c.h"
#include "lcd_i2c.h"
#include "rw_pin.h"


void setup();

typedef enum {
    MENU_MAIN,
        MENU_SELECT_MODE,
            MENU_SELECT_MODE_AUTO,
            MENU_SELECT_MODE_MANUAL,
        MENU_CAPITAN_LOG,
            MENU_CAPITAN_LOG_ERROR_LOG,
            MENU_CAPITAN_LOG_HISTORY,
        MENU_SETTINGS,
            MENU_SETTINGS_BACKUP_TIME,
            MENU_SETTINGS_DATE,
    MENU_COUNT // ostatnia wartość — ilość elementów
} MenuState;

MenuState current_menu = MENU_MAIN;