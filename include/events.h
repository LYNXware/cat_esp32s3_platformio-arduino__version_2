#ifndef EVENTS_H
#define EVENTS_H

#include <Arduino.h>

// // #include "USB.h"
#include "USBHIDKeyboard.h"
// USBHIDKeyboard Keyboard;
#include "USBHIDMouse.h"
// USBHIDMouse Mouse;



class Event {

    public:
        void actuate(byte event);
        void deactuate(byte event);

    private:
        void mouse_press(char m);
        void mouse_release(char m);    


};

extern USBHIDKeyboard Keyboard;
extern USBHIDMouse Mouse;

extern Event event;


#endif