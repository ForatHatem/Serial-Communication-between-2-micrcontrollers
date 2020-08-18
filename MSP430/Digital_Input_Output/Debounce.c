#include <msp430.h>
#include "Debounce.h"
#include "Toggle.h"
#include "Timer/Debounce_Timer.h"
#include "UART/UART.h"
#include "LCD/Display_LCD.h"


int BTN_pressed [3] = {0,0,0};
int BTN_release [3] = {0,0,0};

void ButtonPressedRoutine (enum Button x)
{
    BTN_release[x] = 0;

    stop_DebounceTimer(x);

    if(BTN_pressed[x] == 0)
    {
        //ToggleLED(y);

        sendChar(x);

        if(x == Button0)
            show_String("B0 CL");
        else if(x == Button1)
            show_String("B1 CL");
        else if(x == Button2)
            show_String("B2 CL");

        START_ONESEC_LCD_DELAY;
        BTN_pressed[x] = 1;
     }
}

void ButtonReleasedRoutine (enum Button x)
{
    start_DebounceTimer(x);
}
