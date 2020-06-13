#include <msp430.h>
#include "Toggle.h"
#include "GPIO.h"

void ToggleLED (enum LED x)
{
    switch(x)
    {
    case LED0:
        TOGGLE_LED0;
        break;
    case LED1:
        TOGGLE_LED1;
        break;
    case LED2:
        TOGGLE_LED2;
        break;
    default:
        break;
    }
}
