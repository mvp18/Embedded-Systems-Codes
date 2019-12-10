int sine [255];
const int POT = A0;
int value = 0;
int freq = 0;
int amp = 0;
int data1 = 0;
int data2 = 0;
int data3 = 0; 
int frequency;
int freqCurrent;
unsigned int freqscaled;
void setup () {
pinMode ( 2 , OUTPUT );
pinMode ( 3 , OUTPUT );
pinMode ( 4 , OUTPUT );
pinMode ( 5 , OUTPUT );
pinMode ( 6 , OUTPUT );
pinMode ( 7 , OUTPUT );
pinMode ( 8 , OUTPUT );
pinMode ( 9 , OUTPUT );
Serial . begin ( 9600 ); // Initialize variables
frequency = analogRead ( A4 ); // initialize frequency
// A4 gets the value from DAC output.
freqscaled = 48 * frequency + 1 ; // from 1 to ~50,000\
period = samplerate / freqscaled;
delay ( 3000 ); // So we can see the nice splash screen
// Generate the values of a sine function float
float x , y;
for ( int i = 0 ; i < 255 ; i ++){
x =( float ) i;
y = sin (( x / 255 )* 2 * PI );
sine [ i ]=( int ( y * 128 )+ 128 );
}
}
/*
* @Description : This function generate a sine signal
* @input : freq
*/
void Sine_Function ( int freq ){
for ( int i = 0 ; i < 255 ; i ++){
PORTD = sine [ i ];
amp = analogRead ( A0 ); // A pot is used to give a value between 0 and 5 V to pin
amp = amp / 255.0;
Serial . println ( amp * sine [ i ]); // amplitude control using variable register.
delay(10);
delayMicroseconds ( freq ); }
}
/*
* @Description : This function check the value of the input Analog 4 ( A4 ),
* which configure the frequency of the signal.
* This value will be displayed by the display
*/
void checkFreq () {
freqCurrent = analogRead ( A4 );
}
void loop () {
digitalWrite ( 2 , LOW );
digitalWrite ( 3 , LOW );
digitalWrite ( 4 , LOW );
digitalWrite ( 5 , LOW );
digitalWrite ( 6 , LOW );
digitalWrite ( 7 , LOW );
digitalWrite ( 8 , LOW );
digitalWrite ( 9 , HIGH ); // setting up the DAC output to set up the frequency..
value = analogRead ( A4 );
freq = value * 10;
checkFreq ();
Sine_Function ( freq );
}
