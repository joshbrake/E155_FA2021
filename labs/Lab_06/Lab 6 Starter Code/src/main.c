// main.c

#include "STM32F401RE_FLASH.h"
#include "STM32F401RE_RCC.h"
#include "STM32F401RE_USART.h"

#define USART_ID USART2_ID

int main(void) {
    // Configure flash and clock
    configureFlash();
    configureClock(); // Set system clock to 84 MHz

    // TODO: Your code here
}