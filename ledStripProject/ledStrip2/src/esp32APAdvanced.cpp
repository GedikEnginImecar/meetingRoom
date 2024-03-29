#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <HTTPClient.h>

const char *ssid = "ESP32-Access-Point";
const char *password = "123456789";

const int buttonPin = 21;           // GPIO pin where the button is connected
const int switchPin = 26;           // GPIO pin where the switch is connected
const int blinkStartButtonPin = 17; // GPIO pin for starting the blinking
const int blinkStopButtonPin = 16;  // GPIO pin for stopping the blinking

bool switchState = false;
bool buttonActive = false; // Flag to indicate if the button is active
bool ledBlinking = false;  // Flag to control LED blinking

unsigned long previousMillis = 0; // Stores last time LED was updated
const long interval = 500;        // Interval at which to blink (milliseconds)

bool ledGreen = false; // Flag to track LED color

AsyncWebServer server(80);

void handleButtonPress();
void toggleLed(bool turnOn);

void setup()
{
    Serial.begin(115200);
    Serial.print("Setting AP (Access Point)...");
    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    delay(1000);
    Serial.print("AP IP address: ");
    Serial.println(IP);

    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(switchPin, INPUT_PULLUP);
    pinMode(blinkStartButtonPin, INPUT_PULLUP);
    pinMode(blinkStopButtonPin, INPUT_PULLUP);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(200, "text/plain", "Hello, switch and button!"); });

    server.begin();
}

void loop()
{
    bool newSwitchState = digitalRead(switchPin) == HIGH;
    if (newSwitchState != switchState)
    {
        switchState = newSwitchState;
        Serial.print("Switch state changed: ");
        Serial.println(switchState);
        if (!switchState)
        {
            // If the switch is turned off, turn off the LED and disable blinking
            ledBlinking = false;
            toggleLed(false); // Turn off the LED
        }
    }

    if (switchState)
    { // Only allow button and LED operations if the switch is on
        if (digitalRead(buttonPin) == LOW && !buttonActive)
        {
            handleButtonPress();
            delay(100); // Debounce delay
        }

        if (digitalRead(blinkStartButtonPin) == LOW)
        {
            ledBlinking = true;
            delay(100); // Debounce delay
        }

        if (digitalRead(blinkStopButtonPin) == LOW)
        {
            ledBlinking = false;
            toggleLed(true); // Keep the LED on in the current color
            delay(100);      // Debounce delay
        }

        static bool ledState = false;
        if (ledBlinking)
        {
            unsigned long currentMillis = millis();
            if (currentMillis - previousMillis >= interval)
            {
                previousMillis = currentMillis;
                ledState = !ledState;
                toggleLed(ledState);
            }
        }
    }
}

void handleButtonPress()
{
    buttonActive = true;
    Serial.println("Button pressed, changing LED state...");
    ledGreen = !ledGreen;
    toggleLed(true); // Ensure the LED is on with the new color
    buttonActive = false;
}

void toggleLed(bool turnOn)
{
    int hue, saturation, value;
    if (turnOn)
    {
        hue = ledGreen ? 85 : 0;
        saturation = 255;
        value = 255;
    }
    else
    {
        hue = 0;
        saturation = 0;
        value = 0;
    }

    HTTPClient http;
    String url = "http://192.168.4.2/setcolor?hue=" + String(hue) + "&saturation=" + String(saturation) + "&value=" + String(value);
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    }
    else
    {
        Serial.print("Error on HTTP request. Code: ");
        Serial.println(httpResponseCode);
    }
    http.end();
}
