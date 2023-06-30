#ifndef LAYOUTS_MANAGER_H
#define LAYOUTS_MANAGER_H

#include <Arduino.h>


class Layouts_Manager {

    public:

        String incoming_raw_layouts = "empty";

        String events_array[4][46];

        float mouse_factor[4][2];

        // this functlon is checküng if the LYNXapp is sending the layouts via SerialComms
        // if yes, it will save the layouts in the preferences (espressif library)
        void get_layouts(String variant);

        // this function is loading the layouts from the preferences (espressif library)
        void load_layouts();
        
    private:

        // this function is splitting the incoming raw layouts into the events_array
        void split_raw_layouts();
        
        // this function is calculating the mouse speed factor
        void adjust_mouse_speed();

};

extern Layouts_Manager layouts_manager;

#endif