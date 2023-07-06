#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

#include "layer_control.h"
#include "layouts_manager.h"
#include "events.h"



class Joystick {

    public:

        // initialization of the joystick pins
        void initialize();

        // reading the joystick state
        void read_joystick();

    private:

        // declaring the joystick pins
        #define pin_jx 18  
        #define pin_jy 8
        #define pin_v 3

        // variables for joystick values
        int xVal;
        int yVal;
        
        // declaring the joystick thresholds
        const int h1 = 2300;   // frirst event height
        const int l1 = 1600;   // frirst event low
        const int h2 = 4045;    //second event height
        const int l2 = 50;    //second event low

        // declaring the joystick events
        const byte xl1 = 33;  //JF1
        const byte xl2 = 34;  //JF2
        const byte xh1 = 35;  //JB1
        const byte xh2 = 36;  //JB2

        const byte yh1 = 37;  //JL1
        const byte yh2 = 38;  //JL2
        const byte yl1 = 39;  //JR1
        const byte yl2 = 40;  //JR2    

        // byte yl1 = 37;  //JL1
        // byte yl2 = 38;  //JL2
        // byte yh1 = 39;  //JR1
        // byte yh2 = 40;  //JR2  


        void one_step();
        // variables for one_step function
        int thresholds[4] = {l1, h1, l1, h1};
        byte events[4] = {xl1, xh1, yl1, yh1};
        bool eventActivated[4] = {false, false, false, false};
        const char* eventNames[4] = {"xl1", "xh1", "yl1", "yh1"};
        
        


        void two_step();
};

// creating an instance of the Joystick class
extern Joystick joystick;

#endif