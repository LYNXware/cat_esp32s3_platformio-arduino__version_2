#ifndef THUMB_MODULE_H
#define THUMB_MODULE_H

#include <Arduino.h>


class Thumb_Module {

    public:

        void initialize();

        void read_keystate();
};


extern Thumb_Module thumbModule;

#endif