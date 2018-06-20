# Optical-Dust-Sensor-Library

<p align="center"><img src="/readme/sharp.jpg" width="400px"/></p>

<p align="center"><img src="/readme/sharptopdown.png" width="400px"/></p>

Optical Dust Sensor (Sharp GP2Y10) library for Arduino framework. Tested on PlatformIO, ArduinoIDE.
#### Examples: https://github.com/lnquy065/Optical-Dust-Sensor-Library/blob/master/example/

## Schematic

<p align="center"><img src="/readme/schematic.jpg" width="500px"/></p>

### Components
+ Arduino Nano
+ Sharp GP2Y10 Dust Sensor
+ 150Ω Resistor
+ 220uF Capacitor

## SharpGP2Y10 Library
### Using
+ Include SharpGP2Y10 library
```
#include "SharpGP2Y10.h"
```
+ Create SharpGP2Y10 Object with parameters
```
int voPin = A0;
int ledPin = 2;
SharpGP2Y10 dustSensor(voPin, ledPin);
```
+ Get and print dust density
```
float dustVal = dustSensor.getDustDensity();
Serial.println(dustVal);
```

### Constructors
+ SharpGP2Y10(int voPin, int ledPin)
  - voPin: Vo (5)
  - ledPin: LED (3)
  - Notice: default vcc is 5.0v

+ SharpGP2Y10(int voPin, int ledPin, float vcc)
  - voPin: Vo (5)
  - ledPin: LED (3)
  - vcc: Voltage reference (5.0, 3.3, ...)

### Methods
#### Get fields value only
+ float getDustDensityField()
+ float getVotageField()
+ int getADCField()

#### Read new value from sensor before return
+ float getDustDensity()
+ float getVotage()
+ int getADC()

