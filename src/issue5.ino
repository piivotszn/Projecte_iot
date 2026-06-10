#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h> 

const char* ssid = "iPhone de Raul";     
const char* password = "RAUL8888";
const int limitCO2 = 60; 

void setup() {
  // Inicialització de la consola sèrie a alta velocitat (115200)
  Serial.begin(115200); 
  delay(500);
  
  // Inicialització nativa del protocol I2C
  Wire.begin(); 
  
  Serial.println("Consola de control sèrie i bus digital I2C actius.");
}

void loop() {
  // Canals actius
}
