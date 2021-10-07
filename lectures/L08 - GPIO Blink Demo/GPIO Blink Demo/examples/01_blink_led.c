// 01_blink_led.c
// Simple GPIO blink LED with direct pointer manipulation
// Josh Brake
// jbrake@hmc.edu
// 9/22/21

// Pointer for register to turn on clock for GPIO

// Pointers for registers to configure GPIO (see chapter 8 of the STM32F401RE
// reference manual starting on p. 146)
/* YOUR CODE HERE */

// Complete define statements for the LED pin and delay duration
#define LED_PIN         /* YOUR CODE HERE */
#define DELAY_DURATION  500

// Simple delay function to use a bunch of NOPs to stall the processor
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=200;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {
    // Turn on clock to GPIO
    /* YOUR CODE HERE */

    // Set LED_PIN as output
    /* YOUR CODE HERE */

    // Blink LED
    while(1) {
        ms_delay(DELAY_DURATION);
        
        // Code to toggle the LED each iteration (i.e., set from high to low
        // or from low to high)
        
        /* YOUR CODE HERE */
    }
    return 0;
}