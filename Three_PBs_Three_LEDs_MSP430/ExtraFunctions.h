/*
 * ExtraFunctions.h
 *
 *  Created on: 3 Feb. 2020
 *      Author: sarah1
 */

#define ONE_MS 40
//Taclk = 25us t = count*Taclk, count = 1ms/25us = 40

#ifndef EXTRAFUNCTIONS_H_
#define EXTRAFUNCTIONS_H_


enum PushButton
{
    PushButton0,
    PushButton1,
    PushButton2
};

enum LED
{
    LED0,
    LED1,
    LED2
};

unsigned int FirstFlag[3];//there are 3 FirstFlags, FF0 for PB0 and LED0, FF1 -> PB1 & LED1, FF2 -> PB2 & LED2

void Toggle_LED (enum LED x);//x = 0,1,2

int check_RisingEdge (enum PushButton PB);//returns the value of P1IES & BITX, X = 5,6,7

void toggle_EdgeSelect (enum PushButton PB);//toggles R/F Edge of P1IES

void Port1_ISR_BlockCode (enum PushButton PB, enum LED x);//check Rising Edge, check FirsFlagx, toggle Edge, Toggle LED are all in this function

#endif /* EXTRAFUNCTIONS_H_ */
