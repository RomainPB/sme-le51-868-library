/*
    SmeIoT Library - ConfigurationMode

    Demostrate how move in configuration mode for the Telit Sigfox component.

    created 27 Apr 2015
    by Mik (smkk@amel-tech.com)

    This example is in the public domain

    http://www.amel-tech.com/smarteverything/tutorial/IoT/SigFox
 */ 
#include <Wire.h>
#include <SmeSFX.h>
#include <Arduino.h>


bool inConfiguration;
// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin 13 as an output.
    pinMode(PIN_LED_GREEN, OUTPUT);
    digitalWrite(PIN_LED_GREEN, HIGH);
    inConfiguration = false;

    SerialUSB.begin(115200);
    
    sfxAntenna.begin();
    sfxAntenna.setSfxConfigurationMode(); // enter in configuration Mode
}

// the loop function runs over and over again forever
void loop() {

    digitalWrite(PIN_LED_GREEN, HIGH);
    delay(1000);

    if (!inConfiguration) {
        uint8_t answerReady = sfxAntenna.hasSfxAnswer();
        if (answerReady){
            SerialUSB.println("Enterd in configuration Mode");
            inConfiguration = true;
        }
    } else {
        digitalWrite(PIN_LED_GREEN, LOW);
        delay(2000);              // wait for a second

    }    
}