#include "TactileButton.h"

TactileButton tButton(7);

#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5

void setup() {
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

void loop() {
  int result = tButton.detectInput();
  digitalWrite(result, HIGH);
  turnOthersOff(result);
}

void turnOthersOff(int ext) {
  for(int i = 1; i <= 5; i++) {
    if (ext != i) {
      digitalWrite(i, LOW);
    }
  }
}
