#include "esp-now.h"

//instance of the class
EspNow espnow;

void EspNow::initialize() {


    uint8_t mac[6];
    esp_read_mac(mac, ESP_MAC_WIFI_STA);


    // Initialize ESP-NOW
    WiFi.mode(WIFI_STA);
    esp_now_init();

    // Add peer
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, mac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    esp_now_add_peer(&peerInfo);

    // Register callback functions
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(OnDataReceived);
   
}

// Callback function for sending data
void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
  // Handle send status
}

// Callback function for receiving data
void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
  // Handle received data
}