#ifndef UARTCOMM_H
#define UARTCOMM_H

#include <avr/io.h>

void uart_init(void);                   //Initialize connection
void queueUARTcommand(char cmd[20]);    //Send command - remember to use standard "/******!" - where *** is command text, "/" - beggining of command, "!" - end of command
int returnStatusOfCommand();            //Command statuses: 0 - waiting for new command, 1 - reciving command, 2 - command received succesfully, 3 - error during reciving command
int returnReceivedCommand(char *str);   //Return recived value of command in standard "/*******!"
void resetCommand();                    //Reset status of command - required if an error occured

#endif // UART_H