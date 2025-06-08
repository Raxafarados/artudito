#include <avr/io.h>
#include <util/delay.h>
#include "rw_pin.h"
#include "OUT_PORTx.h"


extern uint8_t buttonUPlaststate;
extern uint8_t buttonDOWNlaststate;
extern uint8_t buttonBACKlaststate;
extern uint8_t buttonENTERlaststate;


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

const char *menu_strings[MENU_COUNT+1] = {
    "Main Menu",
    "Select Mode",
    "Auto",
    "Manual",
    "Capitan Log",
    "Error Log",
    "History",
    "Settings",
    "Backup Time",
    "Date",
    ""
};



MenuState current_menu = MENU_MAIN;
MenuState previous_menu = MENU_COUNT;




void handle_menu_navigation() {
    if (       read_pin(&PIND, PD7) == 0 && buttonBACKlaststate == 1) { // BACK KEY
        menu_back();
        lcd_clear();
        display_menu();
    } else if (read_pin(&PINE, PE6) == 0 && buttonENTERlaststate == 1) { // ENTER KEY
        menu_select();
        lcd_clear();
        display_menu();
    } else if (read_pin(&PINB, PB4) == 0 && buttonDOWNlaststate == 1) { // DOWN KEY
        menu_next();
        lcd_clear();
        display_menu();
    } else if (read_pin(&PINB, PB5) == 0 && buttonUPlaststate == 1) { // UP KEY
        menu_prev();
        lcd_clear();
        display_menu();
    }
    // Aktualizacja stanu przycisków
    buttonUPlaststate = read_pin(&PINB, PB5);
    buttonDOWNlaststate = read_pin(&PINB, PB4);
    buttonENTERlaststate = read_pin(&PINE, PE6);
    buttonBACKlaststate = read_pin(&PIND, PD7);
    _delay_ms(100); // Debounce delay

}

void display_menu() {
    
    if (current_menu >= 0 && current_menu < MENU_COUNT) {
        lcd_goto(0, 0);
        lcd_write_char(1); // Previous menu
        lcd_write_str(menu_strings[previous_menu]);
        lcd_goto(1, 0);
        lcd_write_char(2); // Current menu
        lcd_write_str(menu_strings[current_menu]);
    } else {
        lcd_write_str("Unknown Menu");
    }
}

void menu_next() {
    switch (current_menu) {
        //FIRST LEVEL
        case MENU_SELECT_MODE:
            current_menu = MENU_CAPITAN_LOG;
            break;
        case MENU_CAPITAN_LOG:
            current_menu = MENU_SETTINGS;
            break;
        case MENU_SETTINGS:
            current_menu = MENU_SELECT_MODE;
            break;
        //SECOND LEVEL
            //SUB MENU SELECT_MODE
        case MENU_SELECT_MODE_AUTO:
            current_menu = MENU_SELECT_MODE_MANUAL;
            break;
        case MENU_SELECT_MODE_MANUAL:
            current_menu = MENU_SELECT_MODE_AUTO;
            break;
            //SUB MENU CAPITAN_LOG
        case MENU_CAPITAN_LOG_ERROR_LOG:
            current_menu = MENU_CAPITAN_LOG_HISTORY;
            break;
        case MENU_CAPITAN_LOG_HISTORY:
            current_menu = MENU_CAPITAN_LOG_ERROR_LOG;
            break;
            //SUB MENU SETTINGS
        case MENU_SETTINGS_BACKUP_TIME:
            current_menu = MENU_SETTINGS_DATE;
            break;
        case MENU_SETTINGS_DATE:
            current_menu = MENU_SETTINGS_BACKUP_TIME;
            break;
        default:
            current_menu = MENU_MAIN; // Wracamy do głównego menu
            break;
    } 
    
}
void menu_prev() {
    switch (current_menu) {
        //FIRST LEVEL
        case MENU_SELECT_MODE:
            current_menu = MENU_SETTINGS;
            break;
        case MENU_CAPITAN_LOG:
            current_menu = MENU_SELECT_MODE;
            break;
        case MENU_SETTINGS:
            current_menu = MENU_CAPITAN_LOG;
            break;
        //SECOND LEVEL
            //SUB MENU SELECT_MODE
        case MENU_SELECT_MODE_AUTO:
            current_menu = MENU_SELECT_MODE_MANUAL;
            break;
        case MENU_SELECT_MODE_MANUAL:
            current_menu = MENU_SELECT_MODE_AUTO;
            break;
            //SUB MENU CAPITAN_LOG
        case MENU_CAPITAN_LOG_HISTORY:
            current_menu = MENU_CAPITAN_LOG_ERROR_LOG;
            break;
        case MENU_CAPITAN_LOG_ERROR_LOG:
            current_menu = MENU_CAPITAN_LOG_HISTORY;
            break;
            //SUB MENU SETTINGS
        case MENU_SETTINGS_BACKUP_TIME:
            current_menu = MENU_SETTINGS_DATE;
            break;
        case MENU_SETTINGS_DATE:
            current_menu = MENU_SETTINGS_BACKUP_TIME;
            break;
        default:
            current_menu = MENU_MAIN; // Wracamy do głównego menu
            break;
    }

    
}
void menu_select() {
    switch (current_menu) {
        //ZERO LEVEL
        case MENU_MAIN:
            current_menu = MENU_SELECT_MODE;
            previous_menu= MENU_MAIN;
            break;
        //FIRST LEVEL
        case MENU_CAPITAN_LOG:
            current_menu = MENU_CAPITAN_LOG_HISTORY;
            previous_menu= MENU_CAPITAN_LOG;
            break;
        case MENU_SETTINGS:
            current_menu = MENU_SETTINGS_BACKUP_TIME;
            previous_menu= MENU_SETTINGS;
            break;        
        case MENU_SELECT_MODE:
            current_menu = MENU_SELECT_MODE_AUTO;
            previous_menu= MENU_SELECT_MODE;
            break;

                    //sub menu auto/manual
        case MENU_SELECT_MODE_AUTO:
            write_pin(OUT_PORTB, PB2, 1);
            break;
        case MENU_SELECT_MODE_MANUAL:
            write_pin(OUT_PORTB, PB2, 0);
            break;

                    //sub menu err/hist
        case MENU_CAPITAN_LOG_ERROR_LOG:
            write_pin(OUT_PORTB, PB6, 0);
            break;
        case MENU_CAPITAN_LOG_HISTORY:
            write_pin(OUT_PORTB, PB6, 1);
            break;
        default:
            break;
    }
    
}
void menu_back() {
    switch (current_menu) {
        //FIRST LEVEL
        case MENU_SELECT_MODE:
            current_menu = MENU_MAIN;
            previous_menu= MENU_COUNT;
            break;
        case MENU_CAPITAN_LOG:
            current_menu = MENU_MAIN;
            previous_menu= MENU_COUNT;
            break;
        case MENU_SETTINGS:
            current_menu = MENU_MAIN;
            previous_menu= MENU_COUNT;
            break;
        //SECOND LEVEL
            //SUB MENU SELECT_MODE
        case MENU_SELECT_MODE_AUTO:
            current_menu = MENU_SELECT_MODE;
            previous_menu= MENU_MAIN;
            break;
        case MENU_SELECT_MODE_MANUAL:
            current_menu = MENU_SELECT_MODE;
            previous_menu= MENU_MAIN;
            break;
            //SUB MENU CAPITAN_LOG
        case MENU_CAPITAN_LOG_ERROR_LOG:
            current_menu = MENU_CAPITAN_LOG;
            previous_menu= MENU_MAIN;
            break;
        case MENU_CAPITAN_LOG_HISTORY:
            current_menu = MENU_CAPITAN_LOG;
            previous_menu= MENU_MAIN;
            break;
            //SUB MENU SETTINGS
        case MENU_SETTINGS_BACKUP_TIME:
            current_menu = MENU_SETTINGS;
            previous_menu= MENU_MAIN;
            break;
        case MENU_SETTINGS_DATE:
            current_menu = MENU_SETTINGS;
            previous_menu= MENU_MAIN;
            break;
        
        default:
            current_menu = MENU_MAIN;
            previous_menu= MENU_COUNT;
            break;
    }
    
    
}