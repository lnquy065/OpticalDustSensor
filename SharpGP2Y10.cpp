/**************************************************************************/
/*!
@file     SharpGP2Y10.h
@author   lnquy065
@license  GNU GPLv3
@version  1.0
First version of an Arduino Library for the SharpGP2Y10 dust sensor
*/
/**************************************************************************/
#include <Arduino.h>
#include "SharpGP2Y10.h"

SharpGP2Y10::SharpGP2Y10(int voPin, int ledPin) {
    pinMode(ledPin, OUTPUT);
    this->voPin = voPin;
    this->ledPin = ledPin;
}

SharpGP2Y10::SharpGP2Y10(int voPin, int ledPin, float vccVol) {
    pinMode(ledPin, OUTPUT);
    this->voPin = voPin;
    this->ledPin = ledPin;
    this->vccVol = vccVol;
}

void SharpGP2Y10::calc() {
    digitalWrite(ledPin, LOW); //turn on LED
    delayMicroseconds(SharpGP2Y10_SAMPLINGTIME);     //Sampling time
    volMeasured = analogRead(voPin);    //read ADC VoPin

    delayMicroseconds(SharpGP2Y10_DELTATIME);   
    digitalWrite(ledPin, HIGH); //turn off LED
    delayMicroseconds(SharpGP2Y10_SLEEPINGTIME);

    calcVoltage = volMeasured * (vccVol / 1024);   //calc real Voltage

    // Linear equation taken from http://www.howmuchsnow.com/arduino/airquality/
    // Chris Nafis (c) 2012
    dustDensity = 0.17 * calcVoltage - 0.1; 

    

    if (dustDensity < 0)
    {
        dustDensity = 0.00;
    }
}

// recalculator
float SharpGP2Y10::getDustDensity()
{
    calc();
    return dustDensity;
}

float SharpGP2Y10::getVotage()
{
    calc();
    return calcVoltage;
}

int SharpGP2Y10::getADC()
{
    calc();
    return volMeasured;
}



//Get fields value only
float SharpGP2Y10::getDustDensityField()
{
    return dustDensity;
}

float SharpGP2Y10::getVotageField()
{
    return calcVoltage;
}

int SharpGP2Y10::getADCField()
{
    return volMeasured;
}
