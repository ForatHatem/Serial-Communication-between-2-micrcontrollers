#include <msp430.h>
#include "Digital_Input_ISR.h"
#include "Debounce.h"

enum EDGE_SELECT check_edge_isr(enum Button x)
{
    int EdgeState;
    enum EDGE_SELECT di_isrState;

    switch(x)
    {
    case Button0:
        EdgeState = BTN0_EDGE_SELECT;
        break;
    case Button1:
        EdgeState = BTN1_EDGE_SELECT;
        break;
    case Button2:
        EdgeState = BTN2_EDGE_SELECT;
        break;
    case ButtonLCD:
        EdgeState = BTN_LCD_EDGE_SELECT;
        break;
    default:
        break;
    }

    if(EdgeState == 0)
        di_isrState = RISING_EDGE;
    else if(EdgeState != 0)
        di_isrState = FALLING_EDGE;

    return di_isrState;
}

void change_edge_isr(enum Button x)
{
    switch(x)
    {
    case Button0:
        BTN0_CHANGE_EDGE;
        break;
    case Button1:
        BTN1_CHANGE_EDGE;
        break;
    case Button2:
        BTN2_CHANGE_EDGE;
        break;
    case ButtonLCD:
        BTN_LCD_CHANGE_EDGE;
        break;
    default:
        break;
    }
}

void init_port_isr (void)
{
    P1IE |= (BIT3 | BIT5 | BIT6 | BIT7);//P1.3 P1.5 1.6 1.7

    P1IES &= ~(BIT3 | BIT5 | BIT6 | BIT7);//transition from L -> H

    P1IFG = 0x00;//clear flags
}
