#include <Wire.h>

void setup(){
  Serial.begin(9600);  
  Serial.println("Serial Connection Established");
  pinMode(4,OUTPUT);
}

//0x23 is the bh1750's I2C Address as I'm running it in address low mode 
//i.e. I am connecting "ADD" to "GND"
void loop() {
  Wire.beginTransmission(0x23);
  Wire.write(0x01); //power on
  Wire.endTransmission();
  
  Wire.beginTransmission(0x23);
  Wire.write(0x20); //one time sense
  Wire.endTransmission();
  delay(500);
  
  Wire.beginTransmission(0x23);
  Wire.requestFrom(0x23,2); //requesting 2 bytes from the lux sensor
  
  
    //read them in one byte at a time
    

     uint16_t lux = Wire.read();
       
    //MSB was first so we'll need to shift byte to the left 
     lux = lux << 8; //

     // "or"-ing with the next byte, we will be able to  
     lux |= Wire.read();

 
   Wire.endTransmission();

  if ( lux < 100 ) 
    digitalWrite(4,HIGH);
  else 
    digitalWrite(4, LOW);

     Serial.println(lux);
     
}
