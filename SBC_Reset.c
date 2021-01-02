/*
 * File:   SBC_Reset.c
 * Author: Jeremy N. Surma
 *
 * 8-bit Computer reset circuit w/ push-button
 * manual reset.
 * 
 * Written in MPLAB X IDE v5.45
 * 
 * 2020, 12:53 AM
 */

// PIC12F615 Configuration Bit Settings

// 'C' source line config statements
#define _XTAL_FREQ 8000000
#define MS2DELAY 100     // How long to pulse reset (LOW)

// CONFIG
#pragma config FOSC = INTOSCIO   // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on GP4/OSC2/CLKOUT and GP5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config IOSCFS = 8MHZ    // Internal Oscillator Frequency Select (8 MHz)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>

int main()
{
    TRISIO = 0b00000000; //GPIOs as Input/Output PINS
//    GP2 = 1;                // Reset pin HIGH
//    __delay_ms(MS2DELAY);   // Hold reset LOW
    GP2 = 0;                // Reset pin LOW
    __delay_ms(MS2DELAY);   // Hold reset LOW
    GP2 = 1;                // Reset pin HIGH
    while(1){};
return 0;
}