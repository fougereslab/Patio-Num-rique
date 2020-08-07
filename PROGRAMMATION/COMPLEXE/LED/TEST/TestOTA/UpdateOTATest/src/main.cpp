//========= Définition ========
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <FastLED.h>

const char* ssid = "   ";
const char* password = "   ";

//========= Initialisation =========
void setup() {
  Serial.begin(115200); // Initialisation Liaison Série
  Serial.println("Démarrage"); // Affichage Démarrage

  //========== Démarrage WiFi ==============
  WiFi.mode(WIFI_STA); // Paramétrage du module en mode station
  WiFi.begin(ssid, password); // Démarrage de la connexion WIFI avec les paramètres wifi
  while (WiFi.waitForConnectResult() != WL_CONNECTED) // Procédure de connexion WiFi
  {
    Serial.println("Connection Failed! Rebooting..."); // Affichage échec de connexion
    delay(5000); // Attente 5S 
    ESP.restart(); // Redémarrage ESP32
  }
  //========= Fin Démarrage WiFi =================

  //=========== Paramétrage OTA ==========
  ArduinoOTA.setHostname("monEsp"); // on donne une petit nom a notre module
  ArduinoOTA.begin(); // initialisation de l'OTA
}

void loop() {
  ArduinoOTA.handle();
}