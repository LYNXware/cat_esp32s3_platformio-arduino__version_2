#include "layouts_manager.h"

#include "config.h"

#include <Preferences.h>
Preferences preferences;


// String test = "test";



String found_you = "found_you";

int inBL;
int b;
int f;

byte layer;
byte event_index;

const char delimiter = 0xff;
const char delimiter_layout = 0xfe;
const char last_byte = 0xfd;

int m;



void Layouts_Manager::get_layouts() {


    if (Serial.available() > 0){

        incoming_bytes = Serial.readString();

        if (found_you == incoming_bytes){
            Serial.println(config.variant);
        }
        else{
            // split(incoming_bytes);

            preferences.begin("myPrefs", false);
            preferences.clear();
            preferences.putString("layout", incoming_bytes);
            preferences.end();
        }
    }
}  




// void Layouts_Manager::split(String in_bytes){
    
//     inBL = in_bytes.length();
//     b = 0;
//     f = 0;
//     event_index = 0;
//     layer = 0;

//     for(b; b < inBL; b++) {
    
//         if (in_bytes[b] == delimiter_layout){
//             layer++;
//             event_index = 0;
//             f++;
//         }
//         if (in_bytes[b] == delimiter){
//             events_array[layer][event_index] = in_bytes.substring(f,b);
//             f = b+1;
//             event_index++;    
//         }   
//     }
//     mouse_speed();      
// }



// void Layouts_Manager::mouse_speed(){
//     m = 0;
//     for (m; m < 4; m++){
//     mouse_factor[m][0] = pow((float(events_array[m][44][0])/100), 2);  // horizontal mouse factor
//     mouse_factor[m][1] = pow((float(events_array[m][45][0])/100), 2);  // vertical mouse factor
//     }
// }