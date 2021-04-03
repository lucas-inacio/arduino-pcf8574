#include "PCF8574.h"

#include <Wire.h>

PCF8574::PCF8574() {
  m_Pins.value = 0xFF;
}

void PCF8574::begin() {
  Wire.begin();
}

void PCF8574::begin(byte sdaPin, byte sclPin) {
  Wire.begin(sdaPin, sclPin);
}

void PCF8574::setPinHigh(byte address, PCF8574::PinIndex pin) {
  m_Pins.value |= static_cast<byte>(pin);
  
  Wire.beginTransmission(address);
  Wire.write(m_Pins.value);
  Wire.endTransmission();
}

void PCF8574::setPinLow(byte address, PCF8574::PinIndex pin) {
  m_Pins.value &= ~static_cast<byte>(pin);
  
  Wire.beginTransmission(address);
  Wire.write(m_Pins.value);
  Wire.endTransmission();
}

void PCF8574::togglePin(byte address, PCF8574::PinIndex pin) {
  if (m_Pins.value & static_cast<byte>(pin)) {
    m_Pins.value &= ~static_cast<byte>(pin);
  } else {
    m_Pins.value |= static_cast<byte>(pin);
  }
  this->writeWord(address, m_Pins.value);
}

char PCF8574::readPin(byte address, PCF8574::PinIndex pin) {
  // First the pin must be set high
  this->setPinHigh(address, pin);
  // Then we can read from it
  if (Wire.requestFrom(address, 1, true) == 1) {
    byte reg = Wire.read();
    return (reg & static_cast<byte>(pin)) ? 1 : 0;
  } else {
    return -1;
  }
}

void PCF8574::writeWord(byte address, byte value) {
  m_Pins.value = value;
  Wire.beginTransmission(address);
  Wire.write(m_Pins.value);
  Wire.endTransmission();
}

int16_t PCF8574::readWord(byte address) {
  this->writeWord(address, 0xFF);
  if (Wire.requestFrom(address, 1, true) == 1) {
    byte reg = Wire.read();
    return reg;
  }
  return -1;
}
