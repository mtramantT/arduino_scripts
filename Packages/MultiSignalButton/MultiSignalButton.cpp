#include "MultiSignalButton.h"

MultiSignalButton::MultiSignalButton(int pin) {
    pinMode(_pin, INPUT);
    _pin = pin;
    _currentState = RELEASED;
    _previousState = RELEASED;
    _pressedTime = 0;
    _releasedTime = 0;
    _isHoldEventActive = false;
    _isDoubleClickOnRelease = false;
    _isPendingDoubleClick = false;
}

int MultiSignalButton::detectInput() {
    int signal = CONTINUE_SIGNAL; // The default output signal.
    _currentState = digitalRead(_pin);

    // Button was pressed.
    if (isPressed()) {
        _pressedTime = millis();
        _isHoldEventActive = false;
        if ((millis() - _releasedTime) < DOUBLE_CLICK_WAIT_PERIOD && _isDoubleClickOnRelease == false && _isPendingDoubleClick == true) {
            _isDoubleClickOnRelease = true;
        } else {
            _isDoubleClickOnRelease = false;
        }
        _isPendingDoubleClick = false;
    } 
    // Button was released
    else if (isReleased()) {
        _releasedTime = millis();
        if (_isDoubleClickOnRelease == true) {
            _isPendingDoubleClick = false;
            _isDoubleClickOnRelease = false;
            signal = DOUBLE_CLICK_SIGNAL;
        } else {
            _isPendingDoubleClick = true;
        }
    }

    // Test for hold event.
    if (isHolding()) {
        if (_isHoldEventActive == false) {
            signal = LONG_CLICK_SIGNAL;
            _isHoldEventActive = true;
        }
    }

    _previousState = _currentState;
    return signal;
}


bool MultiSignalButton::isPressed() {
    return _currentState == PRESSED && _previousState == RELEASED && ((millis() - _releasedTime) > DEBOUNCE_TIME);
}

bool MultiSignalButton::isReleased() {
    return _currentState == RELEASED && _previousState == PRESSED && ((millis() - _pressedTime) > DEBOUNCE_TIME);
}

bool MultiSignalButton::isHolding() {
    return _currentState == PRESSED && ((millis() - _pressedTime) >= HOLD_DURATION);
}