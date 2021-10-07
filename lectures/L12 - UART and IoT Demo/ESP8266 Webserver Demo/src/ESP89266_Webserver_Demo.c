/*
File: ESP89266_Webserver_Demo.c
Author: Josh Brake
Email: jbrake@hmc.edu
Date: 9/29/21
*/

// NB: You must connect to the portal using http, NOT https.
// So navigate to http://192.168.4.1 when you connect via your browser.

#include "STM32F401RE_GPIO.h"
#include "STM32F401RE_FLASH.h"
#include "STM32F401RE_RCC.h"
#include "STM32F401RE_USART.h"
#include <string.h> // for strstr()
#include <stdint.h> // for integer types (i.e., uint32_t)
#include <stdio.h>  // for sprintf()

#define BUFF_LEN 32

/////////////////////////////////////////////////////////////////
// Provided Constants and Functions
/////////////////////////////////////////////////////////////////

//Defining the web page in two chunks: everything before the current time, and everything after the current time
//Please see the e155 website for a human-readable version of the file "webpage.html"
char * webpageStart = "<!DOCTYPE html><html><head><title>E155 Web Server Demo Webpage</title><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"></head><body><h1>E155 Web Server Demo Webpage</h1>";
char * ledStr = "<h2>LED Control:</h2><form action=\"ledon\"><input type=\"submit\" value=\"Turn the LED on!\" /></form>\
	<form action=\"ledoff\"><input type=\"submit\" value=\"Turn the LED off!\" /></form>";
char * webpageEnd   = "</body></html>";

// Sends a null terminated string of arbitrary length
void sendString(USART_TypeDef * USART, char * str) {
	char * ptr = str; // Get a pointer to the first element in the array.
  
  // Check if ptr is the null terminator (i.e. 0).
  // Otherwise, send the character and post-increment the pointer to point to
  // the next character in the string.
	while (*ptr) sendChar(USART, *ptr++);
}

//determines whether a given character sequence is in a char array request, returning 1 if present, -1 if not present
int inString(char request[], char des[]) {
	if (strstr(request, des) != NULL) {return 1;}
	return -1;
}

void updateLED(char request[]) {
	// The request has been received. now process to determine whether to turn the LED on or off
	if (inString(request, "ledoff") == 1) {
		digitalWrite(GPIOA, 5, 0);
	}
	if (inString(request, "ledon") == 1) {
		digitalWrite(GPIOA, 5, 1);
	}
}

int main (void) {
  // Configure the flash and then set clock to 84 MHz from PLL
  configureFlash();
  configureClock();
  
  // Turn on GPIOA
  RCC->AHB1ENR.GPIOAEN = 1;

  // Set PA5 as an output for the LED
  pinMode(GPIOA, 5, GPIO_OUTPUT);
	digitalWrite(GPIOA, 5, 1);
	
  // Initialize the UART connection for the ESP8266
  USART_TypeDef * ESPUSART = initUSART(USART1_ID);

  while(1) {
    /* Wait for ESP8266 to send a request.
    Requests take the form of '/REQ:<tag>\n', with TAG being <= 10 characters.
    Therefore the request[] array must be able to contain 18 characters.
    */
    
    // Receive web request from the ESP
    char request[BUFF_LEN] = "                  "; // initialize to known value
    int charIndex = 0;

    // Keep going until you get end of line character
    while(inString(request, "\n") == -1) {
      // Wait for a character to be received before reading the RX buffer
      while(!ESPUSART->SR.RXNE);
      request[charIndex++] = (char) receiveChar(ESPUSART);
    }
    
    // Update the state of the LED based on the request from the webpage
    updateLED(request);

    // Get the current LED state and format the string to send back as part of
    // the HTML.
    char LEDState[128];
    if (digitalRead(GPIOA, 5) == 1)
      sprintf(LEDState, "The LED is on!\n");
    else
      sprintf(LEDState, "The LED is off!\n");
    
    // Transmit the webpage over UART by sending a series of strings
    // Note: 
    sendString(ESPUSART, webpageStart);
    sendString(ESPUSART, ledStr);
    sendString(ESPUSART, "<br>"); // Line break
    sendString(ESPUSART, "<h2>LED Status</h2>");
    sendString(ESPUSART, LEDState);
    sendString(ESPUSART, webpageEnd);
  }
}
