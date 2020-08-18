/*
 * LCD_Definitions.h
 *
 *  Created on: 17 Aug. 2020
 *      Author: sarah1
 */

#ifndef LCD_INIT_LCD_H_
#define LCD_INIT_LCD_H_

#define LCD_SEG_A       0xFFC0
#define LCD_SEG_B       0xF03F
#define LCD_SEG_C       0x00F0

#define LCD_BTN         0x0008

#define FACLK           32768  L     //MHz
#define TIME            1              //one sec
#define COUNT           (TIME*FACLK)

#define TURN_ON_LCD     (LCDCCTL0 |= LCDON)
#define TURN_OFF_LCD    (LCDCCTL0 &= (~LCDON))
#define CLEAR_LCD_MEM   (LCDCMEMCTL |= LCDCLRM)

void init_LCD (void);

void init_OneSecond_Delay (void);


#endif /* LCD_INIT_LCD_H_ */
