#include <msp430.h>
#include "Debounce_Timer.h"
#include "Digital_Input_Output/Debounce.h"

const int BounceValue = 200;

void init_DebounceTimer (void)
{
    TA0CTL |= (TASSEL__ACLK | MC__CONTINUOUS);
}

void init_DebounceTimer_Isr (void)
{
    TA0CCTL0 |= CCIE;
    TA0CCTL1 |= CCIE;
    TA0CCTL2 |= CCIE;
}

void start_DebounceTimer (enum Button x)
{
    switch (x)
    {
    case Button0:
        BTN0_DEBOUNCETIMER_REG = TA0R + BounceValue;
        break;
    case Button1:
        BTN1_DEBOUNCETIMER_REG = TA0R + BounceValue;
        break;
    case Button2:
        BTN2_DEBOUNCETIMER_REG = TA0R + BounceValue;
        break;
    default:
        break;
    }
}

void stop_DebounceTimer (enum Button x)
{
    switch(x)
    {
    case Button0:
        TA0CCR0 = 0;
        break;
    case Button1:
        TA0CCR1 = 0;
        break;
    case Button2:
        TA0CCR2 = 0;
        break;
    default:
        break;
    }
}
