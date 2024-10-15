#include "Adafruit_VL53L0X.h"
#include <Wire.h>
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Wire.begin(D3, D4);
  Serial.begin(115200);
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1)
      ;
  }
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false);
  if (measure.RangeStatus != 4) {
    // Serial.print("Distance (mm): ");
    // Serial.println(measure.RangeMilliMeter);
    // Serial.println();
    Serial.print("Distance (cm): ");
    Serial.println(measure.RangeMilliMeter / 10);
  } else {
    Serial.println(" out of range ");
  }
  delay(100);
}
