# arduino-pcf8574

Simple wrapper for the PCF8574 I/O expansion chip.

### Description
The PCF8574 chip operates with the i2c standard and needs proper manipulation to get things right. This library implements a simple interface to use it in your projects.

### Interface
Currently the code defines the following constants and functions:
```C++
PCF_P0...PCF_P7 // These are constants that map to the chip pins

// Initialization
PCF8574();
void begin(); // Default I2C pins
void begin(byte sdaPin, byte  sclPin);

// Write operations
void  setPinHigh(byte  address, PinIndex  pin);
void  setPinLow(byte  address, PinIndex  pin);
void  togglePin(byte  address, PinIndex  pin);
void  writeWord(byte  address, byte  value);

// Read operations
char  readPin(byte  address, PinIndex  pin);
int16_t  readWord(byte  address);
```

### Usage
It's necessary to instantiate an object and then call begin passing two pins (SDA and SCL) as arguments.

All read/write operations take an address as first argument which is the chip's i2c address (defined in the PCF8574 datasheet). Common values are 0x27, 0x38.
