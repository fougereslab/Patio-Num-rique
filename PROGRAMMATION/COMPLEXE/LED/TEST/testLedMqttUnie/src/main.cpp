// Appel des librairies
#include <Arduino.h>
#include <FastLED.h>
#include <EspMQTTClient.h>
#include <Arduino_JSON.h>



// Nombre de leds
#define NUM_LEDS 600

// Informations de connexion MQTT et wifi
#define SSID "NETGEAR"
#define WifiPassword ""
#define IpMQTTBroker "172.16.0.9"
#define MQTTUsername ""
#define MQTTPassword ""
#define MQTTCLientName "bande_led_1"
#define MQTTPort 1883

// Initialisation de l'objet MQTT
EspMQTTClient client(SSID,WifiPassword,IpMQTTBroker,MQTTUsername,MQTTPassword,MQTTCLientName,MQTTPort);

// Initialisation des bandes leds
CRGBArray<NUM_LEDS> leds;

// Valeur de teinte
int hue;



void setup() {

  // Fonctionnalités optionnelles de EspMQTTClient :
  client.enableDebuggingMessages(); // Activation des message de débuggage
  client.enableHTTPWebUpdater();  // Activation de la mise à jour web (détail dans exemple librairie)

  // Reset de la teinte
  hue = 0;

  // Reset des Leds
  FastLED.clear();
  //FastLED.addLeds<WS2813,5>(leds,NUM_LEDS);
  FastLED.addLeds<WS2813,5,GRB>(leds,NUM_LEDS);

  // Boucle pour mettre toutes les leds en blanc avant le départ
  for(int i = 0;i<NUM_LEDS;i++)
  {
    leds[i] = CRGB::White;
  }

  // Affichage sur les leds
    FastLED.show();

}

CRGB colorParse(String color)
{
  JSONVar jSONColor = JSON.parse(color);

  int red = jSONColor["r"];
  int green = jSONColor["g"];
  int blue = jSONColor["b"];


  CRGB CRGBColor = CRGB(red,green,blue);

  return CRGBColor;

}

void changeAllLEDColor(CRGB color)
{

  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = color;
  }

  FastLED.show();

}

void changeIndividualLEDColor(String ledColorArray[])
{



}

void onConnectionEstablished()
{

  

  client.subscribe("led_color", [](const String & payload) {

    CRGB color = colorParse(payload);

    changeAllLEDColor(color);

  });

  


}

void loop()
{

  
  client.loop();
}