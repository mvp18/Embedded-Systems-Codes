#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int known = A1;
int known_resistance = 1000;
void setup() {
  pinMode(known, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Group No. 11");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);
  int observed_voltage = analogRead(known);
  Serial.println(observed_voltage);
  float voltage = (float)(5*observed_voltage)/1023;
  float current = (5 - voltage)/known_resistance;
  float unknown_resistance = voltage/current;
  lcd.print("resistance = ");
  lcd.print(unknown_resistance);
}
