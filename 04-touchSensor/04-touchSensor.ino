#define TOUCH 15
void setup()
{
  Serial.begin(115200);
  Serial.println("Touch sensor tutorial ESP32");
}

void loop()
{
  int v=touchRead(TOUCH);
  Serial.println(v);
  delay(1000);
}
