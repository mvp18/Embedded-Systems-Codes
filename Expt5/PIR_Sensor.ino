int irPin=7; //
int ledPin=13;
int objectDetected=LOW; //
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);
  digitalWrite(irPin, HIGH); // internal pull-up
  Serial.begin(9600);
}
void loop() {
  objectDetected=digitalRead(irPin);
  Serial.println(objectDetected);
  if (LOW==objectDetected) {
    digitalWrite(ledPin, HIGH);
    } 
  else {
    digitalWrite(ledPin, LOW);
    }
}
