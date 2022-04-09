#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))
#include <ArduinoJson.h>

/* Wifi includes */
#include <ESP8266WiFi.h>
char ssid[] = "BESIKTAS";
char pass[] = "9990475316";
/***********************/

/* Blynk includes */
#define BLYNK_FIRMWARE_VERSION "0.1"
#define BLYNK_TEMPLATE_ID "TMPLO8E6fVpN"
#define BLYNK_DEVICE_NAME "Led Kontrol Aygıtı"
#define BLYNK_AUTH_TOKEN "NufO2c7BI4ZuMek_HQ0nBjUBogjfbc3_"
#define BLYNK_PRINT Serial
#define MAX_AMPER 60
#include <BlynkSimpleEsp8266.h>
bool gameEffects = true;
/***********************/

/* Async WebServer includes */
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#define webServerPort 80
AsyncWebServer server(webServerPort);
/***********************/

/* NTP Client includes */
#include <NTPClient.h>
#include <WiFiUdp.h>
WiFiUDP ntpUDP;
const byte GMT = 3;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600*GMT);
/***********************/

/* Effect Manager includes */
#include "EffectManager.h"


/* FastLED includes */
#include <FastLED.h>
#define NUM_LEDS 900
#define DATA_PIN D7
#define LED_TYPE WS2812B
CRGB leds[NUM_LEDS];
/***********************/
