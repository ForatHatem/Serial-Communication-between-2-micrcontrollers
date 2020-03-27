# Three Push Buttons Three LEDs for MSP430

Three NO Push Buttons **PB0**, **PB1**, and **PB2** have been connected to **P1.5**, **P1.6**, and **P1.7** respectively, the voltage divider circuitry provides a maximum of 2.7V, which is enough for the MSP430 to register it as a HIGH state.

Three LEDs **LED0**, **LED1**, and **LED2** are connected to the MSP430 **P9.1**, **P9.5**, **P9.6** respectively, where they get a Voltage of 0 (LOW) and 3.2V (HIGH), blue LEDs got a Forward Voltage of 3.5V

Adding three buttons added to the complexity of the code, especially in debouncing the PB. Instead of starting and stoping the timer for the debounce, and instead of using **TA0**, **TA1**, and **TA2** as timers for the PBs, I used one timer Timer **TA0R** that is configured in a continous mode (it counts till 0xFFFF then rolls back to 0 and counts again), and enabled the Capture/Compare interrupt (CCIE) for **TA0CCR0**, **TA0CCR1**, and **TA0CCR2**.

Eventually I want to put the MSP430 in a Low Power Mode, where the CPU is switched off, hence no code will be running on the main function. That is why I introduced interrupts, where the uC goes to sleep and when a Rising Edge, Falling Edge, or Capture/Compare IF is set an ISR will be serviced.

To organize the code better, I put different sections of the code in seperate files, **MoreButton2.c** got the main function and the ISR functions, **Initialization.h** and **Initialization.c** got the initialization of peripherals, **ExtraFunctions.h** and **ExtraFunctions.c** got the other functions such as: Toggle the LED, toggle Edge Select ISR function, check if Rising or Falling Edge function.
