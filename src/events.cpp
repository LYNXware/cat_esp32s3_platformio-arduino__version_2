#include "events.h"

#include "layouts_manager.h"
#include "layer_control.h"


// from the USBHIDKeyboard library
KeyReport key_report;



void Event::actuate(byte event){
    
    passing_event = layouts_manager.events_array[layer_control.active_layer][event];
   
    if (passing_event[0] == mouse_function){
        mouse_press(passing_event[1]);
    }
    else if (passing_event[0] == cat_function){
        layer_control.switch_layer(passing_event[1]);
    }      
    else{
        keyboard_press(passing_event);
    }  
}



void Event::deactuate(byte event){

    passing_event = layouts_manager.events_array[layer_control.active_layer][event];
    
    if (passing_event[0] == mouse_function){
        mouse_release(passing_event[1]);
    }
    else if (passing_event[0] == cat_function){
        layer_control.switch_layer_back(passing_event[1]);
    }    
    else{
        keyboard_release(passing_event);
    } 
}



void Event::keyboard_press(String passingEvent){

    pel = passing_event.length();

    for(k=0; k < pel; k++){ 

        switch (passing_event[k]){

            case 0x81:

                Serial.println("0x81");

                key_report.modifiers |= 2;
                Keyboard.sendReport(&key_report);
                break;
            
            default:

                event_component = passing_event[k];
                Keyboard.press(event_component);

                Serial.println("---actuate"); 
                Serial.println(event_component); 
                Serial.println(int(event_component), HEX);

                break;
            }
    }
}



void Event::keyboard_release(String passingEvent){

    pel = passing_event.length();

    for(k=0; k < pel; k++){ 

        switch (passing_event[k]){

            case 0x81:

                Serial.println("**0x81");

                key_report.modifiers = 0;
                Keyboard.sendReport(&key_report);
                break;
            
            default:

                event_component = passing_event[k];
                Keyboard.release(event_component);

                Serial.println("***deactuate"); 
                Serial.println(event_component);

                break;
        }
    }
}


// void Event::keyboard_press(String passingEvent){

//     pel = passing_event.length();

//     for(k=0; k < pel; k++){ 

//         event_component = passing_event[k];
//         Keyboard.press(event_component);

//         Serial.println("---actuate"); 
//         Serial.println(event_component); 
//         Serial.println(int(event_component));
//     }
// }


// void Event::keyboard_release(String passingEvent){

//     pel = passing_event.length();

//     for(k=0; k < pel; k++){ 
//         event_component = passing_event[k];
//         Keyboard.release(event_component);

//         Serial.println("***deactuate"); 
//         Serial.println(event_component);
//     }
    
// }




void Event::mouse_press(char m){

    Serial.println("mouse press");
    Serial.println(m);


    switch (m) {
               
        case 0xf1:
            Serial.println("left_click");
            Mouse.press(MOUSE_LEFT);
        break;
        
        case 0xf2:
            Serial.println("middle_click");
            Mouse.press(MOUSE_MIDDLE);
        break;
        
        case 0xf3:
            Serial.println("right_click");
            Mouse.press(MOUSE_RIGHT);
        break;   
        
        case 0xf4:
            Serial.println("mouse_move 1");
            Mouse.move(0, 0, 1);
        break;
        
        case 0xf5:
            Serial.println("mouse_move -1");
            Mouse.move(0, 0, -1);
        break;    
        
        default:
            // do nothing
            break;
    }
}



void Event::mouse_release(char m){
    
    switch (m) {
        
        case 0xf1:
            Mouse.release(MOUSE_LEFT);
            break;
        
        case 0xf2:
            Mouse.release(MOUSE_MIDDLE);
            break;
        
        case 0xf3:
            Mouse.release(MOUSE_RIGHT);
            break;  
                
        default:
            // do nothing
            break;
    }
}


Event event;

USBHIDKeyboard Keyboard;
USBHIDMouse Mouse;