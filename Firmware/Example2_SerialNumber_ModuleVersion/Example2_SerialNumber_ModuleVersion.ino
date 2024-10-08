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

  This example contains additional output (serial number and module version).

  This example is a combination of the examples written by SparkFun and Sensirion:
  https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library
  https://github.com/Sensirion/arduino-i2c-sen5x

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
  SparkFun Indoor Air Quality Sensor - SCD41 SEN55 (Qwiic) (SEN-25200) https://www.sparkfun.com/products/25200

  Hardware Connections:
  Plug a Qwiic cable into the board an ESP32 based board such as the SparkFun IoT RedBoard: https://www.sparkfun.com/products/19177
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/17912)
  Open the serial monitor at 115200 baud to see the output
*/

// The used commands use up to 48 bytes. On some Arduino's the default buffer
// space is not large enough
#define MAXBUF_REQUIREMENT 48

#if (defined(I2C_BUFFER_LENGTH) &&                 \
     (I2C_BUFFER_LENGTH >= MAXBUF_REQUIREMENT)) || \
    (defined(BUFFER_LENGTH) && BUFFER_LENGTH >= MAXBUF_REQUIREMENT)
#define USE_PRODUCT_INFO
#endif

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

  // Print SEN55 module information if i2c buffers are large enough
#ifdef USE_PRODUCT_INFO
  printSerialNumber();
  printModuleVersions();
#endif

  // set a temperature offset in degrees celsius
  // Note: supported by SEN54 and SEN55 sensors
  // By default, the temperature and humidity outputs from the sensor
  // are compensated for the modules self-heating. If the module is
  // designed into a device, the temperature compensation might need
  // to be adapted to incorporate the change in thermal coupling and
  // self-heating of other device components.
  //
  // A guide to achieve optimal performance, including references
  // to mechanical design-in examples can be found in the app note
  // “SEN5x – Temperature Compensation Instruction” at www.sensirion.com.
  // Please refer to those application notes for further information
  // on the advanced compensation settings used
  // in `setTemperatureOffsetParameters`, `setWarmStartParameter` and
  // `setRhtAccelerationMode`.
  //
  // Adjust tempOffset to account for additional temperature offsets
  // exceeding the SEN module's self heating.
  float tempOffset = 0.0;
  error = sen5x.setTemperatureOffsetSimple(tempOffset);
  if (error) {
    Serial.print("Error trying to execute setTemperatureOffsetSimple(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.print("Temperature Offset set to ");
    Serial.print(tempOffset);
    Serial.println(" deg. Celsius (SEN54/SEN55 only)");
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

void printModuleVersions()
{
  uint16_t error;
  char errorMessage[256];

  unsigned char productName[32];
  uint8_t productNameSize = 32;

  error = sen5x.getProductName(productName, productNameSize);

  if (error) {
    Serial.print("Error trying to execute getProductName(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.print("ProductName:");
    Serial.println((char*)productName);
  }

  uint8_t firmwareMajor;
  uint8_t firmwareMinor;
  bool firmwareDebug;
  uint8_t hardwareMajor;
  uint8_t hardwareMinor;
  uint8_t protocolMajor;
  uint8_t protocolMinor;

  error = sen5x.getVersion(firmwareMajor, firmwareMinor, firmwareDebug,
                           hardwareMajor, hardwareMinor, protocolMajor,
                           protocolMinor);
  if (error) {
    Serial.print("Error trying to execute getVersion(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.print("Firmware: ");
    Serial.print(firmwareMajor);
    Serial.print(".");
    Serial.print(firmwareMinor);
    Serial.print(", ");

    Serial.print("Hardware: ");
    Serial.print(hardwareMajor);
    Serial.print(".");
    Serial.println(hardwareMinor);
  }
}

void printSerialNumber() {
  uint16_t error;
  char errorMessage[256];
  unsigned char serialNumber[32];
  uint8_t serialNumberSize = 32;

  error = sen5x.getSerialNumber(serialNumber, serialNumberSize);
  if (error) {
    Serial.print("Error trying to execute getSerialNumber(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.print("SerialNumber:");
    Serial.println((char*)serialNumber);
  }
}
