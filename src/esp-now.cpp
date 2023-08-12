#include "esp-now.h"

//instance of the class
EspNow espnow;

void EspNow::initialize() {


    // uint8_t mac[6];
    // get the mac address of the device
    esp_read_mac(mac, ESP_MAC_WIFI_STA);


    // Initialize ESP-NOW
    WiFi.mode(WIFI_STA);
    esp_now_init();

    // Add peer
    // esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, mac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    esp_now_add_peer(&peerInfo);

    // Register callback functions
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(OnDataReceived);
   
}

// Callback function for sending data
void EspNow::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
  // Handle send status
}

// // Callback function for receiving data
// void EspNow::OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
//   // Handle received data
// }


void EspNow::OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
    if (data_len == 4) {
        if (data[0] == 'c' && data[1] == 'a' && data[2] == 't') {
            uint8_t dynamicValue = data[3];

            Serial.print("Received data from: ");
            Serial.println(dynamicValue);

            // Now you can use the dynamicValue received
            testValue = dynamicValue;
        }
    }
}

uint8_t EspNow::testValue = 0; // Initialize it to a default value if needed



void EspNow::test(){

  Serial.println("ESP-NOW test");

  Serial.print("MAC Address: ");
  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", mac[i]);
    if (i < 5) {
      Serial.print(":");
    }
  }
  Serial.println();

  Serial.print("testValue: ");
  Serial.println(testValue);

}

void EspNow::send_switch_layer(uint8_t dynamicValue) {
    uint8_t data[4];
    data[0] = 'c';
    data[1] = 'a';
    data[2] = 't';
    data[3] = dynamicValue;

    Serial.println("Sending data...");

    // Send the data using ESP-NOW
    esp_now_send(peerInfo.peer_addr, data, sizeof(data));
}