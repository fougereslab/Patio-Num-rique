//========= Définitions ========
#include <FastLED.h>  // Appel de la librairie FastLED
#define NUM_LEDS 300  // Nombre de LED commandé


//======= Déclarations =========
CRGBArray<NUM_LEDS> leds; // Création de l'objet contenant les leds
int hue; // teinte, couleur led

//========== Initialisation ===================
void setup() {
  hue = 0;  // Mise à 0 de la teinte
  
  FastLED.clear(); // Initialisation leds

  FastLED.addLeds<NEOPIXEL,4>(leds, NUM_LEDS); // Ajout des leds à l'objet FastLED (paramétrage modèle de LED et nombres de leds)

  // Allumage des leds en blanc
  for(int i = 0; i < NUM_LEDS; i++)
  {   
   leds[i]= CRGB::White; // Définition de la couleur de la LED i en blanc
  }

  FastLED.show(); // Affichage des nouvelles couleurs

  }

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}
