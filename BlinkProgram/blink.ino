#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  static int i = 0;
  Serial.println("Hello world " + String(i++));
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}