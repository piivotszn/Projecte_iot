#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h> 

const char* ssid = "iPhone de Raul";     
const char* password = "RAUL8888";
const int limitCO2 = 60; 

void setup() {
  Serial.begin(115200); 
  Wire.begin(); 
}

void loop() {
  // Enviament d'un pols per simular la crida elèctrica a la línia digital I2C
  Wire.beginTransmission(0x3C); 
  Wire.endTransmission();
  
  Serial.println("Pols de sincronització I2C enviat correctament.");
  delay(2000);
}
