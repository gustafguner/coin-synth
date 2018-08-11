#include <pic32mx.h>
#include "synth.h"

/*
Simpel sleepfunktion.
*/
void quicksleep(int cyc) {
	long i;
	for(i = cyc*4000; i > 0; i--);
}

// Array innehållande steg att skifta i fetchKeyboard()
const int shifts[] = {7, 6, 11, 5, 7, 6, 5, 4, 3, 2, 1, 0};

int octave = 2;

int ticks = 0;
int totalsounds = 0;
double totalStep = 0;

/*
Kärnfunktionen i synthesizern. Söker igenom alla 12 inputs och formar ljud beronde
på vilka som är på.
*/
void fetchKeyboard() {
	totalsounds = 0;
	totalStep = 0;

	// Itererar 12 gånger pga 12 mynt
	int i;
	for (i = 0; i < 12; i++) {
		PORTD |= 0x400; // Slå på ström

		// Upp till index 3 används PORTD, sedan används PORTE.
		// Inkrementerar ticks medan den aktuella pin är av.
		if (i < 4) {
			do {
		        ticks++;
		    } while (!((PORTD >> shifts[i]) & 0x1));
		} else {
			do {
		        ticks++;
		    } while (!((PORTE >> shifts[i]) & 0x1));
		}

		// Om det tog tillräckligt många ticks för strömmen att gå igenom
		// drar vi slutsatsen att en finger lagts på myntet och spelar därför ljud.
	    if (ticks >= 18) {
			totalStep += FREQUENCIES[i + octave*12];
	        totalsounds++;
	    }

		// Slå av ström och sleep
		PORTD &= ~0x400;
	    quicksleep(1);

		if (i < 11) {
			ticks = 0;
		}

	}

	// Om inga ljud spelas tystar vi ljudet ut, annars skickar vi in genomsnittet
	// av steglängden i funktionen playNote().
	if (!totalsounds) {
		canPlay = 0;
	} else {
		playNote((double) (totalStep/totalsounds));
	}
	ticks = 0;
}
