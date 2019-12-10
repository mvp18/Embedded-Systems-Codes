const int trigPin1 = 11; // the number of the trigger output pin ( sensor 1 )
const int echoPin1 = 10; // the number of the echo input pin ( sensor 1 )
const int trigPin2 = 6; // the number of the trigger output pin ( sensor 2 )
const int echoPin2 = 5; // the number of the echo input pin ( sensor 2 )
////////////////////////////////// variables used for distance calculation
long duration;
int distance1, distance2;
float r;
unsigned long temp=0;
unsigned long temp1=0;
int l=0;
void find_distance (void);
// this function returns the value in cm.
void find_distance (void){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH, 5000);
  r = 3.4 * duration / 2; 
  distance1 = r / 100.00;
//Serial.println(distance1);
//upper part for left sensor and lower part for right sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;
  distance2 = r / 100.00;
  delay(100);
}
void setup(){
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // initialize the trigger and echo pins of both the sensor as input and output:
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay (100);
}
void loop(){
  find_distance(); 
  if(distance2<=35 && distance2>=15){
    temp=millis(); 
    while(millis()<=(temp+300)){
      find_distance();
      }
    if(distance2<=35 && distance2>=15){
      while(distance2<=50 && distance2>=10){
        temp=distance2;
        find_distance();
        if((temp+3)<distance2){
          Serial.println("up2");
          }
        else if((temp-3)>distance2){
          Serial.println("down2"); // send "up" serially.
          }
          }
          }
  else{
  Serial.println("next2"); // send "next" serially.
  }
  }
  if(distance1<=35 && distance1>=15){
    temp1=millis(); 
    while(millis()<=(temp1+300)){
      find_distance();
      }
    if(distance1<=35 && distance1>=15){
      while(distance1<=50 && distance1>=10){
        temp1=distance1;
        find_distance();
        if((temp1+3)<distance1){
          Serial.println("u p1");
          }
        else if((temp1-3)>distance1){
          Serial.println("down1"); // send "up" serially.
          }
          }
          }
  else{
    Serial.println("next1"); // send "next" serially.
    }
    }
}
