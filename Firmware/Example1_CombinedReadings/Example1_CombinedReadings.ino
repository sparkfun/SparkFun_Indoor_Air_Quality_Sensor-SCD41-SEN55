/*
  Reading SEN55 and SCD41 Dual Sensor Breakout
  By: Nathan Seidle
  SparkFun Electronics
  Date: August 14, 2024
  License: MIT. Please see LICENSE.md for more information.

  This example shows how to read the full set of sensor readings 
  from the Sensirion air particle/VOC/Humidty sensor (SEN55) and the CO2 sensor (SCD41).
  Particle readings are output once per second, CO2 is output every five seconds.
  Written primarily for ESP32 based boards but should work on others.

  This example is a combination of the examples written by Sensirion:
  https://github.com/Sensirion/arduino-i2c-scd4x
  https://github.com/Sensirion/arduino-i2c-sen5x

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
  SparkFun Indoor Air Quality Sensor - SCD41 SEN55 (Qwiic) (SEN-25200) https://www.sparkfun.com/products/25200

  Hardware Connections:
  Plug a Qwiic cable into the board an ESP32 based board such as the SparkFun IoT RedBoard: https://www.sparkfun.com/products/19177
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/17912)
  Open the serial monitor at 115200 baud to see the output
*/

#include <SensirionCore.h>// Click here to get the library: http://librarymanager/All#Sensirion_Core_Base
#include <SensirionI2CSen5x.h>// Click here to get the library: http://librarymanager/All#Sensirion_Sen5x
SensirionI2CSen5x sen5x;

#include "SparkFun_SCD4x_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD4x
SCD4x scd4x;

// Measurement Variables
float pm1p0;
float pm2p5;
float pm4p0;
float pm10p0;
float sen5xHumidity;
float ambientTemperature;
float vocIndex;
float noxIndex;

void setup()
{
  Serial.begin(115200);
  delay(250);

  Wire.begin();

  sen5x.begin(Wire);

  uint16_t error;
  char errorMessage[256];
  error = sen5x.deviceReset();
  if (error) {
    Serial.print("Error trying to execute deviceReset(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  }

  // Start Measurement
  error = sen5x.startMeasurement();
  if (error) {
    Serial.print("Error trying to execute startMeasurement(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  }

  //Start SCD4x CO2 measurements
  if (scd4x.begin() == false)
  {
    Serial.println(F("SCD4x not detected. Please check wiring. Freezing..."));
    while (true);
  }

  //The SCD4x has data ready every five seconds
}

void loop()
{
  uint16_t error;
  char errorMessage[256];

  error = sen5x.readMeasuredValues(
            pm1p0, pm2p5, pm4p0,
            pm10p0, sen5xHumidity, ambientTemperature, vocIndex,
            noxIndex);

  if (error) {
    Serial.print("Error trying to execute readMeasuredValues(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.print("SEN5x ");

    Serial.print("Pm1p0:");
    Serial.print(pm1p0);
    Serial.print(" ");
    Serial.print("Pm2p5:");
    Serial.print(pm2p5);
    Serial.print(" ");
    Serial.print("Pm4p0:");
    Serial.print(pm4p0);
    Serial.print(" ");
    Serial.print("Pm10p0:");
    Serial.print(pm10p0);
    Serial.print(" ");
    Serial.print("Humidity:");
    if (isnan(sen5xHumidity)) {
      Serial.print("n/a");
    } else {
      Serial.print(sen5xHumidity);
    }
    Serial.print(" ");
    Serial.print("Temp:");
    if (isnan(ambientTemperature)) {
      Serial.print("n/a");
    } else {
      Serial.print(ambientTemperature);
    }
    Serial.print(" ");
    Serial.print("VocIndex:");
    if (isnan(vocIndex)) {
      Serial.print("n/a");
    } else {
      Serial.print(vocIndex);
    }
    Serial.print(" ");
    Serial.print("NoxIndex:");
    if (isnan(noxIndex)) {
      Serial.println("n/a");
    } else {
      Serial.println(noxIndex);
    }
  }

  if (scd4x.readMeasurement()) // readMeasurement will return true when fresh data is available
  {
    Serial.print("SCD4x ");

    Serial.print("CO2(ppm):");
    Serial.print(scd4x.getCO2());

    Serial.print(" Temperature(C):");
    Serial.print(scd4x.getTemperature(), 1);

    Serial.print(" Humidity(%RH):");
    Serial.print(scd4x.getHumidity(), 1);

    Serial.println();
  }

  delay(1000);
}
