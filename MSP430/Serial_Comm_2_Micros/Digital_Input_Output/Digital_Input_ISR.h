#ifndef DIGITAL_INPUT_ISR_H_
#define DIGITAL_INPUT_ISR_H_

#define BTN0    P1IV_P1IFG5
#define BTN1    P1IV_P1IFG6
#define BTN2    P1IV_P1IFG7
#define BTN_LCD P1IV_P1IFG3

#define BTN0_EDGE_SELECT    (P1IES & BIT5)
#define BTN1_EDGE_SELECT    (P1IES & BIT6)
#define BTN2_EDGE_SELECT    (P1IES & BIT7)
#define BTN_LCD_EDGE_SELECT (P1IES & BIT3)

#define BTN0_CHANGE_EDGE    (P1IES ^= BIT5)
#define BTN1_CHANGE_EDGE    (P1IES ^= BIT6)
#define BTN2_CHANGE_EDGE    (P1IES ^= BIT7)
#define BTN_LCD_CHANGE_EDGE (P1IES ^= BIT3)

#include "Debounce.h"

enum EDGE_SELECT
{
    RISING_EDGE = 0,
    FALLING_EDGE = 1
};

enum EDGE_SELECT check_edge_isr (enum Button x);

void change_edge_isr (enum Button x);

void enable_port_isr (void);

void init_port_isr (void);


#endif /* DIGITAL_INPUT_OUTPUT_DIGITAL_INPUT_ISR_H_ */
