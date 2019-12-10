int trigPin = 8; //
int echoPin = 7; //
int irPin=2; //
int objectDetected=LOW; //
float v=331.5+0.6*20; // m/s //
void setup() //
{
  Serial.begin(9600); //
  pinMode(trigPin, OUTPUT); //
  pinMode(echoPin, INPUT); //
  pinMode(irPin, INPUT);
  digitalWrite(irPin, HIGH); // internal pull-up
}
float distanceCm(){ //
  // send sound pulse //
  digitalWrite(trigPin, LOW); //
  delayMicroseconds(3); //
  digitalWrite(trigPin, HIGH); //
  delayMicroseconds(5); //
  digitalWrite(trigPin, LOW); //
  // listen for echo //
  float tUs = pulseIn(echoPin, HIGH); // microseconds //
  float t = tUs / 1000.0 / 1000.0 / 2.0; // s //
  float d = t*v; // m //
  return d*100; // cm //
}
void loop() //
{
  objectDetected=digitalRead(irPin);
  if (LOW==objectDetected) {
    int d=distanceCm(); //
    Serial.println(d, DEC); //
  }
  else{
    int d = -1;
    Serial.println(d);
  }
  delay(200); // ms //
}
