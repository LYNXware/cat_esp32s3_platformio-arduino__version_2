#ifndef LAYOUTS_MANAGER_H
#define LAYOUTS_MANAGER_H

#include <Arduino.h>




class Layouts_Manager {

    public:


        String incoming_bytes = "empty";
        String events_array[4][46];

        float mouse_factor[4][2];

        // this functlon is checküng if the LYNXapp is sending the layouts via SerialComms
        void get_layouts();
        
        void split(String in_bytes);
        
        void mouse_speed();

    private:
    
        

};




#endif