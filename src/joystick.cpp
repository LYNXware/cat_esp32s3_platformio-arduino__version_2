#include "joystick.h"

// creating an instance of the Joystick class
Joystick joystick;



void Joystick::initialize(){

    // pin to read the joystick values
    pinMode(pin_jx, INPUT_PULLUP);     
    pinMode(pin_jy, INPUT_PULLUP);  
    
    // power supply for the joystick
    pinMode(pin_v,OUTPUT);
    digitalWrite(pin_v,HIGH); 
} 

  
void Joystick::read_joystick(){

    //read the analog joystick values
    xVal = analogRead(pin_jx);       
    yVal = analogRead(pin_jy);


    if (layouts_manager.events_array[layer_control.active_layer][32][0] == '0'){
        one_step();
    }
    else{
        two_step();
    }
}


void Joystick::one_step() {

  // xVal = analogRead(pin_jx);       
  // yVal = analogRead(pin_jy);

  int axisValues[4] = {xVal, xVal, yVal, yVal};

  for (int i = 0; i < 4; i++) {

    if ((i % 2 == 0 && axisValues[i] < thresholds[i]) 
    || (i % 2 == 1 && axisValues[i] > thresholds[i])) {

      if (!eventActivated[i]) {
        eventActivated[i] = true;
        event.actuate(events[i]);
        Serial.println(eventNames[i]);
      }
    } 
    else{
      if (eventActivated[i]) {        
        eventActivated[i] = false;
        event.deactuate(events[i]);
        Serial.println("released");
      }
    }
  }
}









void Joystick::two_step() {
//   int axisValues[] = {xVal, yVal};
//   int lowThresholds[] = {l1, l2};
//   int highThresholds[] = {h1, h2};
//   int eventsLow[] = {xl1, xl2, yl1, yl2};
//   int eventsHigh[] = {xh1, xh2, yh1, yh2};
//   const char* eventNames[] = {"xl1", "xl2", "xh1", "xh2", "yl1", "yl2", "yh1", "yh2"};
//   bool eventActivated[] = {false, false, false, false, false, false, false, false};

//   for (int i = 0; i < 4; i++) {
//     if (axisValues[i / 2] < lowThresholds[i]) {
//       if (!eventActivated[i]) {
//         event.actuate(eventsLow[i]);
//         Serial.println(eventNames[i]);
//         eventActivated[i] = true;
//       }
//     } else {
//       event.deactuate(eventsLow[i]);
//       eventActivated[i] = false;
//     }

//     if (axisValues[i / 2] > highThresholds[i]) {
//       if (!eventActivated[i + 4]) {
//         event.actuate(eventsHigh[i]);
//         Serial.println(eventNames[i + 4]);
//         eventActivated[i + 4] = true;
//       }
//     } else {
//       event.deactuate(eventsHigh[i]);
//       eventActivated[i + 4] = false;
//     }
//   }
}


// void Joystick::two_step() {

//   int axisValues[] = {xVal, yVal};
//   int lowThresholds[] = {l1, l2};
//   int highThresholds[] = {h1, h2};
//   int eventsLow[] = {xl1, xl2, yl1, yl2};
//   int eventsHigh[] = {xh1, xh2, yh1, yh2};
//   const char* eventNames[] = {"xl1", "xl2", "xh1", "xh2", "yl1", "yl2", "yh1", "yh2"};
  
//   for (int i = 0; i < 4; i++) {
//     if (axisValues[i/2] < lowThresholds[i]) {
//       event.actuate(eventsLow[i]);
//       Serial.println(eventNames[i]);
//     } else {
//       event.deactuate(eventsLow[i]);
//     }
    
//     if (axisValues[i/2] > highThresholds[i]) {
//       event.actuate(eventsHigh[i]);
//       Serial.println(eventNames[i + 4]);
//     } else {
//       event.deactuate(eventsHigh[i]);
//     }
//   }
// }


//  void Joystick::one_step(){
  
//       if (xVal < l1){  // x low value events
//         event.actuate(xl1);
//           Serial.println("xl1");
//       }
//       else{
//         event.deactuate(xl1);
//       }
      
//       if (xVal > h1){   // x heigh value events
//         event.actuate(xh1);
//           Serial.println("xh1");
//       }
//       else{
//         event.deactuate(xh1);
//       }
    
//       if (yVal < l1){   // y low value events
//         event.actuate(yl1);
//           Serial.println("yl1");
//       }
//       else{
//         event.deactuate(yl1);
//       }
      
//       if (yVal > h1){   // y heigh value events
//         event.actuate(yh1);
//           Serial.println("yh1");
//       }
//       else{
//         event.deactuate(yh1);
//       }
//     }



  
// void Joystick::two_step(){
  
//     if (xVal < l1 && xVal > l2){  // x low value events
//     event.actuate(xl1);
//         Serial.println("xl1");
//     }
//     else{
//     event.deactuate(xl1);
//     }
    
//     if (xVal < l2){
//     event.actuate(xl2);  
//         Serial.println("xl2");
//     }
//     else{
//     event.deactuate(xl2);
//     }
    
//     if (xVal > h1 && xVal < h2){   // x heigh value events
//     event.actuate(xh1);
//         Serial.println("xh1");
//     }
//     else{
//     event.deactuate(xh1);
//     }
    
//     if (xVal > h2){
//     event.actuate(xh2);
//         Serial.println("xh2");
//     }
//     else{
//     event.deactuate(xh2);
//     }


//     if (yVal < l1 && yVal > l2){   // y low value events
//     event.actuate(yl1);
//         Serial.println("yl1");
//     }
//     else{
//     event.deactuate(yl1);
//     }
    
//     if (yVal < l2){
//     event.actuate(yl2);   
//         Serial.println("yl2");
//     }
//     else{
//     event.deactuate(yl2);
//     }  
    
//     if (yVal > h1 && yVal < h2){   // y heigh value events
//     event.actuate(yh1);
//         Serial.println("yh1");
//     }
//     else{
//     event.deactuate(yh1);
//     }
    
//     if (yVal > h2){
//     event.actuate(yh2);
//         Serial.println("yh2");
//     }
//     else{
//     event.deactuate(yh2);
//     }
// }




