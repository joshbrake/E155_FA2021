// 03_GPIO_header_blink.c
// Blink LED with program using header
// Josh Brake
// jbrake@hmc.edu
// 9/22/21

#include "03_GPIO.h"

// Pointer to AHB2 enable register for turning on GPIOB
volatile unsigned long * RCC_AHB1ENR  = (unsigned long *) 0x40023830;

#define LED_PIN     5   // PA5
#define BUTTON_PIN  13  // PC13
#define DELAY_MS    100

void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {
    // Turn on clock to GPIOA and GPIOC using pointer manipulation
    // YOUR CODE HERE

    // Set LED_PIN as output using pinMode()
    // YOUR CODE HERE

    // Set button pin as input using pinMode()
    // YOUR CODE HERE

    // Blink LED using digitalRead() and digitalWrite()
    while(1) {
      // YOUR CODE HERE
    }
    return 0;
}