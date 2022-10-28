#include "MultiSignalButton.h"

#define BUTTON_PIN 7
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6

MultiSignalButton signalButton(BUTTON_PIN);
int counter;
bool isOn;

void setup() {
    Serial.begin(9600);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LED_5, OUTPUT);
    counter = 0;
    isOn = false;
}

void loop() {
    int result = signalButton.detectInput();
    if (result == 1) {
      isOn = !isOn;
    }
    if (isOn) {
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_1, LOW);
    } else {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      turnAllOff(0);
    }

    // Counter and reset
    if (isOn && result == 2) {
      if (counter == 2) {
        counter = 0;
      } else {
        counter++;
      }
    }

    if (counter == 0 && isOn) {
      digitalWrite(LED_3, HIGH);
      turnAllOff(LED_3);
    }
    if (counter == 1 && isOn) {
      digitalWrite(LED_4, HIGH);
      turnAllOff(LED_4);
    }
    if (counter == 2 && isOn) {
      digitalWrite(LED_5, HIGH);
      turnAllOff(LED_5);
    }
    
    // Logger
    if (result > 0) {
        Serial.println(result);
    }
}

void turnAllOff(int ext) {
  for (int i=4; i <=6; i++) {
    if (ext != i) {
      digitalWrite(i, LOW);
    }
  }
}