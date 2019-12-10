int bit0 = 2;
int bit1 = 3;
int bit2 = 4;
int bit3 = 5;
int bit4 = 6;
int bit5 = 7;
int bit6 = 8;
int bit7 = 9;
int output = A0;
void setup() {
pinMode(bit0,OUTPUT);
pinMode(bit1,OUTPUT);
pinMode(bit2,OUTPUT);
pinMode(bit3,OUTPUT);
pinMode(bit4,OUTPUT);
pinMode(bit5,OUTPUT);
pinMode(bit6,OUTPUT);
pinMode(bit7,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}
void loop() {
digitalWrite(bit0,HIGH);
digitalWrite(bit1,HIGH);
digitalWrite(bit2,HIGH);
digitalWrite(bit3,HIGH);
digitalWrite(bit4,HIGH);
digitalWrite(bit5,HIGH);
digitalWrite(bit6,HIGH);
digitalWrite(bit7,HIGH);
analogRead(A0);
Serial.println(A0);
delay(1000);
}
