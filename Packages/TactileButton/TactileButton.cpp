#include "TactileButton.h"

TactileButton::TactileButton(int pin, int debounceDelay) {
    pinMode(pin, INPUT_PULLUP);
    _pin = pin;
    _debounceDelay = debounceDelay;
    _previousState = LOW;
    _pressTime = 0;
    _releaseTime = 0;
    _timer = 0;
    _numPresses = 0;
    _lastSteadyState = LOW;
    _lastFlickerableState = LOW;
    _lastDebounceTime = 0;
}

int TactileButton::detectInput() {
    int currentState = digitalRead(_pin);
    int result = 0;
    
    if (currentState != _lastFlickerableState) {
        _lastDebounceTime = millis();
        _lastFlickerableState = currentState;
    }

    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (_lastSteadyState == HIGH && currentState == LOW) {
            _pressTime = millis();
        }
        else if (_lastSteadyState == LOW && currentState == HIGH) {
            _releaseTime = millis();
            long pressDuration = _releaseTime - _pressTime;

            if( pressDuration < SHORT_PRESS_TIME ) {
                result = 1;
            }
            if (pressDuration > LONG_PRESS_TIME ) {
                result = 2;
            }
        }

        _lastSteadyState = currentState;
        return result;
    }
}



int TactileButton::readInput(int input) {
  if ( input == LONG_PRESS_TIME ) {
    return 1;
  }
  if ( input == SHORT_PRESS_TIME ) {
    _numPresses += _numPresses;
    if ()
  }

//     // Button pressed
//     if ( _previousState == HIGH && _currentState == LOW ) {
//         _pressTime = millis();
//     }else if ( _previousState == LOW && _currentState == HIGH ) {
//         _releaseTime = millis();
        
//         long pressDuration = _releaseTime - _pressTime;
//         if ( pressDuration > EXTRA_LONG_PRESS_TIME ) { return 4; }
//         if ( pressDuration > LONG_PRESS_TIME ) { return 5; }
//         if ( pressDuration < SHORT_PRESS_TIME ) {
//             _numPresses += _numPresses;

//             if ( _timer == 0 ) {
//                 _timer = millis();
//             }
//         }
//     }

//     // Short press timing.
//     long pressTimer = millis() - _timer;
//     long result = 0;
//     if ( _timer > 0 && pressTimer > TIME_LIMIT && _numPresses < 5 && _numPresses > 2) {
//         result = _numPresses - 2;
//         _numPresses = 0;
//         _timer = 0;
//     }
//     if (_timer > 0 && pressTimer > TIME_LIMIT) {
//         _numPresses = 0;
//         _timer = 0;
//     }

//     _previousState = _currentState;
//     return result;
// }
}