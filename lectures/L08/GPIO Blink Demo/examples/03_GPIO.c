#include "03_GPIO.h"

// Function to set the mode of a pin to either input, output, alternate function or analog
void pinMode(struct GPIO * GPIOX, int pin, int function) {
    switch(function) {
        case(GPIO_INPUT):
            // YOUR CODE HERE
            break;
        // YOUR CODE HERE: Add cases for output, alternate output function (AF), and analog pin modes
    }
}

// Reads and returns the value of an input pin
int digitalRead(struct GPIO * GPIOX, int pin) {
    // YOUR CODE HERE
}

// Write a value to a GPIO pin
void digitalWrite(struct GPIO * GPIOX, int pin, int val) {
    // YOUR CODE HERE
    
}

// Toggles the state of a GPIO pin (low to high or high to low)
void togglePin(struct GPIO * GPIOX, int pin) {
    // YOUR CODE HERE
}
