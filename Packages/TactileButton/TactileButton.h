#ifndef TactileButton_h
#define TactileButton_h

#include "Arduino.h"

#define NO_INPUT 0
#define SHORT_PRESS 1
#define LONG_PRESS 2

// #define DEBOUNCE_DELAY  50

#define SHORT_PRESS_TIME 500
#define LONG_PRESS_TIME 1000
#define EXTRA_LONG_PRESS_TIME 3000
#define TIME_LIMIT 3000

class TactileButton {
    private:
        int _pin;
        int _debounceDelay;
        int _previousState;
        // int _currentState;
        unsigned long _pressTime;
        unsigned long _releaseTime;
        int _timer;
        int _numPresses;
        int _lastSteadyState;
        int _lastFlickerableState;
        unsigned long _lastDebounceTime;
    public:
        TactileButton(int pin, int debounceDelay);
        int detectInput();
        int readInput(int input);
};

#endif