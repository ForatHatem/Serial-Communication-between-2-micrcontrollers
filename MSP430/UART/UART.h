/*
 * UART.h
 *
 *  Created on: 23 Jun. 2020
 *      Author: sarah1
 */

#ifndef UART_H_
#define UART_H_

#define UART_TX_BUF UCA0TXBUF

#include "Digital_Input_Output/Debounce.h"



void init_UART (void);

void sendChar (enum Button x);


#endif /* UART_UART_H_ */
