const int ledPin13 = 13; 
float outputValue = 0.0;
const int analogInPin = A5;
int sensorValue = 0;

void setup() {
 
 pinMode(ledPin13, OUTPUT);
 Serial.begin(9600);

}
void loop(){
  
  sensorValue = analogRead(analogInPin);
  outputValue = sensorValue/1023.0;
  Serial.println(outputValue);
  if (outputValue >= 0.8) {

    digitalWrite(ledPin13, HIGH);    
  }
  else{

    digitalWrite(ledPin13, LOW);
  }
  delay(100);
}
