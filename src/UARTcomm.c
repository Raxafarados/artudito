#include "../include/UARTcomm.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>


//Configuraton: UART
#define BAUD     9600UL
#define UBRR_VAL ((F_CPU/16/BAUD) - 1)   // 16-clk, mode normal
#define F_CPU 16000000UL 


//Variables: UART
const int UARTbufferSize=20;    //When changing buffer size, please remember to change this value into 'UARTbuffer' variable and 'UARTsendBuffer'
int UARTbufferPointer=0;
char UARTbuffer[20];     
char UARTsendBuffer[20];       
int commandStatus=0;            //Command statuses: 0 - waiting for new command, 1 - reciving command, 2 - command received succesfully, 3 - error during reciving command
int commandSendStatus=0;        //Command in queue: 0 - nothing to do, 1 - command queued 

// UART1 initialization
void uart_init(void)
{
    // Set baud rate
    UBRR1H = (uint8_t)(UBRR_VAL >> 8);
    UBRR1L = (uint8_t)UBRR_VAL;

    UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
    UCSR1B = (1 << RXEN1) | (1 << TXEN1);

    sei();  // Enable global interrupts

    // Clear UART buffer
    for (int i = 0; i < UARTbufferSize; i++) {
        UARTbuffer[i] = 0;
    }
}


void uart_send_byte(uint8_t c)
{
    while (!(UCSR1A & (1 << UDRE1)));
    UDR1 = c;
}


void sendUART(const char *s)
{
    while (*s) uart_send_byte(*s++);
}

void queueUARTcommand(char cmd[20])
{
    strcpy(UARTsendBuffer,cmd);
    commandSendStatus=1;
}




int returnReceivedCommand(char *str){
    if(commandStatus==2){
        //If command is waiting to receive
        strcpy(str, UARTbuffer);
        commandStatus=0;
        return 1;
    }else{
        //If command is not ready
        return 0;
    }
}

void resetCommand(){
    //Clear UART buffer
    for(int i=0; i<UARTbufferSize;i++){
        UARTbuffer[i]=0;
    }
    UARTbufferPointer=0;
}


int returnStatusOfCommand(){
    return commandStatus;
}




// UART Interrupt function
ISR(USART0_RX_vect)
{
    uint8_t received = UDR1;  // Read UART data from buffer (Warning - it's only one char)

    switch(commandStatus){
        case 0: //Status: waiting for receive command
            if(received=='/'){
                //Mark as reciving command
                commandStatus=1;

                //Clean buffer
                for(int i=0; i<UARTbufferSize;i++){
                    UARTbuffer[i]=0;
                }

                //Start reciving command
                UARTbufferPointer=0;
                UARTbuffer[UARTbufferPointer]=received;
                UARTbufferPointer++;
            }
            break;
        case 1:  //Status: reciving command
            //Save char in array
            UARTbuffer[UARTbufferPointer]=received;

            //Check if is end of command
            if(received=='!'){
                //Check if command is from checking connection
                if(strcmp(UARTbuffer,"/RUOK!") == 0 ){
                    sendUART("/IMHERE!");
                    resetCommand();
                    commandStatus=0;

                    _delay_ms(10);

                    //If controller have to send command
                    if(commandSendStatus){
                        sendUART(UARTsendBuffer);
                    }

                }else{
                    //Mark status as received
                    sendUART("/OK!");
                    commandStatus=2;
                }
            }else if(received=='/'){
                //Mark as reciving command
                commandStatus=1;

                //Clean buffer
                for(int i=0; i<UARTbufferSize;i++){
                    UARTbuffer[i]=0;
                }

                //Start reciving command
                UARTbufferPointer=0;
                UARTbuffer[UARTbufferPointer]=received;
                UARTbufferPointer++;
            }else{
                if(UARTbufferPointer<UARTbufferSize){
                    UARTbufferPointer++;
                }else{
                    //Too long command received
                    commandStatus=3;
                    sendUART("/NOK!");
                }
            }
            break;  
    }

    if(commandStatus==2){ //If command is received and is in out of user control range
        if(strcmp(UARTbuffer,"/RUNA!") == 0 ){
            //Run disk A
            resetCommand();
            commandStatus=0;
            sendUART("/RUNNEDA!");

        }else if(strcmp(UARTbuffer,"/RUNB!") == 0 ){
            //Run disk B
            resetCommand();
            commandStatus=0;
            sendUART("/RUNNEDB!");

        }else if(strcmp(UARTbuffer,"/ZZZ!") == 0 ){
            //Disable all disks
            resetCommand();
            commandStatus=0;

        }
    }


}



            

