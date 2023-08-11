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

        // declaring the joystick values        
        int joystickValues[2];

        // declaring the joystick thresholds
        const int threshold_l1 = 1600;
        const int threshold_l2 = 50;
        const int threshold_h1 = 2300;
        const int threshold_h2 = 4045;
        
        // declaring the joystick events
                                     //  JF1, JF2, JB1,  JB2,  JL1,  JL2, JR1, JR2
        // byte joystick_event_map[2][4] = {{33,  34,  35,  36},  {37,  38,  39,  40}};
        byte joystick_event_map[2][4] = {{33,  34,  35,  36},  {39,  40,  37,  38}};
        // state (triggered or not)
        bool joystick_state[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

        void one_step();
        void two_step();

        void actuate_event(byte axis, byte axis_event);
        void deactuate_event(byte axis, byte axis_event);

};

// creating an instance of the Joystick class
extern Joystick joystick;

#endif



        // const byte xl1 = 33;  //JF1
        // const byte xl2 = 34;  //JF2
        // const byte xh1 = 35;  //JB1
        // const byte xh2 = 36;  //JB2

        // const byte yh1 = 37;  //JL1
        // const byte yh2 = 38;  //JL2
        // const byte yl1 = 39;  //JR1
        // const byte yl2 = 40;  //JR2    
