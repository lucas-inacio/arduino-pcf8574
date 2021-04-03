#include <PCF8574.h>

// PCF8574's i2c address
// Change it to the correct one
#define I2C_ADDR 0x27

PCF8574 pcf8574;
void setup() {
  // Must be called first
  pcf8574.begin();
}

void loop() {
  // Blinks the output 0
  pcf8574.togglePin(I2C_ADDR, PCF_P0);
  delay(1000);
}
