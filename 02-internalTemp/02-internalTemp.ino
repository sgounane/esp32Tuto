#include <WiFi.h> 

#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();


const char *ssid =  "Orange-E131";  
const char *pass =  "NGD84BM2FH";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  int t=temprature_sens_read();
  if (WiFi.status() == WL_CONNECTED){
    Serial.print("Cnnected Temperature: ");
    Serial.print(t);
    Serial.println(" C");
  }
  else{
    Serial.print("Not connected Temperature: ");
    Serial.print((t-32)/1.8);
    Serial.println(" C");
  }
  
  delay(500);
}
