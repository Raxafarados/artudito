#ifndef DISK_MANAGEMENT_H
#define DISK_MANAGEMENT_H

#include <avr/io.h>
#include <util/delay.h>

void disk_power_on();
void disk_power_off();
void disk_selectA();
void disk_selectB();

#endif // DISK_MANAGEMENT_H