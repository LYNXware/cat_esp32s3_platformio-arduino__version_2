#ifndef LAYER_CONTROL_H
#define LAYER_CONTROL_H

#include <Arduino.h>


class Layer_Control {

    public:

        byte active_layer;

        void initialize();
        void switch_layer(char c);

    private:

};

extern Layer_Control layer_control;

#endif