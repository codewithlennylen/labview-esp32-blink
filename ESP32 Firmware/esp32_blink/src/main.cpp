#include <Arduino.h>


const int ledPin = 2; // Internal LED is usually on GPIO 2

void setup() {

  // Initialize Serial Communication at 9600 baud rate
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  
  // Blink once to show we are alive
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

void loop() {

  // Check if data is available on the USB port
  if (Serial.available() > 0) {
    
    // Read the incoming character
    char command = Serial.read();
    
    if (command == '1') {
      digitalWrite(ledPin, HIGH); // Turn LED ON
    } 
    else if (command == '0') {
      digitalWrite(ledPin, LOW);  // Turn LED OFF
    }
  }
}
