#include "gpiote.h"

void gpiote_init() {
    GPIOTE->CONFIG[0] = 1 | (13 << 8) | (1 << 17);
    GPIOTE->CONFIG[1] = 3 | (17 << 8) | (3 << 16) | (1 << 20);
    GPIOTE->CONFIG[2] = 3 | (18 << 8) | (3 << 16) | (1 << 20);
    GPIOTE->CONFIG[3] = 3 | (19 << 8) | (3 << 16) | (1 << 20);
    GPIOTE->CONFIG[4] = 3 | (20 << 8) | (3 << 16) | (1 << 20);
}
