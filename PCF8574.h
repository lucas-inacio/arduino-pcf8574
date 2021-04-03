#ifndef PCF8574_H
#define PCF8574_H

#include <Arduino.h>

#define PCF_P0 PCF8574::PinIndex::PCF8574_PIN0
#define PCF_P1 PCF8574::PinIndex::PCF8574_PIN1
#define PCF_P2 PCF8574::PinIndex::PCF8574_PIN2
#define PCF_P3 PCF8574::PinIndex::PCF8574_PIN3
#define PCF_P4 PCF8574::PinIndex::PCF8574_PIN4
#define PCF_P5 PCF8574::PinIndex::PCF8574_PIN5
#define PCF_P6 PCF8574::PinIndex::PCF8574_PIN6
#define PCF_P7 PCF8574::PinIndex::PCF8574_PIN7

class PCF8574
{
  public:
    enum class PinIndex : byte {
        PCF8574_PIN0 = 1,
        PCF8574_PIN1 = (1 << 1),
        PCF8574_PIN2 = (1 << 2),
        PCF8574_PIN3 = (1 << 3),
        PCF8574_PIN4 = (1 << 4),
        PCF8574_PIN5 = (1 << 5),
        PCF8574_PIN6 = (1 << 6),
        PCF8574_PIN7 = (1 << 7)
    };

    union Pins {
      struct Bits {
        byte p0: 1;
        byte p1: 1;
        byte p2: 1;
        byte p3: 1;
        byte p4: 1;
        byte p5: 1;
        byte p6: 1;
        byte p7: 1;
      } bits;
      byte value;
    };
    
    PCF8574();

    // Initialize the library. Must be called first
    void begin();
    void begin(byte sdaPin, byte sclPin);

    void setPinHigh(byte address, PinIndex pin);
    void setPinLow(byte address, PinIndex pin);
    void togglePin(byte address, PinIndex pin);
    
    // Read the state of a port. Returns -1 if nothing was read
    char readPin(byte address, PinIndex pin);

    // Set the state of all pins
    void writeWord(byte address, byte value);

    // Read all ports. Returns -1 if nothing was read
    int16_t readWord(byte address);

  private:
    Pins m_Pins;
};

#endif // PCF8574_H
