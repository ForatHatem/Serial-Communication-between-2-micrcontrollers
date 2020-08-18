/*
 * Display_LCD.h
 *
 *  Created on: 17 Aug. 2020
 *      Author: sarah1
 */

#ifndef LCD_DISPLAY_LCD_H_
#define LCD_DISPLAY_LCD_H_

#define TURN_ON_LCD                 (LCDCCTL0 |= LCDON)
#define TURN_OFF_LCD                (LCDCCTL0 &= (~LCDON))
#define CLEAR_LCD_MEM               (LCDCMEMCTL |= LCDCLRM)

#define START_ONESEC_LCD_DELAY      (TA1CTL |= MC__UP)
#define STOP_ONESEC_LCD_DELAY       (TA1CTL &= 0xFFE7)

#define LCD_DELAY_IF                TA1IV_TAIFG

#define A1_1            LCDM10
#define A1_2            LCDM11
#define A2_1            LCDM6
#define A2_2            LCDM7
#define A3_1            LCDM4
#define A3_2            LCDM5
#define A4_1            LCDM19
#define A4_2            LCDM20
#define A5_1            LCDM15
#define A5_2            LCDM16
#define A6_1            LCDM8
#define A6_2            LCDM9

void show_Char (unsigned char ch, unsigned int pos);
void show_String (char*str);

void test_Segments (void);

void OneSecond_Delay (void);

void displayHelloMsg (void);

#endif /* LCD_DISPLAY_LCD_H_ */
