#ifndef LCD_H
#define	LCD_H

#define TOTAL_POWER     1
#define POWER_PER_LED   0

void InitLCD (void);

void displayHelloMsg (void);

void displayLED (unsigned int * LED);

void displayComm (unsigned int CommMode);

void displayPower (unsigned int * LED, unsigned int powerMode);

void ClearDisplayLCD (void);

extern unsigned int LED [3];// = {0,0,0};

#endif	/* XC_HEADER_TEMPLATE_H */

