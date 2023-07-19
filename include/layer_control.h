#ifndef LAYER_CONTROL_H
#define LAYER_CONTROL_H

#include <Arduino.h>


class Layer_Control {

    public:

        byte active_layer;

        // initialize  the pins for leds and set the layer to major-main
        void initialize();

        // function to switch the layers
        void switch_layer(char c);

        void switch_layer_back(char c);


    private:

        // daclaring the led pins
        #define led_major_main 43     
        #define led_major_sub 44
        #define led_minor_main 1
        #define led_minor_sub 2

        // declaring the layer change codes
        const char major_minor = 0xfb;
        const char main_sub = 0xfc;

        // variables for switch_layer_back function
        // byte previous_layer;
        unsigned long press_start;
        unsigned long hold_time;

        // the layer will be switch back if the key is pressed longer than min_hold_time
        const int min_hold_time = 500;

        //switch the leds on or off
        void switch_led(bool blue, bool red1, bool green, bool red2);


        // to do: transmit the layer change to othe devices via BLE
        // void transmit_layer_change();

};

extern Layer_Control layer_control;

#endif