const int analog1 = A0;
const int analog2 = A1;
const int buzzer = 9;
float val = 0.0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int v1 = analogRead(analog1);
  int v2 = analogRead(analog2);
  val = (v1-v2)/1023.0;
  Serial.print("v1 = ");
  Serial.print(v1);
  Serial.print(" v2 = ");
  Serial.print(v2);
  Serial.println(val);
  if (val<0.0){
    tone(buzzer, 5000);
  }
  else{
    noTone(buzzer);
  }
  // put your main code here, to run repeatedly:

}
