/*
 * ExtraFunctions.h
 *
 *  Created on: 3 Feb. 2020
 *      Author: sarah1
 */

#define ONE_MS 40


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

unsigned int FirstFlag[3];

void Toggle_LED (enum LED x);

int check_RisingEdge (enum PushButton PB);

void toggle_EdgeSelect (enum PushButton PB);

//void Port1_ISR_BlockCode (enum PushButton PB, enum LED x);

#endif /* EXTRAFUNCTIONS_H_ */
