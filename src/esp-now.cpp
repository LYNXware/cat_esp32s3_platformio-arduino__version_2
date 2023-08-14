#include "esp-now.h"

//instance of the class
EspNow espnow;

void EspNow::initialize() {

    // WiFi.mode(WIFI_STA); // Set ESP32 to station (client) mode
    // WiFi.mode(WIFI_AP); // Set ESP32 to access point mode

    // Initialize Wi-Fi: simultanious (Station Mode) and WIFI_AP (Access Point Mode)
    WiFi.mode(WIFI_AP_STA);

    // set up an Access Point 
    // WiFi.softAP(SSID, "Slave_1_Password", CHANNEL, 0);
    WiFi.softAP(config.variant, "Slave_1_Password", CHANNEL, 0);

    // Initialize ESP-NOW
    esp_now_init();

    // Register callback functions
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(OnDataReceived);
}






void EspNow::scan_for_slave(){

    Serial.println("Scanning for slaves");
  
    // Scan for slaves
    // int8_t scanResults = WiFi.scanNetworks();
    int8_t scanResults = WiFi.scanNetworks(false, false, false, 300, CHANNEL); // Scan only on one channel
    
    // reset mac address
    memset(&peerInfo, 0, sizeof(peerInfo));
    // Serial.println("Scan done");

      if (scanResults == 0) {
          Serial.println("No ESP32 devices nearby found");

      } else {

          Serial.print("Found ");
          Serial.print(scanResults);
          Serial.println(" device(s)");

          for (int i = 0; i < scanResults; ++i) {

              // Print SSID and RSSI for each device found
              String SSID = WiFi.SSID(i);
              int32_t RSSI = WiFi.RSSI(i);
              String BSSIDstr = WiFi.BSSIDstr(i);

              Serial.printf("%d: %s (%d) %s\n", i + 1, SSID.c_str(), RSSI, BSSIDstr.c_str());
              delay(10);
              // Serial.println(SSID);
              // Serial.println(SSID.indexOf("RX"));

              // Check if the current device starts with `Slave`
              if (SSID.indexOf("C") == 0) {
                  // SSID of interest
                  Serial.println("Found a Slave.");
                  // Get BSSID => Mac Address of the Slave
                  int mac[6];
                  if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x%c", 
                      &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5])) {
                      for (int ii = 0; ii < 6; ++ii) {
                          peerInfo.peer_addr[ii] = (uint8_t) mac[ii];
                      }
                  }
  
                  peerInfo.channel = 0; // pick a channel
                  peerInfo.encrypt = false; // no encryption
  
                  // Add peer        
                  esp_now_add_peer(&peerInfo);
                  // break;
              }
          }
      }
      // clean up ram
      WiFi.scanDelete();
}







// Callback function for sending data
void EspNow::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
  Serial.println("OnDataSent");
  // Handle send status
}

// // Callback function for receiving data
// void EspNow::OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len) {
//   // Handle received data
// }


void EspNow::OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len) {

    Serial.println("OnDataReceived");

    if (data_len == 4) {
        if (data[0] == 'c' && data[1] == 'a' && data[2] == 't') {
            uint8_t dynamicValue = data[3];

            Serial.print("Received data: ");
            Serial.println(dynamicValue);

            // Now you can use the dynamicValue received
            testValue = dynamicValue;
        }
    }
}

uint8_t EspNow::testValue = 0; // Initialize it to a default value if needed



void EspNow::test(){

  Serial.println("ESP-NOW test");

  esp_read_mac(mac, ESP_MAC_WIFI_STA);

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

    Serial.println("send_switch_layer data...");

    Serial.println(peerInfo.peer_addr[0]);


    // Send the data using ESP-NOW
    esp_now_send(peerInfo.peer_addr, data, sizeof(data));
}