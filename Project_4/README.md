# Adding a Screen

I2C isn't usually fast enough for color screens, but there are screens like the SSD1306 (see Adafruit) which 
have the option of being interfaced via I2C.

The advantages of course being:
* simplicity of wiring 
  * need only to extend I2C bus, as opposed to an additional 6 wires for spi
* Code simplicity 
  * need only to create/test I2C bus helper-functions and macros 
* firmware size
  * Space is always scarce with firmware, and having fewer interfaces leaves firmware-space other features.
