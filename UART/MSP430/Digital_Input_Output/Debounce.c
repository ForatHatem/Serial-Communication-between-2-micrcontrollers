#include <msp430.h>
#include "Debounce.h"
#include "Toggle.h"
#include "Timer/Debounce_Timer.h"
#include "UART/UART.h"


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
        BTN_pressed[x] = 1;
    }
}

void ButtonReleasedRoutine (enum Button x)
{
    start_DebounceTimer(x);
}
