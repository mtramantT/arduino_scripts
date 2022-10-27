#include "MultiClickButton.h"

MultiClickButton::MultiClickButton(int pin) {
    pinMode(_pin, INPUT);
    _pin = pin;
    _currentState = RELEASED;
    _previousState = RELEASED;
    _pressTime = 0;
    _releaseTime = 0;
    _dcOnRelease = false;
    _ignoreOnRelease = false;
    _dcPending = false;
}

int MultiClickButton::detectInput() {
    int event = 0;
    int _currentState = digitalRead(_pin);

    // Button is pressed.
    if (_currentState == PRESSED && _previousState == RELEASED && (millis() - _releaseTime) > DEBOUNCE_TIME) {
        _pressTime = millis();
        _ignoreOnRelease = false;
        _isHoldEvent = false;
        if ((millis() - _releaseTime) < DC_GAP && _dcOnRelease == false && _dcPending == true) {
            _dcOnRelease = true;
        } else {
            _dcOnRelease = false;
        }
        _dcPending = false;
    } 
    // Button is released.
    else if (_currentState == RELEASED && _previousState == PRESSED && (millis() - _pressTime) > DEBOUNCE_TIME) {
        if (! _ignoreOnRelease) {
            _releaseTime = millis();
            if (!_dcOnRelease) {
                _dcPending = true;
            } else {
                event = 2;
                _dcOnRelease = false;
                _dcPending = false;
            }
        }
    }

    // Test for single click (i.e the dcGap expired)
    if (_currentState == RELEASED && (millis() - _releaseTime) >= DC_GAP && _dcPending ==true && _dcOnRelease == false && event != 1) {
        _dcPending = false;
    }

    // Test for hold.
    if (_currentState == PRESSED && (millis() - _pressTime) >= HOLD_TIME) {
        if (! _isHoldEvent) {
            event = 1;
            _isHoldEvent = true;
            _ignoreUp = true;
            _dcOnRelease = false;
            _dcPending = false;
        }
    }
}