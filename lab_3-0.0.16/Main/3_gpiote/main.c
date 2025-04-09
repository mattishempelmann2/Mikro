#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

void gpiote_init() {
    GPIOTE->CONFIG[0] = 1 | (13 << 8) | (1 << 17);
    GPIOTE->CONFIG[1] = 3 | (17 << 8) | (3 << 16) | (1 << 20);
    GPIOTE->CONFIG[2] = 3 | (18 << 8) | (3 << 16) | (1 << 20);
    GPIOTE->CONFIG[3] = 3 | (19 << 8) | (3 << 16) | (1 << 20);
    GPIOTE->CONFIG[4] = 3 | (20 << 8) | (3 << 16) | (1 << 20);
}

void button_init() {
    GPIO->PIN_CNF[13] = (3 << 2);
}

void led_init(){
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}
}

int main() {


    button_init();
    gpiote_init();
    led_init();

    while(1) {
        for(int i = 1; i<= 4; i++){
            int sleep = 1000000;
            GPIOTE->TASKS_OUT[i] = 1;
            while(--sleep);
        }

    }
    
    return 0;
}