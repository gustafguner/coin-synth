#include <pic32mx.h>
#include "synth.h"

double index = 0;
double step = 0;
int canPlay = 0;
int periodType = 1; // styr vilken sorts period som ska spelas upp

/*
ISR för Timer3. Uppdaterar duty cycle genom att hämta nästa värde från sinusarray
med viss steglängd. Ju högre steglängd, desto högre frekvens. För att nå "element" med
decimala index används linjär interpolation för att istället approximera värdet.
*/
void user_isr(void) {
    IFS(0) = 0;

    if (canPlay) {
        index += step;
        if (index >= 63) index -= 63;

        // Linjär interpolation
        int x0 = (int)index;
        int x1 = (int)index+1;

        int y0 = PERIODS[periodType][x0];
        int y1 = PERIODS[periodType][x1];

        int y = y0 + (index - x0) * ((y1-y0)/(x1-x0));

        // Sätt nya duty cycle
        OC1RS = y;
    }
}

/*
En funktion som sätter canPlay till 1 så att ljud kan spelas upp och även
tilldelar ett värde till step för att kontrollera frekvens.
*/
void playNote(double stepSize) {
    canPlay = 1;
    step = stepSize;
}
