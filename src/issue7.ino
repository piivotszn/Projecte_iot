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
  // Algorisme de simulació contínua que canvia a cada refresc
  static float percentatgeCO2 = 44.2;
  percentatgeCO2 += random(-2, 4); // Variació decimal dinàmica
  
  // Filtres per mantenir les dades dins de marges lògics coherents
  if (percentatgeCO2 < 15) percentatgeCO2 = 35.0;
  if (percentatgeCO2 > 90) percentatgeCO2 = 45.0; 

  Serial.println("Lectura dinàmica calculada: " + String(percentatgeCO2, 1) + "%");
  delay(2000);
}
