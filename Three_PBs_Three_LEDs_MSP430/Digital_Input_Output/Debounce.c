#include <msp430.h>
#include "Debounce.h"
#include "Toggle.h"

const int BounceValue = 2000;

int BTN_press [3] = {0,0,0};
int BTN_pressed [3] = {0,0,0};
int BTN_release [3] = {0,0,0};

void ButtonPressedRoutine (enum Button x, enum LED y)
{
    BTN_press[x]++;
    BTN_release[x] = 0;

    if(BTN_press[x] > BounceValue)
    {
        if(BTN_pressed[x] == 0)
        {
            ToggleLED(y);
            BTN_pressed[x] = 1;
            BTN_press[x] = 0;
        }
    }
}

void ButtonReleasedRoutine (enum Button x)
{
    BTN_release [x]++;
    BTN_press [x] = 0;

    if(BTN_release[x] > BounceValue)
    {
        BTN_pressed[x] = 0;
        BTN_release[x] = 0;
    }
}
