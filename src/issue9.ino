#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h> 

const char* ssid = "iPhone de Raul";     
const char* password = "RAUL8888";
const int limitCO2 = 60; 

WebServer server(80);

void enviarPaginaPrincipal() {
  float percentatgeCO2 = 44.2; // Dada base provisional de maquetació

  // Disseny amb l'etiqueta de refresc d'interfície automatitzat cada 2 segons
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='2'>"; 
  html += "<title>Panell I2C</title>";
  html += "<style>body { font-family: sans-serif; text-align: center; background-color: #f4f6f7; }</style>";
  html += "</head><body><h1>Control d'Aire</h1></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  // Preparant rutes de navegació
}

void loop() {
  // Interfície web d'estructura bàsica preparada
}
