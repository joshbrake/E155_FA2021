// 02_blink_led_struct.c
// Blnk LED with structure
// Josh Brake
// jbrake@hmc.edu
// 9/22/21

// Include integer types with specified widths like uint32_t
#include <stdint.h>

// Pointer to turn on GPIO clock domain
/* YOUR CODE HERE */

// Base addresses for GPIO ports
/* YOUR CODE HERE */

// GPIO register structs here
struct GPIO {
  /* YOUR CODE HERE */
};

// Pointers to GPIO-sized chunks of memory for each peripheral
/* YOUR CODE HERE */

#define LED_PIN     5
#define DELAY_MS    100

void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {
    // Turn on clock for GPIO
    /* YOUR CODE HERE */

    // Set LED_PIN as output
    /* YOUR CODE HERE */

    // Blink LED
    while(1) {
        ms_delay(DELAY_MS);
        /* YOUR CODE HERE */
    }
    return 0;
}