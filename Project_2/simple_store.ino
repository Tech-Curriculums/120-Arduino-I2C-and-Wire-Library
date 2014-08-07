#include <Wire.h>

void setup(){
  Serial.begin(9600);  
  Serial.println("Serial Connection Established");
  pinMode(4,OUTPUT);
}

//0b1010 _ _ _  is the fram I2C Address (the last three are "0"'s if you connect address pins, A1 A2 A3, to gnd)  

char c ='';
uint8_t store_this_number = 1; // max 256
    
void loop() {

  if (Serial.available()) {
   switch ( c ) {
   case '1':
    //Wire.beginTransmission(0b1010000);
    Wire.beginTransmission(0x50);
    Wire.write(0xff); //8bit address 1st half
    Wire.write(0xff); //8bit address 2nd half
    Wire.write(store_this_number); //central-writing 
    Wire.endTransmission();//wait for acknowledge
  break
  case '2':
    //Wire.beginTransmission(0b1010000);
    Wire.beginTransmission(0x50);
    Wire.write(0xff); //8bit address 1st half
    Wire.write(0xff); //8bit address 2nd half
    Wire.endTransmission();//wait for acknowledge
    Wire.requestFrom(0x50, (uint8_t) 1);
    break;
  case '3':
    store_this_number++;
    break;
  default:
    break;
  }
  else {
    delay(1);
  }
}
