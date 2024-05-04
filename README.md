# LL120 Arduino without Commander Pro or Lighting Hub

# Fan details
1x LL Fan => 16x Leds => 12x Outer LEDs + 4x Inner LEDs
They are WS2811 LEDs
Colour order: GRB
At least USB 3.0 is recommended to meet power requirements. You may also fine alternative power solutions.

RGB connector pin order: [Ground | Data in | Data out | 5v] (Assuming it's facing flat side up)

<p>
  <img src="https://github.com/Aw4k3/LL120-Arduino-without-Commander-Pro-or-Lighting-Hub/blob/master/LL120%20Fan%20LED%20order.png" width="400" height="400">
  <img src="https://github.com/Aw4k3/LL120-Arduino-without-Commander-Pro-or-Lighting-Hub/blob/master/LL120%20RGB%20Connecter%20Pin%20order.png" width="400">
</p>

# Getting the RGB to work
<ol>
  <li>Wire your LL fan's 5v and Ground to your arduino or power source of choice.</li>
  <li>Wire your LL fan's data in to any data pin. (If you have more than one fan, connect the fan's data out to the next fan's data in)</li>
  <li>Connect your arduino board to your computer</li>
  <li>Open and configure your Arduino IDE appropriately for the board you are using.</li>
  <li>Download the sketch from this repository and open it in your IDE</li>
  <li>Upload the code.</li>
</ol>

# Code base
```c++
//#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <FastLED.h>

#define NUM_LEDS 16 // No. of fans * 16
#define DATA_PIN D8 // Set according to your configuration
CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, GBR>(leds, NUM_LEDS);
}

void loop() {
  // Your lighting code here
  FastLED.show();
}
```
Uncomment #define FASTLED_ESP8266_RAW_PIN_ORDER if you get a pin error when using a NodeMCU board
