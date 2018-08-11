#include <stdint.h>
#include <pic32mx.h>
#include "constants.h"
#include "synth.h"

void init() {
    // Konfigurera Compare registers (OC1) och slå på
    // PWM-mode.
    OC1CON = 0x0000;
    OC1R = 0x0000;
    OC1RS = 0x0000;
    OC1CON = 0x0006;

    // Konfigurera Timer2 med 1:1 prescale och 256 som period
    // 312.5 kHz
    T2CONSET = 0x0000;
    PR2 = 256;

    // Konfigurera Timer3 med 1:1 prescale och 5000 som period.
    // 16 kHz
    T3CON = 0x0;
    T3CONSET = 0x0000;
    TMR3 = 0x0;
    PR3 = 5000;

    // Konfigurera interrupts för Timer3 med högsta prioritet.
    IFSCLR(0) = 0x00001000;
    IECSET(0) = 0x00001000;
    IPCSET(3) = 0x0000001C;

    // Slå på interrupts.
    asm("ei");

    // Slå på Timer2 (för PWM rate), Timer3 (sample rate) och OC1 (för PWM-output).
    T2CONSET = 0x8000;
    T3CONSET = 0x8000;
    OC1CON |= 0x8000;

    // PIN 8: OUTPUT
    TRISD &= ~0x400;
    PORTD |= 0x400;

    // PIN 37: INPUT - C
    TRISD |= 0x80;
    PORTD &= ~0x80;

    // PIN 36: INPUT - C#
    TRISD |= 0x40;
    PORTD &= ~0x40;

    // PIN 35: INPUT - D
    TRISD |= 0x800;
    PORTD &= ~0x800;

    // PIN 34: INPUT - D#
    TRISD |= 0x20;
    PORTD &= ~0x20;

    // PIN 33: INPUT - E
    TRISE |= 0x80;
    PORTE &= ~0x80;

    // PIN 32: INPUT - F
    TRISE |= 0x40;
    PORTE &= ~0x40;

    // PIN 31: INPUT - F#
    TRISE |= 0x20;
    PORTE &= ~0x20;

    // PIN 30: INPUT - G
    TRISE |= 0x10;
    PORTE &= ~0x10;

    // PIN 29: INPUT - G#
    TRISE |= 0x8;
    PORTE &= ~0x8;

    // PIN 28: INPUT - A
    TRISE |= 0x4;
    PORTE &= ~0x4;

    // PIN 27: INPUT - A#
    TRISE |= 0x2;
    PORTE &= ~0x2;

    // PIN 26: INPUT - B
    TRISE |= 0x1;
    PORTE &= ~0x1;
}


int main() {
    init();

    // Programloop
    while (1) {
        fetchKeyboard();
    }

	return 0;
}
