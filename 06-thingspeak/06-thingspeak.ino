#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#define API_KEY "9HYZA5T8LXMVS6CO"
int t=0;
WiFiMulti wifiMulti;
void setup() {
  Serial.begin(115200);
  wifiMulti.addAP("Orange-E131", "NGD84BM2FH1");
  
}

void loop() {
    // wait for WiFi connection
    
    if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;
        Serial.print("[HTTP] begin...\n");
        http.begin(String("http://api.thingspeak.com/update?api_key=")+
        String(API_KEY)+
        String("&field1=")+
        String(t)); //HTTP
        Serial.print("[HTTP] GET...\n");
        int httpCode = http.GET();
        if(httpCode <= 0) {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }
    t++;

    delay(5000);
}
