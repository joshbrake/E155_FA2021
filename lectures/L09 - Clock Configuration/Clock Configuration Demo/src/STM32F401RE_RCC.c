// STM32F401RE_RCC.c
// Source code for RCC functions

#include "STM32F401RE_RCC.h"

void configurePLL() {
    // Set clock to 84 MHz
    // Output freq = (src_clk) * (N/M) / P
    // (8 MHz) * (336/16) / 4 = 42 MHz
    // M:16, N:336, P:4, Q:7
    // Use HSE as PLLSRC

    RCC->CR.PLLON = ; // Turn off PLL
    while (RCC->CR.PLLRDY != ); // Wait till PLL is unlocked (e.g., off)

    // Load configuration
    RCC->PLLCFGR.PLLSRC = ;
    RCC->PLLCFGR.PLLM = ;
    RCC->PLLCFGR.PLLN = ;
    RCC->PLLCFGR.PLLP = ;
    RCC->PLLCFGR.PLLQ = ;

    // Enable PLL and wait until it's locked
    RCC->CR.PLLON = ;
    while(RCC->CR.PLLRDY == );
}

void configureClock(){
    // Turn on and bypass for HSE from ST-LINK
    RCC->CR.HSEBYP = 1;
    RCC->CR.HSEON = 1;
    while(!RCC->CR.HSERDY);
    
    // Configure and turn on PLL
    configurePLL();

    // Select PLL as clock source
    RCC->CFGR.SW = SW_PLL;
    while(RCC->CFGR.SWS != 0b10);
}