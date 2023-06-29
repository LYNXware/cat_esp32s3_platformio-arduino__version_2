/*
Version: 0.2.0
Date: 01.06.2023
Developer: Stanislaw Kirpicnikow (Ape Devil)
Remark: 
*/

#include <Arduino.h>

// module to define the cat variant
#include "config.h"
Config config;

// module to manage the layouts
#include "layouts_manager.h"
Layouts_Manager layouts_manager;

// module to check the finger keys
#include "finger_module.h"
Finger_Module fingerModule;

// module to check the thumb keys
#include "thumb_module.h"
Thumb_Module thumbModule;




String t = "abcdefghijk";

//test button
#define pI 46
int bRead;



void setup() {

  // setting up the cat variant for the communication with the LYNXapp
  config.set_variant();

  // loading the layouts
  layouts_manager.load_layouts();



  fingerModule.initialize();
  thumbModule.initialize();


  Serial.begin(115200);

  //test buton
  pinMode(pI, INPUT_PULLUP);

}





void loop() {




  layouts_manager.get_layouts(config.variant);
  // layouts_manager.get_layouts(t);

  fingerModule.read_keystate();
  thumbModule.read_keystate();





  bRead = digitalRead(pI);
  if (bRead == 0) {
    Serial.println(config.variant);
    // Serial.println(layouts_manager.incoming_raw_layouts);
    // Serial.println(layouts_manager.events_array[0][0]);
  }

  // Serial.println("-loop");
  // delay(50);

}
