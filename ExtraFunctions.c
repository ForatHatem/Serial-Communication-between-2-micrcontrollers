#include <msp430.h>
#include "ExtraFunctions.h"

/*
 * ExtraFunctions.c
 *
 *  Created on: 3 Feb. 2020
 *      Author: sarah1
 */

void Toggle_LED (enum LED x)//This function is to toggle the LEDs
{
    switch (x)
    {
    case LED0://x == LED0 toggle P9.1, LED -> 9.5, LED2 -> 9.6
        P9OUT ^= BIT1;
        break;
    case LED1:
        P9OUT ^= BIT5;
        break;
    case LED2:
        P9OUT ^= BIT6;
        break;
    default:
        break;
    }
}

/*
 * Checks weather or not P1IES for P1.5, P1.6, P1.7
 * are Rising or Falling edge
 *
 * asks for which PB enum (input) and returns the value of the P1IES bit
 *
 * func returns 0 -> Rising Edge, returns 1 -> Falling Edge
 */
int check_RisingEdge (enum PushButton PB)
{
    switch(PB)
    {
    case PushButton0://if PushButton 0, return P1IES & BIT5, BIT6, BIT7
        return (P1IES & BIT5);
    case PushButton1:
        return (P1IES & BIT6);
    case PushButton2:
        return (P1IES & BIT7);
    default:
        break;
    }

    return 0;
}

void toggle_EdgeSelect (enum PushButton PB)
{
    switch(PB)
    {
    case PushButton0:
        P1IES ^= BIT5;
        break;
    case PushButton1:
        P1IES ^= BIT6;
        break;
    case PushButton2:
        P1IES ^= BIT7;
        break;
    default:
        break;
    }
}

/*
 * This is a block of code in the ISR
 * instead of repeating it, I decided to make it as a function
 *
 * PB and x can either be 0,1, or 2
 *
 * Checks if Rising Edge or Falling Edge
 * if RE
 * Checks First Flag or not First Flag
 * if First Time, toggle LEDx and set FirstFlag
 * if not First Time, TA0CCRx = 0
 * Toggle Edge ISR
 *
 *
 * If FE
 * Checks First Flag
 * if not First Time, TA0CCRx = TA0R + ONE_MS
 * start counting and serivce TA0CCRx ISR after one ms
 * Toggle Edge ISR
 *
 *
 */
void Port1_ISR_BlockCode (enum PushButton PB, enum LED x)
{
    if(!check_RisingEdge(PB))//rising edge = 0 falling edge = non-0
    {
        if(!FirstFlag[PB])//is it the first time PB rises
        {
           Toggle_LED(x);//Toggle LEDx
           FirstFlag[PB] = 1;//set First Flag PB to 1 so at another RE it won't toggle again
        }

        else if(FirstFlag[PB])//if RE and not the first time
            TA0CCR0 = 0;//don't count for CCR0

        toggle_EdgeSelect(PB);//toggle Edge Select so a falling edge will cause an ISR
    }
    else if(check_RisingEdge(PB) && FirstFlag[PB])//falling edge
    {
        if(PB == PushButton0){TA0CCR0 = TA0R + ONE_MS;}//if FE for PBx (x = 0,1,2) then
        else if(PB == PushButton1){TA0CCR1 = TA0R + ONE_MS;}
        else if(PB == PushButton2){TA0CCR2 = TA0R + ONE_MS;}

        toggle_EdgeSelect(PB);//toggle Edge Select so a Rising edge will cause an ISR
    }
}
