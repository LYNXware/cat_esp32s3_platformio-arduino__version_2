#include "neopixel-LED.h"

Adafruit_NeoPixel strip_layer_switch(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void NeopixelLED::initialize(){

    pinMode(LED_power,OUTPUT);    
    digitalWrite(LED_power,HIGH);

    strip_layer_switch.begin();
    strip_layer_switch.show(); // Initialize the pixel to 'off'

}



void NeopixelLED::layer_witch(byte active_layer){

    switch (active_layer){

        case 0:
            strip_layer_switch.setPixelColor(0, 0, 0, 50); //blue
            strip_layer_switch.show();
            break;
            
        case 1:
            strip_layer_switch.setPixelColor(0, 50, 0, 0); // red
            strip_layer_switch.show();
            break;

        case 2:
            strip_layer_switch.setPixelColor(0, 0, 50, 0); //green
            strip_layer_switch.show();
            break;
            
        case 3:
            strip_layer_switch.setPixelColor(0, 20, 30, 0); //yealow
            strip_layer_switch.show();
            break;            
    }
}





void NeopixelLED::led_test(){

                    //led /R /G /B
    strip_layer_switch.setPixelColor(0, 0, 80, 0); // Set the color of the pixel to red
    strip_layer_switch.show();
    delay(500);

    strip_layer_switch.setPixelColor(0, 0, 0, 0); // Turn off the pixel
    strip_layer_switch.show();
    delay(500);
}





// creating an instance of the NeopixelLED class
NeopixelLED neopixelled;