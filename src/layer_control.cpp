#include "layer_control.h"



// // daclaring the led pins
// #define led_major_main 43     
// #define led_major_sub 44
// #define led_minor_main 1
// #define led_minor_sub 2

// const char major_minor = 0xfb;
// const char main_sub = 0xfc;





// initialize  the pins for leds
void Layer_Control::initialize(){

    active_layer = 0;

    pinMode(led_major_main,OUTPUT);       
    digitalWrite(led_major_main, HIGH);  
    
    pinMode(led_major_sub,OUTPUT);
    digitalWrite(led_major_sub, LOW);
    
    pinMode(led_minor_main,OUTPUT);
    digitalWrite(led_minor_main, LOW);
    
    pinMode(led_minor_sub,OUTPUT);
    digitalWrite(led_minor_sub, LOW);
}

void Layer_Control::switch_layer(char c){

    Serial.print("switch_layer---");
    // Serial.println(byte(c),HEX);
    // Serial.println(c,HEX);
    // previous_layer = active_layer;

    press_start = millis();
    Serial.println(press_start);


    if (c == major_minor){

        // Serial.println("..............major_minor");
    
        if (active_layer == 0 || active_layer == 1){

            active_layer = 2;
            switch_led(LOW,LOW,HIGH,LOW);

        }  
        else{

            active_layer = 0; 
            switch_led(HIGH,LOW,LOW,LOW);
        }  

    }
    else if(c == main_sub){

        // Serial.println("..........main_sub");
    
        if (active_layer == 0){

            active_layer = 1;
            switch_led(LOW,HIGH,LOW,LOW);

        }
        else if (active_layer == 1){

            active_layer = 0;
            switch_led(HIGH,LOW,LOW,LOW);

        } 
        else if (active_layer == 2){

            active_layer = 3;
            switch_led(LOW,LOW,LOW,HIGH);

        }   
        else{

            active_layer = 2;  
            switch_led(LOW,LOW,HIGH,LOW); 

        }     
    }
    else{
    // space for script function
    }
//      Serial.print("layer - ");
//      Serial.println(active_layer);
    delay(100);
}


void Layer_Control::switch_layer_back(char c){
    
    // press_start value is set in switch_layer function
    hold_time = millis() - press_start;

    Serial.print("switch_layer_back  hold_time---");
    Serial.println(hold_time);

    // switches back to previous layer if key is pressed for min_hold_time
    if (hold_time > min_hold_time){        
        switch_layer(c);
    }
}


void Layer_Control::switch_led(bool blue, bool red1, bool green, bool red2){
    
        digitalWrite(led_major_main,blue);
        digitalWrite(led_major_sub,red1);
        digitalWrite(led_minor_main,green);
        digitalWrite(led_minor_sub,red2);
    }





// void Layer_Control::switch_layer(char c){

//     Serial.print("switch_layer---");
//     // Serial.println(byte(c),HEX);
//     Serial.println(c,HEX);

//     if (c == major_minor){

//         Serial.println("..............major_minor");
    
//         if (active_layer == 0 || active_layer == 1){
//             active_layer = 2;
//             digitalWrite(led_major_main,LOW);
//             digitalWrite(led_major_sub,LOW);
//             digitalWrite(led_minor_main,HIGH);
//             digitalWrite(led_minor_sub,LOW);
//         }  
//         else{
//             active_layer = 0;
//             digitalWrite(led_major_main,HIGH);
//             digitalWrite(led_major_sub,LOW);
//             digitalWrite(led_minor_main,LOW);
//             digitalWrite(led_minor_sub,LOW);    
//         }  
//     }
//     else if(c == main_sub){

//         Serial.println("..........main_sub");
    
//         if (active_layer == 0){
//             active_layer = 1;
//             digitalWrite(led_major_main,LOW);
//             digitalWrite(led_major_sub,HIGH);
//             digitalWrite(led_minor_main,LOW);
//             digitalWrite(led_minor_sub,LOW);
//         }
//         else if (active_layer == 1){
//             active_layer = 0;
//             digitalWrite(led_major_main,HIGH);
//             digitalWrite(led_major_sub,LOW);
//             digitalWrite(led_minor_main,LOW);
//             digitalWrite(led_minor_sub,LOW);
//         } 
//         else if (active_layer == 2){
//             active_layer = 3;
//             digitalWrite(led_major_main,LOW);
//             digitalWrite(led_major_sub,LOW);
//             digitalWrite(led_minor_main,LOW);
//             digitalWrite(led_minor_sub,HIGH);
//         }   
//         else{
//             active_layer = 2;
//             digitalWrite(led_major_main,LOW);
//             digitalWrite(led_major_sub,LOW);
//             digitalWrite(led_minor_main,HIGH);
//             digitalWrite(led_minor_sub,LOW);    
//         }     
//     }
//     else{
//     // space for script function
//     }
// //      Serial.print("layer - ");
// //      Serial.println(active_layer);
//     delay(100);
// }



Layer_Control layer_control;
