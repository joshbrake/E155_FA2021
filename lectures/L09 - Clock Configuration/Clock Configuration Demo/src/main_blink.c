// main_blink.c
// GPIO blink LED with clock configuration
// Josh Brake
// jbrake@hmc.edu
// 9/28/21

#include "STM32F401RE_GPIOA.h"
#include "STM32F401RE_RCC.h"
#include "STM32F401RE_FLASH.h"

#define LED_PIN     5
#define DELAY_MS    500

void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {
    configureFlash();

    /* Configure APB prescalers
        1. Set APB2 (high-speed bus) prescaler to no division
        2. Set APB1 (low-speed bus) to divide by 2.
    */
    RCC->CFGR.PPRE2 = 0b000;
    RCC->CFGR.PPRE1 = 0b100;

    // Call configureClock() (declared in STM32F401RE_RCC.h)
    configureClock();

    // Turn on clock to GPIOA
    RCC->AHB1ENR.GPIOAEN = 1;

    // Set LED_PIN as output
    pinMode(LED_PIN, GPIO_OUTPUT);

    // Blink LED
    while(1) {
        ms_delay(DELAY_MS);
        togglePin(LED_PIN);
    }
    return 0;
}