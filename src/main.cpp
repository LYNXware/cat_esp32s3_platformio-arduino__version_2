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


// module to control the scroll wheel
#include "scroll-wheel.h"

// module to control the mouse sensor
#include "mouse-sensor.h"

// module to control the joystick
#include "joystick.h"

// module for the execution of the events
#include "events.h"





// dev 001

// premain  001


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


  // initialize the modules
  fingerModule.initialize();
  thumbModule.initialize();
  scroll_wheel.initialize();
  joystick.initialize();

  
#if additional_modules == 1  
  adns5050.initialize();
#endif

  Serial.begin(115200);

  Keyboard.begin();
  Mouse.begin();



  //test buton
  pinMode(pI, INPUT_PULLUP);

}





void loop() {


  // checking if the LYNXapp is connected and sends new layouts
  layouts_manager.get_layouts(config.variant);
  
  // checking if any events are triggered
  fingerModule.read_keystate();
  thumbModule.read_keystate();
  scroll_wheel.read_encoder();
  joystick.read_joystick();

  
  // included only if in config.h the additional_modules is set to 1
#if additional_modules == 1  
  // checking if the mouse sensor is triggered
  adns5050.read_mouse_sensor();
#endif




  //test buton
  bRead = digitalRead(pI);
  if (bRead == 0) {
    
    // Serial.println(layercontro);
    
    Serial.println(config.variant);
    // Serial.println(layouts_manager.incoming_raw_layouts);
    // Serial.println(layouts_manager.events_array[0][0]);
  }

}//end loop
