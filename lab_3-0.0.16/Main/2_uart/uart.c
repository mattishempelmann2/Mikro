#include "uart.h"


void uart_init(){
    GPIO->PIN_CNF[6] = 3;
    GPIO->PIN_CNF[8] = 2;
    UART->PSELTXD = (3 << 1);
    UART->PSELRXD = (1 << 3);
    UART->BAUDRATE = 0x00275000;
    UART->PSELRTS = 0xFFFFFFFF;
    UART->PSELCTS = 0xFFFFFFFF;
    UART->ENABLE = (1 << 2);
    UART->TASKS_STARTRX = 1; //usikker
}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = (uint32_t) letter;
    while(!(UART->EVENTS_TXDRDY));
    UART->EVENTS_TXDRDY = 0;
}

char uart_read(){
    if(!UART->EVENTS_RXDRDY){
        return '\0';
    }

    UART->EVENTS_RXDRDY = 0;
    return UART->RXD;
}