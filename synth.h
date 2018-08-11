void quicksleep();
void fetchKeyboard();
void stopSound();
void playNote(double stepSize);

int ticks;
int canPlay;
int totalsounds;
double step;
const unsigned int PERIODS[2][64];
const double FREQUENCIES[];
int soundsPlaying();
