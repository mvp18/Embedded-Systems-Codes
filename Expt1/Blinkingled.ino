void setup() {  // initialize digital pin 13 as an output.
   pinMode(A2, OUTPUT);
}

// the loop function runs over and over again forever

void loop() {
   analogWrite(A2, 1023); // turn the LED on (HIGH is the voltage level)
   delay(4000); // wait for a second
   digitalWrite(A2, 0); // turn the LED off by making the voltage LOW
   delay(4000); // wait for a second
}
