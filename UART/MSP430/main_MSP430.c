#include <msp430.h> 
#include "Digital_Input_Output/GPIO.h"
#include "Digital_Input_Output/Debounce.h"
#include "Digital_Input_Output/Digital_Input_ISR.h"
#include "Timer/Debounce_Timer.h"
#include "UART/Clock_Initialization.h"
#include "UART/Baud_Rate.h"
#include "UART/UART.h"

#define ENABLE_PINS 0xFFFE

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 = ENABLE_PINS;

    init_GPIO ();//set the Digital Input and Output

    init_port_isr ();
    init_DebounceTimer ();
    init_DebounceTimer_Isr ();

    clock_initialization ();
    baud_rate_setup ();
    init_UART ();

    _BIS_SR (GIE);//enable global interrupt

    while(1);

    return 0;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void DebounceTimerIsr_A0 (void)
{
    BTN_pressed[0] = 0;
    TA0CCTL0 &= (~CCIFG);
    stop_DebounceTimer(Button0);
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void DebounceTimerIsr_A1_A2 (void)
{
    switch(TA0IV)
    {
    case BTN1_DEBOUNCETIMER_IF:
        BTN_pressed[1] = 0;
        stop_DebounceTimer(Button1);
        break;
    case BTN2_DEBOUNCETIMER_IF:
        BTN_pressed[2] = 0;
        stop_DebounceTimer(Button2);
        break;
    default:
        break;
    }
}

#pragma vector = PORT1_VECTOR
__interrupt void Port1_ISR (void)
{
    switch(P1IV)
    {
    case BTN0:
        if(check_edge_isr(Button0) == RISING_EDGE)
        {
            ButtonPressedRoutine(Button0);
        }

        else if(check_edge_isr (Button0) == FALLING_EDGE)
        {
            ButtonReleasedRoutine(Button0);
        }
        change_edge_isr(Button0);
        break;
    case BTN1:
        if(check_edge_isr (Button1) == RISING_EDGE)
        {
            ButtonPressedRoutine(Button1);
        }
        else if(check_edge_isr(Button1) == FALLING_EDGE)
        {
            ButtonReleasedRoutine(Button1);
        }
        change_edge_isr(Button1);
        break;
    case BTN2:
        if(check_edge_isr(Button2) == RISING_EDGE)
        {
            ButtonPressedRoutine(Button2);
        }
        else if(check_edge_isr(Button2) == FALLING_EDGE)
        {
            ButtonReleasedRoutine(Button2);
        }
        change_edge_isr(Button2);
    default:
        break;
    }
}
