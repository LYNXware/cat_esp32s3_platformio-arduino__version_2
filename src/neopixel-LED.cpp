#include "neopixel-LED.h"


void NeopixelLED::initialize(){

    pinMode(power,OUTPUT);    
    digitalWrite(power,HIGH);

    // pinMode(gnd,OUTPUT);    
    // digitalWrite(gnd,LOW);

    strip.begin();
    strip.show(); // Initialize the pixel to 'off'


}

void NeopixelLED::led_test(){

                    //led /R /G /B
    strip.setPixelColor(0, 0, 0, 50); // Set the color of the pixel to red
    strip.show();
    delay(500);

    strip.setPixelColor(0, 0, 0, 0); // Turn off the pixel
    strip.show();
    delay(500);

}

// creating an instance of the NeopixelLED class
NeopixelLED neopixelled;