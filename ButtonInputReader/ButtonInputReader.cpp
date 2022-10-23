#include "Arduino.h"
#include "ButtonInputReader.h"

ButtonInputReader::ButtonInputReader(int pin) {
    pinMode(pin, INPUT_PULLUP);
    _pin = pin;
    _currentState = 0;
    _previousState = LOW;
    _pressTime = 0;
    _releaseTime = 0;
    _timer = 0;
    _numPresses = 0;
}


int ButtonInputReader::detectInput() {
    _currentState = digitalRead(_pin);

    // Button pressed
    if ( _previousState == HIGH && _currentState == LOW ) {
        _pressTime = millis();
    }else if ( _previousState == LOW && _currentState == HIGH ) {
        _releaseTime = millis();
        
        long pressDuration = _releaseTime - _pressTime;
        if ( pressDuration > EXTRA_LONG_PRESS_TIME ) { return 4; }
        if ( pressDuration > LONG_PRESS_TIME ) { return 5; }
        if ( pressDuration < SHORT_PRESS_TIME ) {
            _numPresses += _numPresses;

            if ( _timer == 0 ) {
                _timer = millis();
            }
        }
    }

    // Short press timing.
    long pressTimer = millis() - _timer;
    long result = 0;
    if ( _timer > 0 && pressTimer > TIME_LIMIT && _numPresses < 5 && _numPresses > 2) {
        result = _numPresses - 2
        _numPresses = 0;
        _timer = 0;
    }
    if (_timer > 0 && pressTimer > TIME_LIMIT) {
        _numPresses = 0;
        _timer = 0;
    }

    _previousState = _currentState;
    return result;
    
}