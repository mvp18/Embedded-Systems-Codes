int sensorValue; 
int output;
void setup() {
 Serial.begin(9600);
}
 
void loop() {
  sensorValue = analogRead(A0);
  output = map(sensorValue, 1023, 0, 100, 0);
  Serial.println(output);
  delay(1000);
 }
