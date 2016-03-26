#include "bsp_adc.h"


int main(void)
{
    //TODO: MCU-specific init

    //-- init MCU-specific ADC stuff
    bsp_adc__init();

    //-- enter endless loop
    for (;;) {
        bsp_adc__proceed();
    }
}
