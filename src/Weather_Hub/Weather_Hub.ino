// Settings
#define HUB_NAME "Weather Hub"
//#define DEBUG

// LCD
#define I2C_ADDRESS 0x3C
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
SSD1306AsciiWire oled;

// Radio
#include <SoftwareSerial.h>
SoftwareSerial radio = SoftwareSerial(9, 7);

// JSON
#include <ArduinoJson.h>
const size_t capacity = JSON_OBJECT_SIZE(3) + 10;
