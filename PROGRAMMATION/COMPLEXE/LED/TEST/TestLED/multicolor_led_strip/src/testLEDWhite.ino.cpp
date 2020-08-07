# 1 "C:\\Users\\miked\\AppData\\Local\\Temp\\tmp4g4o9mll"
#include <Arduino.h>
# 1 "C:/Users/miked/OneDrive/Documents/GitHub/Patio-Num-rique/PROGRAMMATION/COMPLEXE/LED/TEST/TestLED/multicolor_led_strip/src/testLEDWhite.ino"

#include <FastLED.h>
#define NUM_LEDS 500


CRGBArray<NUM_LEDS> leds;
int hue;
void setup();
void loop();
#line 10 "C:/Users/miked/OneDrive/Documents/GitHub/Patio-Num-rique/PROGRAMMATION/COMPLEXE/LED/TEST/TestLED/multicolor_led_strip/src/testLEDWhite.ino"
void setup() {
  hue = 0;

  FastLED.clear();

  FastLED.addLeds<NEOPIXEL,4>(leds, NUM_LEDS);


  for(int i = 0; i < NUM_LEDS; i++)
  {
   leds[i]= CRGB::White;
  }

  FastLED.show();

  }

void loop()
{
}