#include <Wire.h>

void setup() {
  Wire.begin();
  
  
pinMode(4,OUTPUT);
digitalWrite(4, HIGH);
delay(1);
digitalWrite(4, LOW);
delay(10);
digitalWrite(4, HIGH);
WRITE_COMMAND(0xae);//--turn off oled panel 

WRITE_COMMAND(0xd5);//---set low column address 

WRITE_COMMAND(0x80);//---set high column address 

WRITE_COMMAND(0xa8);//--set start line address 

WRITE_COMMAND(0x3f);//--set contrast control register 

WRITE_COMMAND(0xd3); 

WRITE_COMMAND(0x0);//--set segment re-map 95 to 0 

WRITE_COMMAND(0x40 | 0x0);//--set normal display 

WRITE_COMMAND(0x8d);//--set multiplex ratio(1 to 64) 

WRITE_COMMAND(0x14);//--1/64 duty 

WRITE_COMMAND(0x20);//-set display offset 

WRITE_COMMAND(0x00);//-not offset 

WRITE_COMMAND( 0xa0 | 0x1);//--set display clock divide ratio/oscillator frequency 

WRITE_COMMAND(0xc0);//--set divide ratio 

WRITE_COMMAND(0xda);//--set pre-charge period 

WRITE_COMMAND(0x12); 

WRITE_COMMAND(0x81);//--set com pins hardware configuration 

WRITE_COMMAND(0xcf); 

WRITE_COMMAND(0xd9);//--set vcomh 

WRITE_COMMAND(0xf1); 

WRITE_COMMAND(0xdb);//--set Charge Pump enable/disable 

WRITE_COMMAND(0x40);//--set(0x14) Enable 

WRITE_COMMAND(0xa4);//--turn on oled panel 
WRITE_COMMAND(0x40);//--turn on oled panel 
WRITE_COMMAND(0xa4);//--turn on oled panel 
WRITE_COMMAND(0xa6);//--turn on oled panel 

WRITE_COMMAND(0xaf);//--turn on oled panel 

/*pinMode(4,OUTPUT);
digitalWrite(4, HIGH);
delay(1);
digitalWrite(4, LOW);
delay(10);
digitalWrite(4, HIGH);*/
}

void loop() {
WRITE_COMMAND(0xA7);
delay(1000);
WRITE_COMMAND(0xA6);
delay(1000);
}


void WRITE_COMMAND(uint8_t das_byte) {
 Wire.beginTransmission(0x3D);
 Wire.write(0x00);
 Wire.write(das_byte);
 Wire.endTransmission();
  
}
