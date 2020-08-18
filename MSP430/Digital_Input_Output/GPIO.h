
//#define BTN0 (P1IN & BIT5)
//#define BTN1 (P1IN & BIT6)
//#define BTN2 (P1IN & BIT7)



#define TOGGLE_LED0 (P9OUT ^= BIT3)
#define TOGGLE_LED1 (P1OUT ^= BIT4)
#define TOGGLE_LED2 (P2OUT ^= BIT0)

#ifndef GPIO_H_
#define GPIO_H_


void init_GPIO (void);


#endif /* DIGITAL_INPUT_OUTPUT_GPIO_H_ */
