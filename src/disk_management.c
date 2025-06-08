#include <avr/io.h>
#include "disk_management.h"
#include "rw_pin.h"
#include "OUT_PORTx.h"

void disk_power_on() {
    write_pin(OUT_PORTB, PB2, 1); // Power on the disk
}
void disk_power_off() {
    write_pin(OUT_PORTB, PB2, 0); // Power off the disk
}
void disk_selectA() {
    write_pin(OUT_PORTB, PB6, 0); // Select disk A
}
void disk_selectB() {
    write_pin(OUT_PORTB, PB6, 1); // Select disk B
}
