/**
    Signal Outputs:
    0 = Do Nothinn
    1 = 3 short button presses. Output signal
    2 = 4 short button presses. Output signal
    3 = N/A
    4 = Extra long button press. Demo signal
    5 = Long button press. Power toggle
*/

#ifdef ButtonInputReader_h
#define ButtonInputReader_h
#include "Arduino.h"

const SHORT_PRESS_TIME = 500;
const LONG_PRESS_TIME = 1500;
const EXTRA_LONG_PRESS_TIME = 3000;
const TIME_LIMIT = 3000;

export class ButtonInputReader {
    public:
        ButtonInputReader(int pin);
        int detectInput();
    private:
        int _pin;
        int _previousState;
        int _currentState;
        int _pressTime;
        int _releaseTime;
        int _timer;
        int _numPresses;
};
#endif