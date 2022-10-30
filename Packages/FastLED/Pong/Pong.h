#ifndef Pong_h
#define Pong_h

#include "FastLED.h"

#define LED_TYPE WS2811


class Pong {
    private:
        int _numPins;
        // CRGB _leds[_numPins];
    public:
        Pong(int numPins);
        void loop();
};

#endif