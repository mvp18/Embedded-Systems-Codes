#include <AFMotor.h> //Import Motor.h Library
int lmPin = A1;
AF_DCMotor motor(1); 
void setup() {
  Serial.begin(9600); // Open Serial communication at baud rate 9600 bps
//  Serial.println("Testing the Motor");
  motor.setSpeed(100); // Set the motor speed at 200 to 255 PWM
}

float tempC(){
  float raw = analogRead(lmPin); //
  float percent = raw/1023.0; //
  float volts = percent*5.0; //
  return 100.0*volts; //
}
 
void loop() {
  // Read any serial input
  Serial.println(tempC());
  if (tempC() > 28.0){
    int m_speed = 200;
    Serial.println("High Temperature, Increasing Speed.");
    motor.setSpeed(m_speed);
    }
  else{
    int m_speed = 100;
    Serial.println("Normal Temperature, Maintaining Speed at 100");
    motor.setSpeed(m_speed);
    } 
  
//  Serial.println("Turning Backward");
  motor.run(BACKWARD);  
  delay(1000);
}
