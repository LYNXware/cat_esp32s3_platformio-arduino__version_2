#include "finger_module.h"

#include "events.h"


                        // u1  u2  u3  u4  u5  u6
const byte outPin_f[6] = {42, 41, 40, 39, 38, 37}; //declaring output pins for finger buttons moudule

                        // j1  j2  j3  j4    
const byte inPin_f[4] = {45, 48, 47, 21};  //declaring inputs pins for finger buttons moudule   

const byte outPin_f_count = 6;
const byte inPin_f_count = 4;


byte fo;
byte fi;
byte f_index;


                        // u1  u2  u3  u4  u5  u6     
const byte f_map[4][6] = {{ 6,  3, 10, 14, 17, 19},   // j1      // button layout for left side
                          { 5,  2,  9, 13, 16, 18},   // j2 
                          { 4,  1,  8, 12, 15, 99},   // j3 
                          {42,  0,  7, 11, 99, 99}};  // j4      // case 99 will never happen

bool f_state[4][6] = {{0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}};



void Finger_Module::initialize(){

    for(byte j=0; j<outPin_f_count; j++){    //initialize outputpins finger module
        pinMode(outPin_f[j],OUTPUT);
        digitalWrite(outPin_f[j],HIGH);  
    }
    for(byte j=0; j<inPin_f_count; j++){     //initialize inputpins finger module
        pinMode(inPin_f[j],INPUT_PULLUP);
    }
}



void Finger_Module::read_keystate() {

    for (fo=0; fo<outPin_f_count; fo++){               //looping through Outputpins and setting one at a time to LOW 
        digitalWrite(outPin_f[fo],LOW);   
                
        for (fi=0; fi<inPin_f_count; fi++){          // looping through Inputpins and checking for the LOW

            f_index = f_map[fi][fo];

            if (digitalRead(inPin_f[fi]) == LOW && f_state[fi][fo] == 0){
                
                Serial.println("-pressed");
                Serial.println(f_index); 

                event.actuate(f_index);  //function from events.h file
                f_state[fi][fo] = 1;
                
            }
            else if (digitalRead(inPin_f[fi]) == HIGH && f_state[fi][fo] == 1){
                
                event.deactuate(f_index); 
                f_state[fi][fo] = 0;
                
                Serial.println("*release");  
            }
            else {     
                //  //function from events.h file    
            }
        }      
        digitalWrite(outPin_f[fo],HIGH);              //setting the Outputpin back to HIGH 
    }
}

Finger_Module fingerModule;