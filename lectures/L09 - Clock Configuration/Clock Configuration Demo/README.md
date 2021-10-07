# Clock Configuration Demo

This demo walks you through the code to configure the PLL to run the MCU at its highest clock frequency of 84 MHz.
Here we use the 8 MHz input from the ST-LINK microcontroller clock output (MCO) pin as the input to the PLL (connected to OSC_IN on the STM32F401RE).
Calculate the required values for the PLL parameters (M, N, and P) and then fill in the missing values.
The header file with the relevant register and register bitfields is provided for you in `STM32F401RE_RCC.h`.

# TODO
* Complete missing entries in `configurePLL()` in `STM32F401RE_RCC.c`.