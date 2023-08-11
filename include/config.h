#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>


/* CONFIG - here you can define your cat variant */

#define side                0   // 0-(left) || 1-(right)
#define thumb_module        1   // 0-(buttons) || 1-(joystick+buttons) || 2-(trackball) 
#define finger_module       0   // 0-(buttons) || 1-(buttons+wheel) 
#define additional_modules  0   // 0-(none) || 1-(mouse moudule)
// #define cat_version





class Config {

    public:

        //the variant variable is used to communicate with the LYNXapp
        String variant = "C0-000-000-000";

        // the setup function is used to set the variant variable
        void set_variant();
};


extern Config config;

#endif