#include <AFMotor.h> //Import Motor.h Library

AF_DCMotor motor(1); 

void setup() {
  Serial.begin(9600); // Open Serial communication at baud rate 9600 bps
  Serial.println("Testing the Motor");
  
  motor.setSpeed(200); // Set the motor speed at 200 to 255 PWM
}
 
void loop() { 
  Serial.println("Turning Backward");
  motor.run(BACKWARD);     // the other way
  delay(4000); // delay at 1 second
//  Serial.println("Turning Forward");
//  motor.run(FORWARD);     // the other way
//  delay(4000); // delay at 1 second
  Serial.println("Release or Stop");
  motor.run(RELEASE);      // Motor will stop
  delay(4000); // delay at 1 second
}
