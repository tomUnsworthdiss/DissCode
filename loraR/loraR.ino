#include <SPI.h>
#include <LoRa.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!LoRa.begin(868100000)) {

 Serial.println("Starting LoRa failed!");

 while (1);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
 
  int packetSize = LoRa.parsePacket();
   if (packetSize) {

   // received packet
   Serial.println("");
   Serial.println("Received packet: ");
   // read the packet
   String message = "";
   while (LoRa.available()) {
   message += (char)LoRa.read();
 }
 // print the Packet and RSSI
 Serial.println(message);
 Serial.print("RSSI: ");

 Serial.println(LoRa.packetRssi());
   }
}
