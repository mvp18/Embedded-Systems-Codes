const int LED = 9;
int val = 0;

void setup() {
  pinMode(LED,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  val = analogRead(0);
  analogWrite(LED,val/2);
  Serial.println(val);
  delay(100);
  // put your main code here, to run repeatedly:

}
