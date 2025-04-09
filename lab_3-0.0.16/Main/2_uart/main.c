#include <stdint.h>
#include "uart.h"
#include "stdio.h"
#include <sys/types.h>

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
	return count;
}


void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
	// Fill inn the configuration for the remaining buttons 
}

int main(){
	uart_init();
	button_init();

	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	iprintf("The average grade in TTK%d was in %d was: %c\n\r", 4235, 2022, 'B');

	while(1){
		if((GPIO->IN & (1 << 13)) == 0) {
			char a = 'A';
			uart_send(a);
		}

		if((GPIO->IN & (1 << 14)) == 0) {
			char b = 'B';
			uart_send(b);
		}
		
		if(UART->EVENTS_RXDRDY) {
			char k = uart_read();
			uart_send(k);

			for(int i = 17; i <= 20; i++){
				if((GPIO->OUT & (1 << i)) == 0) {
					GPIO->OUTSET = (1 << i);
				}

				else if(GPIO->OUT & (1 << i)) {
					GPIO->OUTCLR = (1 << i);
				}
			}
		}

	}


	return 0;
}
