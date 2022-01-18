#include "CM_PER.h"
#include "GPIO.h"

void uDelay(int delay) {
    for (int i = 0; i < delay;i++) {
        for (volatile int j = 0; j < 1000;j++) {
            j = j;
        }
    }
}

int main(void) {
    int delay = 1000;
    CM_PER->CM_L4LS_CLKSTCTRL = 2; // Setup Clock to L4 Interconnect
    CM_PER->CM_L4LS_CLKCTRL = 0x01 << 1; // Turn clock to L4 interconnect as HIGH
    CM_PER->CM_GPIO1_CLKCTRL = 0x01 << 18 | 2; // Setup Clock from L4 interconnect to GPIO1
    GPIO1->GPIO_CTRL = 0; // Turn User LEDs to output
    GPIO1->GPIO_OE = 0;
    while (1){
        (GPIO1->GPIO_SETDATAOUT) = 0x01 << 21;
        uDelay(1000);
        (GPIO1->GPIO_SETDATAOUT) = 0x01 << 22;
        uDelay(1000);
        (GPIO1->GPIO_SETDATAOUT) = 0x01 << 23;
        uDelay(1000);
        (GPIO1->GPIO_SETDATAOUT) = 0x01 << 24;
        uDelay(1000);
        (GPIO1->GPIO_CLEARDATAOUT) = 0x01 << 24;
        uDelay(1000);
        (GPIO1->GPIO_CLEARDATAOUT) = 0x01 << 23;
        uDelay(1000);
        (GPIO1->GPIO_CLEARDATAOUT) = 0x01 << 22;
        uDelay(1000);
        (GPIO1->GPIO_CLEARDATAOUT) = 0x01 << 21;
        uDelay(1000);
    }
    return 0;
}