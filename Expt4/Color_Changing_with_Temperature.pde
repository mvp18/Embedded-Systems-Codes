import processing.serial.*;
Serial myPort;
String myText="";
float temperature;
void setup(){
size(300, 300);
myPort = new Serial(this, "COM4", 9600);
myPort.bufferUntil('\n');
}
void serialEvent (Serial myPort){
myText = myPort.readStringUntil('\n');
}
void draw() {
  temperature = float(myText);
  background(0, 0, 0);
  if(temperature>=23 && temperature<=24){
  
    background(0,0,255);
    textSize(32);
    text(temperature, 120, 120);
  }
  if(temperature>24 && temperature<=25){
  
    background(0,255,0);
    textSize(32);
    text(temperature, 120, 120);
  }
  if(temperature>25){
  
    background(255,0,0);
    textSize(32);
    text(temperature, 120, 120);
  }
}
