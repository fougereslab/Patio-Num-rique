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

  // remise à 0 de la teinte
  if(hue==255)
  {
    hue = 255;
  }

  hue+= 5; // changement de teinte
  
  CHSV color = CHSV(hue,255,255); // Création de la couleur
  
  // changement par color de la couleur des LEDS
 for(int i = 0; i < NUM_LEDS; i++) {  

   leds[i]= color;
   
  }

FastLED.show(); // Affichage de la nouvelle couleur

delay(5); // Attente 5 ms

}