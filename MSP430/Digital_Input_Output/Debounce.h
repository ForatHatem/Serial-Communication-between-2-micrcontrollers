/*
 * Debounce.h
 *
 *  Created on: 11 Jun. 2020
 *      Author: sarah1
 */

#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

#include "Toggle.h"

enum Button
{
    Button0 = 0,
    Button1 = 1,
    Button2 = 2,
};

extern int BTN_pressed [3];

//int BounceValue = 2000;

void ButtonPressedRoutine (enum Button x);
void ButtonReleasedRoutine (enum Button x);

#endif /* DIGITAL_INPUT_OUTPUT_DEBOUNCE_H_ */
