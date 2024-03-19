---
icon: material/cog
---

Let's take a closer look at the pair of sensors along with other hardware present on this Qwiic sensor breakout.

## SEN55 Particle, VOC, Humidity, and Temperature Sensor

The SEN55 Particle and VOC sensor measures particulate matter and volatile organic compounds (VOCs) along with humidity and temperature.

## SCD41 CO<sub>2</sub> Humidity and Temperature Sensor

The SCD41 CO<sub>2</sub> sensor uses Sensirion's PASense<sup>&trade;</sup>, a photoacoustic measurement system, to accurately measure CO<sub>2</sub> concentration using a combination of a narrow band of IR light and a microphone. The sensor also has a built-in humidity and temperatuer sensor using Sensirion's CMOSens<sup>&trade;</sup> technology to provide environmental data and compensate for environmental conditions in CO<sub>2</sub> measurement. For a detailed overview of the SCD41 sensor, refer to the [datasheet](./assets/component_documentation/Sensirion_CO2_Sensors_SCD4x_Datasheet.pdf).

Now you may be curious as to just what photoacoustic measuring actually is. Photoacoustic measuring uses light (photo) and sound/vibrations (acoustic) in tandem to measure the the photoacoustic effect when energy is absorbed by particles (in the case of these sensors, CO<sub>2</sub> molecules). The SCD41 has an IR emitter with a filter to shine a specific IR light into the sensing area. CO<sub>2</sub> molecules inside the sensing area absorb energy from the emitted IR light and vibrate. The microphone inside the sensing area picks up this acoustic vibration and then this data is processed to report CO<sub>2</sub> concentration. This is just a quick and basic explanation of the photoacoustic process used in this sensor. For detailed information on Sensirion's PASens and CMOSens technology, refer to their [technology page](https://sensirion.com/products/technology).

## Qwiic/I<sup>2</sup>C Interface

## LED

This board has just one red LED to indicate power. By default, it is always powered whenever <b>3.3V</b> is present though users can disable it by adjusting the solder jumper covered in the next section.

## Solder Jumpers

This combo board has two solder jumpers labeled <b>PWR</b> and <b>I2C</b>. The <b>PWR</b> jumper completes the power LED circuit and is CLOSED by default. Open the jumper to disable the power LED. The <b>I2C</b> jumper pulls the I<sup>2</sup>C SDA and SCL lines to <b>3.3V</b> via a pair of <b>2.2k</b>&ohm; resistors. This three way jumper is completely closed by default. Open it completely to disable the pullup resistors.

## Board Dimensions

This Qwiic breakout runs a bit larger than standard Qwiic breakouts to fit the SEN55 and measures 3.25" x 1.75" (82.55mm x 44.45mm) and has four mounting holes that fit a [4-40 screw](https://www.sparkfun.com/products/10453).