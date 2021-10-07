// 02_blink_led_struct.c
// Blnk LED with structure
// Josh Brake
// jbrake@hmc.edu
// 9/22/21

// Include integer types with specified widths like uint32_t
#include <stdint.h>

// Pointer to turn on GPIO clock domain
volatile unsigned long * RCC_AHB1ENR  = (unsigned long *) 0x40023830;

// Base addresses for GPIO ports
//volatile unsigned long * GPIOA_BASE   = (unsigned long *) 0x40020000; // Base register
#define GPIOA_BASE (0x40020000UL)

// GPIO register structs here
typedef struct {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFRL;
  volatile uint32_t AFRH;
} GPIO;

// Pointers to GPIO-sized chunks of memory for each peripheral
#define GPIOA ((GPIO *) GPIOA_BASE)

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
    *RCC_AHB1ENR |= (1 << 0);

    // Set LED_PIN as output
    (*GPIOA).MODER  |= (1 << 2*LED_PIN);
    GPIOA->MODER    &= ~(1 << (2*LED_PIN+1));

    // Blink LED
    while(1) {
        ms_delay(DELAY_MS);
        // GPIOA->ODR ^= (1 << LED_PIN);

        if((GPIOA->ODR >> LED_PIN) & 1){
          GPIOA->ODR &= ~(1 << LED_PIN);
        }
        else{
          GPIOA->ODR |= (1 << LED_PIN);
          }
    }
    return 0;
}