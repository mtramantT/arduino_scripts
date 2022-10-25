#ifndef TactileButton_h
#define TactileButton_h

#include "Arduino.h"

#define SHORT_PRESS_TIME 500
#define LONG_PRESS_TIME 1500
#define EXTRA_LONG_PRESS_TIME 3000
#define TIME_LIMIT 3000

class TactileButton {
    private:
        int _pin;
        int _previousState;
        int _currentState;
        int _pressTime;
        int _releaseTime;
        int _timer;
        int _numPresses;
    public:
        TactileButton(int pin);
        int detectInput();
};

#endif