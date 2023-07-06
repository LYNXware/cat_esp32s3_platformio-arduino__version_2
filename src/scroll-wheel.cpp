#include "scroll-wheel.h"



    
void Scroll_Wheel::initialize(){

    pinMode(encoder_GND,OUTPUT);
    digitalWrite(encoder_GND,LOW);

    pinMode (encoder_a,INPUT_PULLUP);
    pinMode (encoder_b,INPUT_PULLUP);
    
    previous_state = digitalRead(encoder_a);   
} 



void Scroll_Wheel::read_encoder(){

    state = digitalRead(encoder_a);
        
    if (state != previous_state){              // we use the encoder_b pin to find out which way we turning.
        
        if (digitalRead(encoder_b) != state) {   // Clockwise
        value ++;
        scroll_value = 1;
        //LeftRight = true;
        event.actuate(forward_scroll);
        event.deactuate(forward_scroll);
        } 
        else {                                 //Counterclockwise
        // LeftRight = false;
        value--;
        scroll_value = -1;
        event.actuate(backward_scroll);
        event.deactuate(backward_scroll);           
        }

        Serial.println(value);
        Serial.println(scroll_value);
        
//         Mouse.move(0, 0, scroll_value);
    
    } 
    previous_state = state;
} 

Scroll_Wheel scroll_wheel;