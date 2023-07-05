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

        String passing_event;
        char event_component;

        byte pel;
        byte k;

        const char cat_function = 0xfa;
        const char mouse_function = 0xf0;

        void keyboard_press(String passingEvent);
        void keyboard_release(String passingEvent);

        void mouse_press(char m);
        void mouse_release(char m);    


};

extern USBHIDKeyboard Keyboard;
extern USBHIDMouse Mouse;

// extern KeyReport key_report;

extern Event event;


#endif