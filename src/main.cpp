/*
Version: 0.2.0
Date: 01.07.2023
Developer: Stanislaw Kirpicnikow (Ape Devil)
Remark: 
*/

#include <Arduino.h>

// module to define the cat variant
#include "config.h"

// module to control the layers
#include "layer_control.h"

// module to manage the layouts
#include "layouts_manager.h"

// module to check the finger events
#include "finger_module.h"

// module to check the thumb events
#include "thumb_module.h"

// module for the execution of the events
#include "events.h"







//test button
#define pI 46
int bRead;






void setup() {

  // setting up the cat variant for the communication with the LYNXapp
  config.set_variant();

  // set the layer to major-main and initialize the LEDs
  layer_control.initialize();

  // loading the layouts
  layouts_manager.load_layouts();



  fingerModule.initialize();
  thumbModule.initialize();


  Serial.begin(115200);

  Keyboard.begin();
  Mouse.begin();



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
    
    // Serial.println(layercontro);
    
    Serial.println(config.variant);
    // Serial.println(layouts_manager.incoming_raw_layouts);
    // Serial.println(layouts_manager.events_array[0][0]);
  }

  // Serial.println("-loop");
  // delay(50);

}
