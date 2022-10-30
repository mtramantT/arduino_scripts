#ifndef Photoresistor_h
#define Photoresistor_h

#include "Arduino.h"

#define ON 1
#define OFF 0

class Photoresistor {
    private:
        int _pin;
        int _threshold;
        int _updatePeriod;
    public:
        Photoresistor(int pin, int threshold, int updatePeriod);
        int detectInput();
};

#endif