#ifndef BAUD_RATE_H_
#define BAUD_RATE_H_

#define BR_VALUE  26
#define MOD_VALUE 0xB601

#define CONFIG_BR_REG  (UCA0BRW = BR_VALUE)
#define CONFIG_MOD_REG (UCA0MCTLW = MOD_VALUE)

void baud_rate_setup (void);

#endif /* UART_BAUD_RATE_H_ */
