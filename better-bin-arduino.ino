#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define UV '1'
#define RGB '2'

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

typedef struct rgbData rgbData;
struct rgbData {
  uint16_t r;
  uint16_t g;
  uint16_t b;
  uint16_t c;
};

unsigned long readUV();
void readRGB(rgbData* data);

void setup() {
    Serial.begin(9600);
    if (!tcs.begin()) {
      Serial.write("Color Sensor not found.");
    } else {
      Serial.write("Color Sensor connected.");
    }
}

void loop() {
    if (Serial.available() > 0) {
        char msg = Serial.readStringUntil('\n')[0];
        msg = RGB;
        // Read and send back requested sensor data
        switch (msg) {
            case UV:
                // todo: UV light on
                Serial.write(readUV());
                // todo: UV light off
                break;
            case RGB:
                rgbData data;
                readRGB(&data);
                Serial.write(data.r);
                Serial.write(data.g);
                Serial.write(data.b);
                Serial.write(data.c);
                break;
        }
    }
}

unsigned long readUV() {
    unsigned long val = 0;
    for (size_t i = 0; i < 1024; i++) {
        val += analogRead(A0);
        delay(2);
    }
    return val / 1024; // todo: Return percentage of maximum intensity or [0, 255]
}

void readRGB(rgbData* data) {
    tcs.getRawData(&data->r, &data->g, &data->b, &data->c);
}
