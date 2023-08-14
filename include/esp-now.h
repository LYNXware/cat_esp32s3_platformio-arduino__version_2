#ifndef ESP_NOW_H
#define ESP_NOW_H
#include "config.h"

#include <Arduino.h>


#include <WiFi.h>
#include <esp_now.h>


class EspNow {

    public:

        void initialize();

        void send_switch_layer(uint8_t la);

        void scan_for_slave();

    private:

        // wife credentials
        #define CHANNEL 1
        String wifi_name = "LYNX-"; // + cat_variant;

        // slave mac address
        esp_now_peer_info_t peerInfo;
    
        static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);

        static void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len); 

};

//instance of the class 
extern EspNow espnow;

#endif