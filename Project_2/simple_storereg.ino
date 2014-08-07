#include <Wire.h>

char c ='0';
uint8_t store_this_number = 1; // max 256


void setup(){
  Serial.begin(9600);  
  Serial.println("Serial Connection Established");

  Wire.begin();
  Serial.println("Press 'a' to store the number, 'b' to read the number, 'c' to increment the counter");

}

//0b1010 _ _ _  is the fram I2C Address (the last three are "0"'s if you connect address pins, A1 A2 A3, to gnd)  


void loop() {

  if (Serial.available() > 0) {
    c = Serial.read();
    switch ( c ) {
    case 'a':

      //Wire.beginTransmission(0b1010000);
      Wire.beginTransmission(0x50);
      Wire.write(0xff); //8bit address 1st half
      Wire.write(0xff); //8bit address 2nd half
      Wire.write(store_this_number); //central-writing 
      Wire.endTransmission();//wait for acknowledge
      
      Serial.println(""); // for spacing
      
      Serial.print(store_this_number); Serial.println(" has been stored");
      break;
    case 'b':
      //Wire.beginTransmission(0b1010000);
      Wire.beginTransmission(0x50);
      Wire.write(0xff); //8bit address 1st half
      Wire.write(0xff); //8bit address 2nd half
      Wire.endTransmission();//wait for acknowledge
      Wire.requestFrom(0x50, 1);

      Serial.println(""); // for spacing
     
      //report the number stored 
      Serial.print(Wire.read()); Serial.println(" is the number in the register"); // read and report the number in the register
      
      //current counter value
      Serial.print(store_this_number); Serial.println(" is the value of our counter");
      break;
    case 'c':
      //increment number
      store_this_number++;
      Serial.println(""); // for spacing

      //current counter value
      Serial.print(store_this_number); 
      Serial.println(" is the value of our counter");
      break;
    default:
      break;
    }

  }
}
