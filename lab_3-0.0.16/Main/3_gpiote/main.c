#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"


int main() {
    button_init();
    led_init();
    gpiote_init();
    ppi_init();

    while(1) {
        // for(int i = 1; i<= 4; i++){
        //     int sleep = 1000000;
        //     GPIOTE->TASKS_OUT[i] = 1;
        //     while(--sleep);
        // }
        int sleep = 10000000;
        while(--sleep);

    }
    
    return 0;
}