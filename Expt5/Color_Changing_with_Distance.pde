import processing.serial.*;
Serial myPort;
String d = "";
float distance;
void setup(){
size(300, 300);
myPort = new Serial(this, "COM5", 9600);
myPort.bufferUntil('\n');
}
void serialEvent (Serial myPort){
d = myPort.readStringUntil('\n');
}
void draw() {
  
  distance = float(d);
  print(distance); 
  background(0, 0, 0);
  if(distance>=5 && distance<=20){
  
    background(255,0,0);
    textSize(32);
    text(distance, 120, 120);
  }
  if(distance>20 && distance<=40){
  
    background(0,0,255);
    textSize(32);
    text(distance, 120, 120);
  }
  
  if(distance>40){
  
    background(127,0,255);
    textSize(32);
    text(distance, 120, 120);
  }
  
  if(distance==-1){
  
    background(0,255,0);
    textSize(32);
    text(distance, 120, 120);
  }
}
