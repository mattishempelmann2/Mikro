#include "gpio.h"

void button_init() {
    GPIO->PIN_CNF[13] = (3 << 2);
}

void led_init(){
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}
}