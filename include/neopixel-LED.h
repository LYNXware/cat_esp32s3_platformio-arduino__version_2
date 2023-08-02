#ifndef NEOPIXEL_LED_H
#define NEOPIXEL_LED_H

#include <Arduino.h>


#include <Adafruit_NeoPixel.h>

    #define LED_PIN    44
    #define LED_COUNT 1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


class NeopixelLED {

    public:

        void initialize();

        void led_test();

    private:
    
    #define power 43



    

};

// creating an instance of the NeopixelLED class
extern NeopixelLED neopixelled;

#endif