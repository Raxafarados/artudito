#include <avr/io.h>
#include <util/delay.h>

const char *menu_strings[MENU_COUNT] = {
    "Main Menu",
    "Select Mode",
    "Select Mode Auto",
    "Select Mode Manual",
    "Capitan Log",
    "Capitan Log Error Log",
    "Capitan Log History",
    "Settings",
    "Settings Backup Time",
    "Settings Date"
};

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

void handle_menu_navigation() {
    if (read_pin(&PIND, PD5) == 0) { // BACK KEY
        menu_prev();
    } else if (read_pin(&PIND, PD6) == 0) { // ENTER KEY
        menu_select();
    } else if (read_pin(&PINB, PB4) == 0) { // DOWN KEY
        menu_next();
    } else if (read_pin(&PINB, PB5) == 0) { // UP KEY
        menu_prev();
    }
}

void display_menu() {
    lcd_clear();
    if (current_menu >= 0 && current_menu < MENU_COUNT) {
        lcd_write_str(menu_strings[current_menu]);
    } else {
        lcd_write_str("Unknown Menu");
    }
}

void menu_next() {
    if (current_menu < MENU_COUNT - 1) {
        current_menu++;
    } else {
        current_menu = 0; // Wracamy do początku
    }
    display_menu();
}
void menu_prev() {
    if (current_menu > 0) {
        current_menu--;
    } else {
        current_menu = MENU_COUNT - 1; // Wracamy do końca
    }
    display_menu();
}
void menu_select() {
    switch (current_menu) {
        case MENU_MAIN:
            current_menu = MENU_SELECT_MODE;
            break;
        case MENU_SELECT_MODE:
            current_menu = MENU_CAPITAN_LOG;
            break;
        case MENU_CAPITAN_LOG:
            current_menu = MENU_SETTINGS;
            break;
        case MENU_SETTINGS:
            current_menu = MENU_MAIN;
            break;
        default:
            break;
    }
    display_menu();
}
void menu_back() {
    switch (current_menu) {
        case MENU_SELECT_MODE:
            current_menu = MENU_MAIN;
            break;
        case MENU_CAPITAN_LOG:
            current_menu = MENU_SELECT_MODE;
            break;
        case MENU_SETTINGS:
            current_menu = MENU_CAPITAN_LOG;
            break;
        default:
            break;
    }
    display_menu();
}