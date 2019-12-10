int lmPin = A0;
const int buzzer = 9;
void setup(){
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); //
}
float tempC(){
  float raw = analogRead(lmPin); //
  float percent = raw/1023.0; //
  float volts = percent*5.0; //
  return 100.0*volts; //
}
void loop(){
  Serial.println(tempC()); //
  if(tempC()>25.0){
    tone(buzzer, 5000);
    }
  else{
    noTone(buzzer);
    }
  delay(200); // ms //
}
