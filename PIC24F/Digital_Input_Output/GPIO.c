#include "xc.h"
#include "GPIO.h"

void init_DigitalOutput (void)
{   
    LED0_INPUT;
    LED1_INPUT;
    LED2_INPUT;
    
    LED0_DIGITAL;
    LED1_DIGITAL;
    LED2_DIGITAL;
}