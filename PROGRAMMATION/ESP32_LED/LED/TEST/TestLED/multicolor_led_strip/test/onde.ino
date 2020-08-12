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


//============== Programme =====================
// Mode multicolore uniforme
//==============================================
void loop(){ 

static uint8_t hue;
  for(int i = 0; i < NUM_LEDS/2; i++) {   
    // fade everything out
    leds.fadeToBlackBy(40);

    // let's set an led value
    leds[i] = CHSV(hue++,255,255);

    // now, let's first 20 leds to the top 20 leds, 
    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    FastLED.delay(33);
  }
}