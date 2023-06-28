/*
Version: 0.2.0
Date: 01.06.2023
Developer: Stanislaw Kirpicnikow (Ape Devil)
Remark: 
*/



// test


#include <Arduino.h>

#include "test.h"


#include "config.h"


#include "layouts_manager.h"
Layouts_Manager layouts_manager;





//test button
#define pI 46
int bRead;





void setup() {

  // setting up the cat variant for the communication with the LYNXapp
  config.set_variant();




  //test buton
  pinMode(pI, INPUT_PULLUP);

  Serial.begin(115200);

}





void loop() {


  Serial.println("loop");
  delay(50);



  bRead = digitalRead(pI);
  if (bRead == 0) {

    // Serial.println("b");
    // Serial.println(test);
    // testFun();

    Serial.println(config.variant);
    
    layouts_manager.get_layouts();

  }
}





// // put function declarations here:
// int myFunction(int, int);

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }