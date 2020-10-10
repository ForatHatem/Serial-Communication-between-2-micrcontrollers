# Serial-Communication-between-2-micrcontrollers

![Project Image](https://github.com/ForatHatem/Serial-Communication-between-2-micrcontrollers/blob/master/Project%20Photo.jpeg)

The premise of this project is to use two microcontrollers to communicate with one another serially either via UART, SPI, or I2C communication protocol. We have 3 buttons
(BTN0, BTN1, and BTN2) attached to micrcontroller A (MSP430FR6989) when a button is pressed, A would send a signal (via UART, SPI, or I2C) to microcontroller B (PIC24FJ1024GB610)
where 3 LEDs are connected to it (LED0, LED1, and LED2), and the relevant LED would be toggled, and in return B would send a signal back to A about which LED is ON or OFF.

MSP430 (uC A), can change the communication protocol with a button connected to it (COMM_BTN).

Additionally, each microcontroller would be connected to an LCD that displays certain information, this LCD display changes with a toggle button (LCD_BTN)

MSP430 has a 14 segment 6 digit LCD, and it will display:
- "HELLO" message
- Serial communication used
- which LED is ON or OFF at the PIC24
- Displays which button is closed for 1 second
- LCD turns off after 2 minutes of being idle

PIC24F will display:
- "HELLO" message
- Serial communication used
- which LED is ON or OFF
- Power consumed by each LED
- Total power consumed by the LEDs
- LCD turns off after 2 minutes of being idle

Finally, I will put the microcontrolles into Low Power Modes, and try to make them consume little power as possible, as after finishing the prototype, I would like to create a PCB
board for the microcontrollers and its associated electronic circuits
