#include <msp430.h>
#include <stdbool.h>
#include "InitDeclaration.h"
#include "ExtraFunctions.h"


/*
 * Button0 P1.5
 * Button1 P1.6
 * Button2 P1.7
 *
 * LED0 P9.1
 * LED1 P9.5
 * LED2 P9.6
 *
 * PB0 LED0 TA0CCR0 FF0
 * PB1 LED1 TA0CCR1 FF1
 * PB2 LED2 TA0CCR2 FF2
 *
 * if(rising edge PBx)
 * {
 *    if(!FFx){
 *        Toggle_LED(x)
 *        FFx = 1;
 *    }
 *    elseif(FFx){
 *        TA0CCRx = 0;
 *    }
 *
 *    change_P1IES();
 * }
 *
 * else if(falling edge PBx)
 * {
 *      if(FFx){
 *          TA0CCRx = TA0R + ONE_MS;}
 *
 *      chang_P1IES();
 *}
 *
 * if(TA0CCRx CCIFG)//1ms
 * {
 *      if(PB == 0){
 *          FFx = 0;
 *          TA0CCRx = 0}
 * }
 *
 * 2 functions
 * void Toggle_LED (unsigned int LED)
 *
 * void FirstFlag (unsigned int C_S, unsigned int PB)
 *
 */

#define ENABLE_PINS 0xFFFE

/*
 * t = count*Taclk
 * count = t/Taclk
 *
 * count = 1ms/25us
 * count = 1000/25 = 40
 */


int main (void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 = ENABLE_PINS;

    init_DigitalInput();// initialize the DigitalInput (PBx, Pulldown)
    init_DigitalOutput();// initialize Digital Output (LEDx, LEDx = 0)
    init_DebounceTimer ();//initialize Timer A0 to count to 0xFFFF then to zero and count again

    init_DigitalInput_Interrupt ();//enable DI ISR (Rising Edge)
    init_Timer_Interrupt ();//initialize Capture/Compare IF CCR0, CCR1, CCR2


    _BIS_SR (GIE);

    while(1);

    return 0;
}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0CCR0_ISR (void)
{
    if(!(P1IN & BIT5))
    {
        TA0CCTL0 &= (~CCIFG);
        FirstFlag[PushButton0] = 0;
        TA0CCR0 = 0;
    }
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void Timer_A0CCR1_ISR (void)
{
    switch(TA0IV)
    {
    case TA0IV_TACCR1:
        if(!(P1IN & BIT6)){
        TA0CCR1 = 0;
        FirstFlag[PushButton1] = 0;}
        break;
    case TA0IV_TACCR2:
        if(!(P1IN & BIT7)){
        TA0CCR2 = 0;
        FirstFlag[PushButton2] = 0;}
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
    case P1IV_P1IFG5://if P1.5 caused ISR
        Port1_ISR_BlockCode(PushButton0, LED0);//code applies to PB0 and LED0
        break;
    case P1IV_P1IFG6:
        Port1_ISR_BlockCode(PushButton1, LED1);
        break;
    case P1IV_P1IFG7:
        Port1_ISR_BlockCode(PushButton2, LED2);
        break;
    default:
        break;
    }
}
