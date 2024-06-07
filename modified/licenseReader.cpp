#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN 12
#define NUM_LEDS 37
#define LED_TYPE WS2812B
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];

void prepLeds()
{
    FastLED.clear();
    FastLED.show();
    // white 1
    for (int i = 4; i < 8; i++)
    {
        leds[i] = CRGB::White;
    }
    // white 2
    for (int i = 23; i < 28; i++)
    {
        leds[i] = CRGB::White;
    }
}

void setLedsGreen()
{
    // Set LEDs to green
    prepLeds();
    for (int i = 8; i < 23; i++)
    {
        leds[i] = CRGB::Green;
    }
    FastLED.show();
};

void setLedsRed()
{

    // Set LEDs to red
    prepLeds();
    for (int i = 28; i < 37; i++)
    {
        leds[i] = CRGB::Red;
    }
    FastLED.show();
};

void clearLeds()
{
    FastLED.clear();
    prepLeds();
    FastLED.show();
};

void setup()
{
    Serial.begin(9600);
    delay(1000);

    // Initialize LED strip
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(100);
}

void loop()
{
    // Other loop logic can go here
}

// ideal ratio for leds:
// starting white: 0 to 4
// green is 5 to 18
// white 2 is 19 to 22
// red is 24 to 37
