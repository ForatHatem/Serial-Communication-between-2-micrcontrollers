#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#define FCY 4000000L
#define BAUD_RATE 9600L
#define BRG_PERIOD (((FCY)/(16*BAUD_RATE)) - 1)

//#define CONFIG_U1TX (RPOR2bits.RP4R = 3)//RP4 -> U1TX -> P69
//#define CONFIG_U1RX (RPINR18bits.U1RXR = 3)//RP3 -> U1RX -> P70

#define U1RX_INPUT (TRISDbits.TRISD9 = 1)
#define U1RX_CONFIG (RPINR18bits.U1RXR = 4)

#define U1TX_OUTPUT (TRISDbits.TRISD10 = 0)
#define U1TX_CONFIG (RPOR1bits.RP3R = 3)

#define ENABLE_UART    (U1MODEbits.UARTEN = 1)
#define ENABLE_TX_UART (U1STAbits.UTXEN = 1)
#define ENABLE_RX_UART (U1STAbits.URXEN = 1)

#define DELAY_105uS asm volatile ("REPEAT, #4201"); Nop ();

void setup_UART (void);

void setup_UART_Pins (void);

void enable_UART (void);

#endif	/* XC_HEADER_TEMPLATE_H */

