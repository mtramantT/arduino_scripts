#ifndef MultiSignalPowerButton_h
#define MultiSignalPowerButton_h

#include "Arduino.h"

// Output Signals
#define CONTINUE_SIGNAL 0             // Default signal to return incase of no new actions.
#define LONG_CLICK_SIGNAL 1           // Hold Event occured. The button was pressed for a long duration.
#define DOUBLE_CLICK_SIGNAL 2         // Double Click Event occured. The button had been pressed twice before a gap cooldown. 

// Button States
#define PRESSED HIGH             // When the button is pressed, the input signal will be LOW.
#define RELEASED LOW           // When the button is released, the input signal will be HIGH.

// Timings
#define DEBOUNCE_TIME 50                    // Delay in which to wait for fluctuations to settle before another input can be registered
#define DOUBLE_CLICK_WAIT_PERIOD 250        // How long to wait between clicks to register them as a double click.
#define HOLD_DURATION 1500                  // How long the button should be held for a Hold Event to occur.

class MultiSignalButton {
    private:
        int _pin;                           // The button's input pin.
        int _currentState;                  // The current state the button is in.
        int _previousState;                 // The last state the button is in.
        unsigned long _pressedTime;         // Recorded time of button press.
        unsigned long _releasedTime;        // Recorded time of button release.
        bool _isHoldEventActive;            // A Hold event was triggered. Wait for next press.
        bool _isDoubleClickOnRelease;       // The next release of the button is a double click.
        bool _isPendingDoubleClick;         // Primes the press to register the next release as a double click.
        bool isPressed();                   // Determines if a button was presed (Debounced).
        bool isReleased();                  // Determines if a button was released (Debounced).
        bool isHolding();                   // Determines if a button is being held.
    public:
        MultiSignalButton(int pin);
        int detectInput();
};

#endif