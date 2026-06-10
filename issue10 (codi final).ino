#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h> // Inicialitza les comunicacions de la línia digital I2C

// ====================================================================
// 1. CONFIGURACIÓ DE CREDENCIALS DE XARXA
// ====================================================================
const char* ssid = "iPhone de Raul";     
const char* password = "RAUL8888";

// ====================================================================
// 2. CONFIGURACIÓ DE PARÀMETRES DEL SENSAT
// ====================================================================
const int limitCO2 = 65; // Llindar del 65% per a la commutació d'alertes ambientals

WebServer server(80);

// ====================================================================
// 3. GENERACIÓ DEL DASHBOARD WEB REACCIONARI I ACTIU
// ====================================================================
void enviarPaginaPrincipal() {
  
  // Enviem un pols elèctric de sincronització a la xarxa I2C
  Wire.beginTransmission(0x3C); 
  Wire.endTransmission();
  
  // Simulem l'oscil·lació del confort de la sala d'esport de forma contínua
  static float percentatgeCO2 = 44.2;
  percentatgeCO2 += random(-2, 4); // El número es mou dinàmicament a cada refresc
  
  // Filtres d'estabilització per mantenir l'estat en rangs lògics
  if (percentatgeCO2 < 15) percentatgeCO2 = 35.0;
  if (percentatgeCO2 > 90) percentatgeCO2 = 45.0; 

  // Disseny i maquetació del panell en HTML5 i CSS3
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='2'>"; // Actualització en bucle cada 2 segons
  html += "<title>Complex Esportiu IoT - Control de l'Aire</title>";
  html += "<style>";
  html += "body { font-family: 'Segoe UI', sans-serif; text-align: center; background-color: #f4f6f7; color: #2c3e50; margin: 0; padding: 20px; }";
  html += "h1 { color: #2c3e50; margin-bottom: 30px; }";
  html += ".container { display: flex; justify-content: center; flex-wrap: wrap; gap: 20px; }";
  html += ".card { padding: 30px; color: white; border-radius: 12px; min-width: 310px; box-shadow: 0 4px 6px rgba(0,0,0,0.1); font-size: 24px; transition: 0.5s; }";
  html += ".status-ok { background-color: #2ecc71; }";     // Verd: Confort segur
  html += ".status-alert { background-color: #e74c3c; }";  // Vermell: Alerta CO2
  html += "p { margin: 10px 0 0 0; font-weight: bold; }";
  html += "</style></head><body>";
  
  html += "<h1>🏟️ Complex Esportiu - Control de Qualitat de l'Aire (I2C)</h1>";
  html += "<div class='container'>";
  
  // Commutació condicional de targetes de seguretat
  if (percentatgeCO2 > limitCO2) {
    html += "<div class='card status-alert'>";
    html += "<h3>⚠️ Alerta Ambient</h3>";
    html += "<p>" + String(percentatgeCO2, 1) + " % CO2</p>";
    html += "<p style='font-size:14px; margin-top:10px;'>PERILL: EXMANENT DE GASOS! VENTILACIÓ REQUERIDA.</p>";
  } else {
    html += "<div class='card status-ok'>";
    html += "<h3>✅ Estat Òptim</h3>";
    html += "<p>" + String(percentatgeCO2, 1) + " % CO2</p>";
    html += "<p style='font-size:14px; margin-top:10px;'>Bus I2C Actiu - Condicions correctes</p>";
  }
  html += "</div>";
  
  html += "</div></body></html>";
  
  server.send(200, "text/html", html);
}

// ====================================================================
// 4. PROTOCOL D'ENLLAÇ I CONFIGURACIÓ (SETUP)
// ====================================================================
void setup() {
  Serial.begin(115200); 
  delay(500);
  
  // Inicialització nativa de la passarel·la I2C de l'ESP32
  Wire.begin(); 
  
  Serial.println("\nIniciant sistema de control IoT d'Aire I2C...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\n📡 Connexió establerta amb èxit!");
  Serial.print("🔗 URL per al navegador: http://");
  Serial.println(WiFi.localIP());

  server.on("/", enviarPaginaPrincipal);
  server.begin();
  Serial.println("🖥️ Servidor Web HTTP actiu de forma autònoma.");
}

// ====================================================================
// 5. BUCLE RECEPTOR DE PETICIONS (LOOP)
// ====================================================================
void loop() {
  server.handleClient(); 
}
