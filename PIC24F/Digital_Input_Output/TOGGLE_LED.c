#include "xc.h"
#include "TOGGLE_LED.h"
#include "GPIO.h"
//#include <stdio.h>
int toggleState[] = {0,0,0};

//char ledState [5];

void toggleLED (unsigned int LED)
{
    if(LED >= 0 && LED < 3)
       toggleState[LED] = !toggleState[LED];
    
    switch(LED)
    {
        case 0:
            LED0 = toggleState[LED];
            //sendChar(65+toggleState[LED]);//A or B
            break;
        case 1:
            LED1 = toggleState[LED];
            //sendChar(70+toggleState[LED]);//E or F
            break;
        case 2:
            LED2 = toggleState[LED];
            //sendChar(75+toggleState[LED]);//I or J
            break;
        default:
            break;
    }
}