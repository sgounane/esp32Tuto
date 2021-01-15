void setup() {
  Serial.begin(115200);
}
 
void loop() {
  int h = 0;
  h = hallRead();
  Serial.printf("Hall sensor measurement: %d\n",h);
  delay(100);
}
