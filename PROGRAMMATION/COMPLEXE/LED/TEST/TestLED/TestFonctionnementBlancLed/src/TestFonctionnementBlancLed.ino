//========== Définition =========
#include <FastLED.h>
#define NUM_LEDS 300

//========= Définition =========
CRGBArray<NUM_LEDS> leds;
int hue;

//========== Initialisation
void setup() {

  
  FastLED.clear(); // Initialisation FastLed
  FastLED.addLeds<NEOPIXEL,4>(leds, NUM_LEDS); // Paramétrage de FastLed
   CRGB color = CRGB(255,255,255); // Création de la couleur blanche à partir de composantes RGB
   FastLED.setBrightness(255); // Paramétrage de la luminosité
  

  // Réglage de toutes les leds en blanc
 for(int i = 0; i < NUM_LEDS; i++)
 {  
   leds[i]= color;
  }

  FastLED.show(); // Affichage de toutes les leds

  }

void loop()
{ 
  
}
