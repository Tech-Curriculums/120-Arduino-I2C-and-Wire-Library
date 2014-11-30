#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  uint16_t reading;
  Wire.beginTransmission(0x5A); // address shifted left by 1
  Wire.write(0x07); // object temperature
  //prevent another master device from transmitting between messages
  Wire.endTransmission(false); //send a restart message after transmission

  //Get the temperature in (scaled) kelvin
  Wire.requestFrom(0x5A, 0x3); // request 3 bytes
  reading = Wire.read();
  reading |= Wire.read() << 8; // shift to the left by 8 and bitwise OR
  
  //Get the third byte, we toss it (temp in first two bytes)
  uint8_t extra = Wire.read(); // toss the third byte

  double celsius = ((double) reading)*0.02 - 273.15;

  Serial.println(celsius); 
  delay(250);
}
