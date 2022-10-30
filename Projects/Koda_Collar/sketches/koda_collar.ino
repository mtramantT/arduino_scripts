#include "MultiSignalPowerButton.h"
#include "Photoresistor.h"

// Pin def.
#define PR_PIN A0
#define LED_PIN 5
#define BUTTON_PIN 7

//Photoresistor def.
#define PR_THRESHOLD 650

bool deviceOn;

Photoresistor pr(PR_PIN, PR_THRESHOLD);
MultiSignalPowerButton button(BUTTON_PIN); 

void setup(
    deviceOn = false;
);

void loop(

);