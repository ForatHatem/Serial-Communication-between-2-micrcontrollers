
/*
   3V3 *
       |        |---------|TX   (RD9/RP4/P69)RX|----------|
1.5BTN0|---/ ---|         |------------------->|          |----|>----|LED0 (RB4) P21
1.6BTN1|---/ ---|   MSP   |P4.2                |   PIC24  |----|>----|LED1 (RB3) P22
1.7BTN2|---/ ---|         |<-------------------|          |----|>----|LED2 (RB2) P23
       |        |         |                    |          |          |
1.3LCD |---/ ---|         |                    |          |          |
                |---------|RX  (RD10/RP3/P70)TX|----------|          |
                 _________ P4.3                 __________           |
                |___LCD___|                    |___LCD____|          V GND

 * UART Baud Rate 9600 8 bits, No Parity, LSB first, One Stop bit
 * MSP430 CS 4MHz
 * PIC24  CS 4MHz
 *
 */



#include <msp430.h> 
#include "Digital_Input_Output/GPIO.h"
#include "Digital_Input_Output/Debounce.h"
#include "Digital_Input_Output/Digital_Input_ISR.h"
#include "Timer/Debounce_Timer.h"
#include "Clock/Clock_Initialization.h"
#include "UART/Baud_Rate.h"
#include "UART/UART.h"
#include "LCD/Init_LCD.h"
#include "LCD/Display_LCD.h"

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

    init_LCD ();
    init_OneSecond_Delay ();

    displayHelloMsg ();

    TURN_ON_LCD;

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

        else//check_edge_isr(x) == FALLING_EDGE
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
        else
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
        else
        {
            ButtonReleasedRoutine(Button2);
        }
        change_edge_isr(Button2);
        break;
    case BTN_LCD:
        if(check_edge_isr(ButtonLCD) == RISING_EDGE)
        {
            ButtonPressedRoutine(ButtonLCD);
        }

        else
        {
            ButtonReleasedRoutine(ButtonLCD)
        }
    default:
        break;
    }
}

#pragma vector = TIMER1_A1_VECTOR
__interrupt void OneSecond_Delay_ISR (void)
{
    switch(TA1IV)
    {
    case LCD_DELAY_IF:
        STOP_ONESEC_LCD_DELAY;
        displayHelloMsg ();//displayLCD ();//
        break;
    default:
        break;
    }
    //TA1CTL &= (~TAIFG);//CLEAR TA1 IF
}
