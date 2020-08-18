#include "xc.h"
#include "TOGGLE_LED.h"
#include "GPIO.h"

int toggleState[] = {0,0,0};

void toggleLED (unsigned int LED)
{
    if(LED >= 0 && LED < 3)
       toggleState[LED] = !toggleState[LED];
    
    switch(LED)
    {
        case 0:
            LED0 = toggleState[LED];
            break;
        case 1:
            LED1 = toggleState[LED];
            break;
        case 2:
            LED2 = toggleState[LED];
            break;
        default:
            break;
    }
}