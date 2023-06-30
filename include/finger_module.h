#ifndef FINGER_MODULE_H
#define FINGER_MODULE_H

#include <Arduino.h>


class Finger_Module {

    public:

        void initialize();

        void read_keystate();
};


extern Finger_Module fingerModule;

#endif