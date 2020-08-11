//I2C
#include <Wire.h>

// BME280
#include <EnvironmentCalculations.h>
#include <BME280I2C.h>
BME280I2C bme;

// Radio
#include <SoftwareSerial.h>
SoftwareSerial radio = SoftwareSerial(9, 7);

// JSON
#include <ArduinoJson.h>
const size_t capacity = JSON_OBJECT_SIZE(4);
