#ifndef SCROLL_WHEEL_H
#define SCROLL_WHEEL_H

#include <Arduino.h>

#include "events.h"


class Scroll_Wheel {

    public:
    
        void initialize();
        void read_incoder();

    private:

        // encoder pins
        #define encoder_a 35    //a2
        #define encoder_b 36    //a1
        #define encoder_GND 0   //a3
        
        // scroll wheel events in the layouts  
        #define forward_scroll 41
        #define backward_scroll 43


        byte value = 0; 
        byte previous_state;  
        byte state;
        int scroll_value = 0;
    

}; 

extern Scroll_Wheel scroll_wheel;





#endif