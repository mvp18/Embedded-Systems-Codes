#include <AFMotor.h> //Import Motor.h Library

AF_DCMotor motor(1); 
void setup() {
  Serial.begin(9600); // Open Serial communication at baud rate 9600 bps
  Serial.println("Testing the Motor");
  
  motor.setSpeed(200); // Set the motor speed at 200 to 255 PWM
}
 
void loop() {
  // Read any serial input
  if (Serial.available() > 0){
    int m_speed = Serial.readStringUntil('\n').toInt();
    Serial.println("New speed : ");
    Serial.print(m_speed);
    motor.setSpeed(m_speed);
    } 
  
  Serial.println("Turning Backward");
  motor.run(BACKWARD);  
  delay(10000);
}
