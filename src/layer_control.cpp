#include "layer_control.h"

Layer_Control layer_control;


void Layer_Control::initialize(){
    // set the layer to 0 on startup
    active_layer = 0;
    neopixelled.layer_witch(active_layer);
}


void Layer_Control::switch_layer(char c){

    press_start = millis();

    if (c == major_minor){
    
        if (active_layer == 0 || active_layer == 1){
            active_layer = 2;
            neopixelled.layer_witch(active_layer);
        }  
        else{
            active_layer = 0; 
            neopixelled.layer_witch(active_layer);
        }  
    }
    else if(c == main_sub){
    
        if (active_layer == 0){
            active_layer = 1;
            neopixelled.layer_witch(active_layer);
        }
        else if (active_layer == 1){
            active_layer = 0;
            neopixelled.layer_witch(active_layer);
        } 
        else if (active_layer == 2){
            active_layer = 3;
            neopixelled.layer_witch(active_layer);
        }   
        else{
            active_layer = 2;  
            neopixelled.layer_witch(active_layer);
        }     
    }
    else{
    // do nothing
    }
    // delay(10);
}


void Layer_Control::switch_layer_back(char c){
    
    // press_start value is set in switch_layer function
    hold_time = millis() - press_start;

    // switches back to previous layer if key is pressed for min_hold_time
    if (hold_time > min_hold_time){        
        switch_layer(c);
    }
}


