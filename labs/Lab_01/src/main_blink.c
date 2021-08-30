// main_blink.c
// GPIO blink LED with clock configuration
// Josh Brake
// jbrake@hmc.edu
// 9/9/20

#include "STM32F401RE_GPIO.h"
#include "STM32F401RE_RCC.h"

#define LED_PIN     8
#define FPGA_IN     10

int main(void) {
    // Turn on clock to GPIOA
    RCC->AHB1ENR.GPIOAEN = 1;
    RCC->AHB1ENR.GPIOBEN = 1;

    // Set LED_PIN as output and FPGA_IN as input
    pinMode(GPIOA, LED_PIN, GPIO_OUTPUT);
    pinMode(GPIOA, FPGA_IN, GPIO_INPUT);
    pinMode(GPIOB, 0, GPIO_OUTPUT);

    // Read input from FPGA and toggle LED appropriately
    while(1) {
        volatile int inputPinState = digitalRead(GPIOA, FPGA_IN);
        if (inputPinState == GPIO_HIGH) {
          digitalWrite(GPIOA, LED_PIN, GPIO_HIGH);
          digitalWrite(GPIOB, 0, GPIO_HIGH);
        }
        else {
          digitalWrite(GPIOA, LED_PIN, GPIO_LOW);
          digitalWrite(GPIOB, 0, GPIO_LOW);
        }
    }
}