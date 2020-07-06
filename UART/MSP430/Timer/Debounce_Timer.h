#ifndef TIMER_DEBOUNCE_TIMER_H_
#define TIMER_DEBOUNCE_TIMER_H_

#define BTN1_DEBOUNCETIMER_IF TA0IV_TA0CCR1
#define BTN2_DEBOUNCETIMER_IF TA0IV_TA0CCR2

#define BTN0_DEBOUNCETIMER_REG TA0CCR0
#define BTN1_DEBOUNCETIMER_REG TA0CCR1
#define BTN2_DEBOUNCETIMER_REG TA0CCR2

#include "Digital_Input_Output/Debounce.h"


void init_DebounceTimer (void);

void init_DebounceTimer_Isr (void);

void start_DebounceTimer (enum Button x);

void stop_DebounceTimer (enum Button x);

#endif /* TIMER_DEBOUNCE_TIMER_H_ */
