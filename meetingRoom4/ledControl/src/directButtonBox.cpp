#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include <HTTPClient.h>

const char *ssid = "ESP32_AP";
const char *password = "password";
const char *ledBarIP = "192.168.4.1";
// pins
#define redPin 27    // GPIO19
#define greenPin 33  // GPIO18
#define bluePin 32   // GPIO05
#define buttonPin 14 // GPIO13


int commandCount = 0; // Variable to keep track of button presses

void sendRequestToLEDBar(String endpoint)
{
    HTTPClient http;
    String url = "http://" + String(ledBarIP) + endpoint;
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0)
    {
        Serial.printf("HTTP request sent to LED bar, response code: %d\n", httpCode);
    }
    else
    {
        Serial.println("HTTP request failed");
    }
    http.end();
}

void setup()
{
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
}

void loop()
{
    // Check if the button is pressed
    if (digitalRead(buttonPin) == LOW)
    {

        Serial.println("test");
        // Increment command count and ensure it stays within 3 (0, 1, 2)
        commandCount = (commandCount + 1) % 3;

        // Determine command based on command count
        String command;
        if (commandCount == 0)
        {
            analogWrite(redPin, 0);
            analogWrite(greenPin, 255);
            analogWrite(bluePin, 0);
            command = "greenLed";
        }
        else if (commandCount == 1)
        {
            analogWrite(redPin, 255);
            analogWrite(greenPin, 0);
            analogWrite(bluePin, 0);
            command = "redLed";
        }
        else if (commandCount == 2)
        {
            analogWrite(redPin, 255);
            analogWrite(greenPin, 255);
            analogWrite(bluePin, 255);
            command = "clearLed";
        }

        // Send HTTP request to trigger LED bar
        Serial.print("Button pressed, sending request to LED bar for command: ");
        Serial.println(command);
        sendRequestToLEDBar("/esp32/setLeds?command=" + command);

        // Delay to debounce the button
        delay(100);
    }
}
