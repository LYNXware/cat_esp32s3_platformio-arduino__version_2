#include "layer_control.h"



// daclaring the led pins
#define led_major_main 43     
#define led_major_sub 44
#define led_minor_main 1
#define led_minor_sub 2

const char major_minor = 0xfb;
const char main_sub = 0xfc;

byte active_layer = 0;


// initialize  the pins for leds
void Layer_Control::initialize(){

    pinMode(led_major_main,OUTPUT);       
    digitalWrite(led_major_main,HIGH);  
    
    pinMode(led_major_sub,OUTPUT);
    digitalWrite(led_major_sub,LOW);
    
    pinMode(led_minor_main,OUTPUT);
    digitalWrite(led_minor_main,LOW);
    
    pinMode(led_minor_sub,OUTPUT);
    digitalWrite(led_minor_sub,LOW);
}


void Layer_Control::switch_layer(char c){

    if (c == major_minor){
    
        if (active_layer == 0 || active_layer == 1){
            active_layer = 2;
            digitalWrite(led_major_main,LOW);
            digitalWrite(led_major_sub,LOW);
            digitalWrite(led_minor_main,HIGH);
            digitalWrite(led_minor_sub,LOW);
        }  
        else{
            active_layer = 0;
            digitalWrite(led_major_main,HIGH);
            digitalWrite(led_major_sub,LOW);
            digitalWrite(led_minor_main,LOW);
            digitalWrite(led_minor_sub,LOW);    
        }  
    }
    else if(c == main_sub){
    
        if (active_layer == 0){
            active_layer = 1;
            digitalWrite(led_major_main,LOW);
            digitalWrite(led_major_sub,HIGH);
            digitalWrite(led_minor_main,LOW);
            digitalWrite(led_minor_sub,LOW);
        }
        else if (active_layer == 1){
            active_layer = 0;
            digitalWrite(led_major_main,HIGH);
            digitalWrite(led_major_sub,LOW);
            digitalWrite(led_minor_main,LOW);
            digitalWrite(led_minor_sub,LOW);
        } 
        else if (active_layer == 2){
            active_layer = 3;
            digitalWrite(led_major_main,LOW);
            digitalWrite(led_major_sub,LOW);
            digitalWrite(led_minor_main,LOW);
            digitalWrite(led_minor_sub,HIGH);
        }   
        else{
            active_layer = 2;
            digitalWrite(led_major_main,LOW);
            digitalWrite(led_major_sub,LOW);
            digitalWrite(led_minor_main,HIGH);
            digitalWrite(led_minor_sub,LOW);    
        }     
    }
    else{
    // space for script function
    }
//      Serial.print("layer - ");
//      Serial.println(active_layer);
    delay(100);
}



Layer_Control layer_control;
