
#ifndef DIGITAL_INPUT_OUTPUT_H
#define	DIGITAL_INPUT_OUTPUT_H

/*
 LED0 -> P21
 LED1 -> P22
 LED2 -> P23
 
 */

#define LED0 LATBbits.LATB4
#define LED1 LATBbits.LATB3
#define LED2 LATBbits.LATB2

#define LED0_INPUT (TRISBbits.TRISB4 = 0)
#define LED1_INPUT (TRISBbits.TRISB3 = 0)
#define LED2_INPUT (TRISBbits.TRISB2 = 0)

#define LED0_DIGITAL (ANSBbits.ANSB4 = 0)
#define LED1_DIGITAL (ANSBbits.ANSB3 = 0)
#define LED2_DIGITAL (ANSBbits.ANSB2 = 0)

void init_DigitalOutput (void);


#endif	

