#include "MultiSignalButton.h"

#define BUTTON_PIN 7

MultiSignalButton signalButton(BUTTON_PIN);

void setup() {
    Serial.begin(9600)
}

void loop() {
    int result = signalButton.detectInput();
    Serial.println(result);
}