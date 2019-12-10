// includes the LiquidCrystal Library
#include <LiquidCrystal.h> 

// includes the LcdBarGraph Library
#include <LcdBarGraph.h>

// Maximum distance we want to ping for (in centimeters).
#define max_distance 30

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

LcdBarGraph lbg(&lcd, 16, 0, 1); // Creates an LCD Bargraph object.

const int trigPin = 9;
const int echoPin = 10;
int redPin= 6;
int greenPin = 7;
int bluePin = 8;
int buzzer = 13;
long duration;
int distance;
const int freq1 = 220; //Low Note A
const int freq2 = freq1 * 2; //Med
const int freq3 = freq1 * 3; //Hi
const int freq4 = freq1 * 4; //Very Hi
boolean play=false;

void setup() 
{
//  Serial.begin(9600);
  lcd.begin(16,2); // Initializes the interface to the LCD screen
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void makeBeep(int intervalSeconds, int howlongSeconds, int freq) {
  tone(buzzer, freq, howlongSeconds * 1000);
}

void loop() 
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH, 5000);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance= duration*0.034/2;

  if(distance<=8){
    setColor(255, 0, 0);
    play=true;
    }
  else if(distance>=8 && distance<=15){
    setColor(0, 0, 255);
    play=false;
    }
  else{
    setColor(0, 255, 0);
    play=false;
    }
  if (play == true) {
    makeBeep(1, 1, freq1); // Desc: in 1 second ahead beep an "A" note in 1 second length
    makeBeep(5, 1, freq1);
    makeBeep(5, 1, freq2);
    makeBeep(1, 1, freq3);
    makeBeep(1, 1, freq4);
    }
  if(play==false){
    noTone(buzzer);
    }

//  Serial.println(distance);
  
  // Prints "Distance: <value>" on the first line of the LCD
  lcd.setCursor(0,0);
  lcd.print("Distance: "); 
  lcd.print(distance);
  lcd.print(" cm");

  // Draws bargraph on the second line of the LCD
  lcd.setCursor(0,1);
  lbg.drawValue(distance, max_distance);
  delay(500);
}
