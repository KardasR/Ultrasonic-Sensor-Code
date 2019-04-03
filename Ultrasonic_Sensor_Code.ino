/*
   Sonar using NewPing library

   author: Ryan Kardas
*/
#include <NewPing.h>

// pins
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200
#define redint A1
#define greenint A0

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
   // activate serial at baud rate of 9600
   Serial.begin(9600);

   // activate pins as output
   pinMode(redint, OUTPUT);
   pinMode(greenint, OUTPUT);
}  // end setup

void loop() {
   // wait 50 milliseconds
   delay(50);

   // uses NewPing to get data from ultrasonic sensor
   unsigned int distance = sonar.ping_in();

   // prints output
   Serial.print("Dist: ");
   Serial.print(distance);
   Serial.println(" inches");

   // blinks red if object is <= 5 inches away
   if(distance <= 5) {
      Serial.println("Object Detected");
      // turn off green led
      digitalWrite(greenint, LOW);
      // turn on red led
      digitalWrite(redint, HIGH);
      delay(50);
      // turn off red led
      digitalWrite(redint, LOW);
      delay(50);
   }
   // otherwise, stay green
   else {
      digitalWrite(greenint, HIGH);
      digitalWrite(redled, LOW);
   }
} // end loop
