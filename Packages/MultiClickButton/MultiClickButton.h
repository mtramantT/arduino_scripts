
#ifndef MultiClickButton_h
#define MultiClickButton_h

#include "Arduino.h"

// Button States
#define PRESSED LOW
#define RELEASED HIGH

// Button Timings
#define DEBOUNCE_TIME 30
#define HOLD_TIME 1000
#define DC_GAP 250


class MultiClickButton {
    private:
        int _pin;
        int _currentState;
        int _previousState;
        int _lastDebounceTime;
        int _lastSteadyState;
        int _pressTime;
        int _releaseTime;
        bool _dcOnUp;
        bool _ignoreUp;
        bool _dcPending;
        bool _isHoldEvent;
    public:
        MultiClickButton(int pin);
        int detectInput();
}

#endif