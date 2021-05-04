#include <SPI.h>
#include <LoRa.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender Test");
 
  if (!LoRa.begin(868100000)) {
    Serial.println("Starting LoRa failed!");
    while (1);
}

void loop() {
  // put your main code here, to run repeatedly:
  LoRa.beginPacket();
  LoRa.print("packet from Arduino with lora shield");
  LoRa.endPacket();
  delay(5000);

}
