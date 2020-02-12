#include <msp430.h>
#include "InitDeclaration.h"

/*
 * InitDeclaration.c
 *
 *  Created on: 21 Jan. 2020
 *      Author: sarah1
 */
void init_DigitalInput (void)
{
    //pulldown resistors
    //P1.5 1.6 1.7 are input
    P1DIR = P1DIR & (~BIT5) & (~BIT6) & (~BIT7);//P1DIR = 000x xxxx

    P1REN = P1REN | BIT5 | BIT6 | BIT7;//enable Pull R at 1.5 1.6 1.7
    //P1REN = 111x xxxx

    P1OUT = P1OUT & (~BIT5) & (~BIT6) & (~BIT7);
    //P1OUT = 000x xxxx
}

void init_DigitalOutput (void)
{
    //Port 9 P9.1 9.5 9.6 are all output
    P9DIR |= BIT6 | BIT5 | BIT1;

    P9OUT = 0x00;

}

void init_DebounceTimer (void)
{
    //I will initialize a 1ms timer TA0
    TA0CTL = TASSEL__ACLK | MC__CONTINOUS;
    //CS from ACLK
    //MC__STOP
}

void init_DigitalInput_Interrupt (void)
{
    P1IE = P1IE | BIT5 | BIT6 | BIT7;//P1.5 1.6 1.7 DI ISR

    P1IES = P1IES & (~BIT5) & (~BIT6) & (~BIT7);//L -> H

    P1IFG = 0x00;//clear flags
}

void init_Timer_Interrupt (void)
{
    TA0CCTL0 = CCIE;//enable TACCR0 ISR
    TA0CCTL1 = CCIE;
    TA0CCTL2 = CCIE;
}
