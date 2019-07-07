//#define FASTLED_ALLOW_INTERRUPTS 0
//#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <FastLED.h>

#define NUM_LEDS 16
#define DATA_PIN D8
CRGB leds[NUM_LEDS];
uint8_t hue;

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, GBR>(leds, NUM_LEDS);
}

void loop() {
  fill_rainbow(leds, NUM_LEDS, hue, 20);
  hue++;
  delay(5);
  FastLED.show();
}
