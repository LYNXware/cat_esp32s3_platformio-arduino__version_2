#include "thumb_module.h"

#include "events.h"

const byte outPin[3] = {6, 5, 4};         //declaring inputs and outputs tor thumb buttons moudule
const byte inPin[4] = {7, 15, 16, 17};    
const byte outPin_count = 3;
const byte inPin_count = 4;

byte to;
byte ti;
byte t_index;

const byte t_map[4][3] = {{29,  30,   25},      // thumb buttons layout tor left side
                          {28,  31,   26},
                          {24,  27,   20},
                          {23,  22,   21}};     // case 99 will never happen

bool t_state[4][3] = {{0, 0, 0},      // thumb buttons layout tor left side
                      {0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0}};



void Thumb_Module::initialize(){

    for(byte j=0; j<outPin_count; j++){    //initialize outputpins tinger module
        pinMode(outPin[j],OUTPUT);
        digitalWrite(outPin[j],HIGH);  
    }
    for(byte j=0; j<inPin_count; j++){     //initialize inputpins tinger module
        pinMode(inPin[j],INPUT_PULLUP);
    }
}


void Thumb_Module::read_keystate() {

    for (to=0; to<outPin_count; to++){               //looping through Outputpins and setting one at a time to LOW 
        digitalWrite(outPin[to],LOW);   
                
        for (ti=0; ti<inPin_count; ti++){          // looping through Inputpins and checking tor the LOW

            t_index = t_map[ti][to];

            if (digitalRead(inPin[ti]) == LOW && t_state[ti][to] == 0){
                
                Serial.println(t_index);     
                event.actuate(t_index);  //function from events.h File
                t_state[ti][to] = 1;
            }
            else if (digitalRead(inPin[ti]) == HIGH && t_state[ti][to] == 1){
                event.deactuate(t_index);  //function from events.h File
                t_state[ti][to] = 0;
                Serial.println("release"); 
            }
            else {
                // Event.deactuate(t_index);  //function from events.h File
                // t_state[ti][to] = 0;   
                // Serial.println("else"); 
            }
        }      
        digitalWrite(outPin[to],HIGH);              //setting the Outputpin back to HIGH 
    }
}


  
Thumb_Module thumbModule;

