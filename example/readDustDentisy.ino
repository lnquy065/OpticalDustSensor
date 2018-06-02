
#include "SharpGP2Y10.h"

//DUST Sensor
int voPin = A0;
int ledPin = 2;

SharpGP2Y10 dustSensor(voPin, ledPin);


void setup() {
    Serial.begin(9600);

}

void loop() {
    float dustVal = dustSensor.getDustDensity();
    Serial.println(dustVal);
    delay(1000);
}
