#ifndef Photoresistor_h
#define Photoresistor_h

#include "Arduino.h"

#define ON 1
#define OFF 0

class Photoresistor {
    private:
        int _pin;
        int _threshold;
        int _readings[];
    public:
        Photoresistor(int pin, int threshold, int updatePeriod = 100);
        // Photoresistor(int pin, int updatePeriod);

        int #include "Photoresistor.h"

Photoresistor::Photoresistor(int pin, int threshold, int updatePeriod) {
    _pin = pin;
    _threshold = threshold;
    _updatePeriod = updatePeriod;
}

Photoresistor::detectInput() {
    int readings = 0;
    for (int i=0; i<=_updatePeriod; i++ ) {
        int reading = analogRead(_pin);
        readings += reading;
        delay(50);
    }

    if ((readings / _updatePeriod) < threshold) {
        return ON;
    } else {
        return OFF;
    }

}();

}

#endif