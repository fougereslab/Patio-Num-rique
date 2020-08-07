
//======== Définition ========
#include <FastLED.h>
#define NUM_LEDS 300

//====== Déclarations =========
CRGBArray<NUM_LEDS> leds;
int hue;
int volume;
int calcul;

//========= Initialisation =========
void setup() {
  Serial.begin(115200);  // Liaison série
  hue = 0; // Init hue
  
  FastLED.clear(); // Préparation objet Fastled
  FastLED.addLeds<NEOPIXEL,6>(leds, NUM_LEDS); // AJout des leds dans FastLed

  // Réglage couleur de toutes les leds en blanc
  for(int i = 0; i < NUM_LEDS; i++)
  {   
   leds[i]= CRGB::White; // Réglage de la led i avec la couleur blanche
  }

  FastLED.show(); // Affichage des réglages de couleurs de fastled

  }


//========= Programme principale ========
void loop(){ 
  
  volume = (analogRead(A0)-914)*30; // Calcul du volume
  //Serial.println(volume);
  delay(50); // Attente
  
  CHSV color = CHSV(volume,255,255); // création d'une couleur à partir du dernier volume mesuré par le micro
  
  // changement de couleurs de toutes les leds selon la couleur crée "color"
 for(int i = 0; i < NUM_LEDS; i++)
 {  
   leds[i]= color;
  }

FastLED.show(); // afficher les nouvelles couleurs

}
