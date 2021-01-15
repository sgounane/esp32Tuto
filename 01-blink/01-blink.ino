
int LED = 2;
void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);

}

void loop() {
  Serial.print("...");
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);

}
