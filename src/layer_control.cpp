#include "layer_control.h"



// initialize  the pins for leds
void Layer_Control::initialize(){

    active_layer = 0;
    neopixelled.layer_witch(active_layer);

    // pinMode(led_major_main,OUTPUT);       
    // digitalWrite(led_major_main, HIGH);  
    
    // pinMode(led_major_sub,OUTPUT);
    // digitalWrite(led_major_sub, LOW);
    
    // pinMode(led_minor_main,OUTPUT);
    // digitalWrite(led_minor_main, LOW);
    
    // pinMode(led_minor_sub,OUTPUT);
    // digitalWrite(led_minor_sub, LOW);
}


void Layer_Control::switch_layer(char c){

    press_start = millis();

    if (c == major_minor){
    
        if (active_layer == 0 || active_layer == 1){
            active_layer = 2;
            // switch_led(LOW,LOW,HIGH,LOW);
            neopixelled.layer_witch(active_layer);
        }  
        else{
            active_layer = 0; 
            // switch_led(HIGH,LOW,LOW,LOW);
            neopixelled.layer_witch(active_layer);
        }  
    }
    else if(c == main_sub){
    
        if (active_layer == 0){

            active_layer = 1;
            // switch_led(LOW,HIGH,LOW,LOW);
            neopixelled.layer_witch(active_layer);
        }
        else if (active_layer == 1){

            active_layer = 0;
            // switch_led(HIGH,LOW,LOW,LOW);
            neopixelled.layer_witch(active_layer);
        } 
        else if (active_layer == 2){

            active_layer = 3;
            // switch_led(LOW,LOW,LOW,HIGH);
            neopixelled.layer_witch(active_layer);
        }   
        else{

            active_layer = 2;  
            // switch_led(LOW,LOW,HIGH,LOW); 
            neopixelled.layer_witch(active_layer);
        }     
    }
    else{
    // do nothing
    }
    delay(100);
}


void Layer_Control::switch_layer_back(char c){
    
    // press_start value is set in switch_layer function
    hold_time = millis() - press_start;

    // switches back to previous layer if key is pressed for min_hold_time
    if (hold_time > min_hold_time){        
        switch_layer(c);
    }
}


// void Layer_Control::switch_led(bool blue, bool red1, bool green, bool red2){
    
//         digitalWrite(led_major_main,blue);
//         digitalWrite(led_major_sub,red1);
//         digitalWrite(led_minor_main,green);
//         digitalWrite(led_minor_sub,red2);
//     }



Layer_Control layer_control;
