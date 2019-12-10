#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define Xdelay 1900
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Group No. 11");
  delay(Xdelay);
}

void loop() {
  // put your main code here, to run repeatedly:
}
