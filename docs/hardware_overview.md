---
icon: material/cog
---

Let's take a closer look at the pair of sensors along with other hardware present on this Qwiic sensor breakout.

## SEN55 Particle, VOC, Humidity, and Temperature Sensor

The SEN55 Particle and VOC sensor module measures particulate matter and volatile organic compounds (VOCs) along with humidity and temperature. The SEN55 is designed with the idea to be a simple plug-and-play solution and includes all sensors, processors, power control, and fan inside a compact housing all with a single, calibrated, digital signal output communicating over I<sup>2</sup>C making it perfect to integrate into this Qwiic combination breakout.

<figure markdown>
[![Photo highlighting SEN55](./assets/img/Indoor_Air_Quality_Sensor-SEN55.jpg){ width="600"}](./assets/img/Indoor_Air_Quality_Sensor-SEN55.jpg "Click to enlarge")
</figure>

The SEN55 reports measurments of particulate matter, VOC index, NO<sub>x</sub> indect, temperature, and relative humidity every second. The sensor measures particulates of the following size specifications: PM1, PM2.5, PM4, and PM10 from a concentration of 0 to 1,000 &micro;g/m<sup>3</sup>. It also senses both VOC and NO<sup>x</sup> indexes from 1 to 500 index points. Lastly, it measures temperature from 15 to 30&deg;C and relative humidity from 30 to 70%RH. It offers a robust set of control registers to take and report measurements as well as check the status of the module and its components. The table below outlines some of the sensing parameters for the SEN55. Refer to the [datasheet](./assets/component_documentation/Sensirion_Datasheet_Environmental_Node_SEN5x.pdf) for a complete overview.

<table>
    <tr>
        <th>Parameter</th>
        <th>Units</th>
        <th>Min</th>
        <th>Typ</th>
        <th>Max</th>
        <th>Conditions/Notes</th>
    </tr>
    <tr>
        <td>Mass concentration range</td>
        <td>&micro;g/m<sup>3</sup></td>
        <td>-</td>
        <td>0</td>
        <td>-</td>
        <td>1,000</td>
        <td>-</td>        
    </tr>
    <tr>
        <td>PM1.0 Mass concentration size</td>
        <td>&micro;g</td>
        <td>0.3</td>
        <td>-</td>
        <td>1.0</td>
        <td>-</td>
    </tr>
    <tr>
        <td>PM2.5 Mass concentration size</td>
        <td>&micro;g</td>
        <td>0.3</td>
        <td>-</td>
        <td>2.5</td>
        <td>-</td>
    </tr>
    <tr>
        <td>PM4 Mass concentration size</td>
        <td>&micro;g</td>
        <td>0.3</td>
        <td>-</td>
        <td>4.0</td>
        <td>-</td>
    </tr>
    <tr>
        <td>PM10 Mass concentration size</td>
        <td>&micro;g</td>
        <td>0.3</td>
        <td>-</td>
        <td>10.0</td>
        <td>-</td>
    </tr>
    <tr>
        <td>Temperature accuracy (Typ.)</td>
        <td>&deg;C</td>
        <td>-</td>
        <td>&plusmn;0.45</td>
        <td>-</td>
        <td>@ 15-30 &deg;C, 50 %RH</td>
    </tr>
    <tr>
        <td>Temperature repeatability</td>
        <td>&deg;C</td>
        <td>-</td>
        <td>0.1</td>
        <td>-</td>
        <td>@25&deg;C, 50 %RH</td>
    </tr>
    <tr>
        <td>Relative humidity accuracy (Typ.)</td>
        <td>%RH</td>
        <td>-</td>
        <td>&plusmn;4.5</td>
        <td>-</td>
        <td>@25&deg;C, 30-70 %RH</td>
    </tr>
    <tr>
        <td>Relative humidity repeatability</td>
        <td>%RH</td>
        <td>-</td>
        <td>&plusmn;1</td>
        <td>-</td>
        <td>@25&deg;C, 50 %RH</td>
    </tr>
    <tr>
        <td>VOC Index output</td>
        <td>VOC Index points</td>
        <td>1</td>
        <td>-</td>
        <td>500</td>
        <td>-</td>
    </tr>
    <tr>
        <td>VOC Index repeatability</td>
        <td>VOC Index points</td>
        <td>-</td>
        <td><&plusmn;5</td>
        <td>-</td>
        <td>-</td>
    </tr>
    <tr>
        <td>NO<sub>x</sub> Index output</td>
        <td>NO<sub>x</sub> Index points</td>
        <td>1</td>
        <td>-</td>
        <td>500</td>
        <td>-</td>
    </tr>
    <tr>
        <td>NO<sub>x</sub> Index repeatability</td>
        <td>NO<sub>x</sub> Index points</td>
        <td>-</td>
        <td><&plusmn;10</td>
        <td>-</td>
        <td>-</td>
    </tr>
</table>

### SEN55 Power

The SEN55 accepts a supply voltage between <b>4.5V</b> to <b>5.5V</b> with a typical voltage of <b>5V</b> with a peak current draw of <b>110mA@5V</b>. The SparkFun Indoor Air Quality Sensor uses an on-board buck/boost circuit to boost the <b>3.3V</b> from a Qwiic connector or to the <b>3.3V</b> PTH pin to <b>5V</b>.

## SCD41 CO<sub>2</sub> Humidity and Temperature Sensor

The SCD41 CO<sub>2</sub> sensor uses Sensirion's PASense<sup>&trade;</sup>, a photoacoustic measurement system, to accurately measure CO<sub>2</sub> concentration using a combination of a narrow band of IR light and a microphone. The sensor also has a built-in humidity and temperatuer sensor using Sensirion's CMOSens<sup>&trade;</sup> technology to provide environmental data and compensate for environmental conditions in CO<sub>2</sub> measurement. For a detailed overview of the SCD41 sensor, refer to the [datasheet](./assets/component_documentation/Sensirion_CO2_Sensors_SCD4x_Datasheet.pdf).

<figure markdown>
[![Photo highlighting SCD41](./assets/img/Indoor_Air_Quality_Sensor-SCD41.jpg){ width="600"}](./assets/img/Indoor_Air_Quality_Sensor-SCD41.jpg)
</figure>

Now you may be curious as to just what photoacoustic measuring actually is. Photoacoustic measuring uses light (photo) and sound/vibrations (acoustic) in tandem to measure the the photoacoustic effect when energy is absorbed by particles (in the case of these sensors, CO<sub>2</sub> molecules). The SCD41 has an IR emitter with a filter to shine a specific IR light into the sensing area. CO<sub>2</sub> molecules inside the sensing area absorb energy from the emitted IR light and vibrate. The microphone inside the sensing area picks up this acoustic vibration and then this data is processed to report CO<sub>2</sub> concentration. This is just a quick and basic explanation of the photoacoustic process used in this sensor. For detailed information on Sensirion's PASens and CMOSens technology, refer to their [technology page](https://sensirion.com/products/technology).

<table>
    <tr>
        <th>Parameter</th>
        <th>Units</th>
        <th>Min</th>
        <th>Typ</th>
        <th>Max</th>
        <th>Notes</th>
    </tr>
    <tr>
        <td>CO<sub>2</sub> Output Range</td>
        <td>ppm</td>
        <td>0</td>
        <td>-</td>
        <td>40,000</td>
        <td></td>
    </tr>
    <tr>
        <td>CO<sub>2</sub> Measurement Accuracy</td>
        <td>ppm</td>
        <td>-</td>
        <td>&plusmn;(40 + 5%)</td>
        <td>-</td>
        <td>-</td>
    </tr>
    <tr>
        <td>Humidity Range</td>
        <td>%RH</td>
        <td>0</td>
        <td>-</td>
        <td>100</td>
        <td></td>
    </tr>
    <tr>
        <td rowspan="2" style="vertical align middle">Humidity Accuracy</td>
        <td rowspan="2" style="vertical align middle">%RH</td>
        <td>-</td>
        <td>&plusmn;6</td>
        <td>-</td>
        <td>15&deg;C - 35&deg;C, 20%RH - 65%RH</td>
    </tr>
    <tr>
        <td>-</td>
        <td>&plusmn;9</td>
        <td>-</td>
        <td>-10&deg;C - 60 &deg;C, 0%RH - 100%RH</td>
    </tr>
    <tr>
        <td>Temperature Range</td>
        <td>&deg;C</td>
        <td>-10</td>
        <td>-</td>
        <td>60</td>
        <td></td>
    </tr>
    <tr>
        <td rowspan="2" style="vertical align middle">Temperature Accuracy</td>
        <td rowspan="2" style="vertical align middle">&deg;C</td>
        <td>-</td>
        <td>&plusmn;0.8</td>
        <td>-</td>
        <td>15&deg;C - 35&deg;C</td>
    </tr>
    <tr>
        <td>-</td>
        <td>&plusmn;1.5</td>
        <td>-</td>
        <td>-10&deg;C - 60&deg;C</td>
    </tr>
</table>

## Qwiic & I<sup>2</sup>C Interface

The Indoor Air Quality Sensor operates over I<sup>2</sup>C using either the two Qwiic connectors or the 0.1"-spaced plated through-hole (PTH) header. Power for the board is supplied over either of these options as well.

<figure markdown>
[![Photo highlighting Qwiic connectors & I2C header.](./assets/img/Indoor_Air_Quality_Sensor-I2C.jpg){ width="600"}](./assets/img/Indoor_Air_Quality_Sensor-I2C.jpg "Click to enlarge")
</figure>

## Power LED

There is just one red LED on the board to indicate power. By default, it is always powered whenever <b>3.3V</b> is present though users can disable it by adjusting the solder jumper covered in the next section.

<figure markdown>
[![Photo highlighting Power LED.](./assets/img/Indoor_Air_Quality_Sensor-LED.jpg){ width="600"}](./assets/img/Indoor_Air_Quality_Sensor-LED.jpg "Click to enlarge")
</figure>

## Solder Jumpers

The board has two solder jumpers labeled <b>PWR</b> and <b>I2C</b>. The <b>PWR</b> jumper completes the power LED circuit and is CLOSED by default. Open the jumper to disable the power LED. The <b>I2C</b> jumper pulls the I<sup>2</sup>C SDA and SCL lines to <b>3.3V</b> via a pair of <b>2.2k</b>&ohm; resistors. This three way jumper is completely closed by default. Open it completely to disable the pullup resistors.

<figure markdown>
[![Photo highlighting solder jumpers.](./assets/img/Indoor_Air_Quality_Sensor-Jumpers.jpg){ width="600"}](./assets/img/Indoor_Air_Quality_Sensor-Jumpers.jpg "Click to enlarge")
</figure>

## Board Dimensions

This Qwiic breakout runs a bit larger than standard Qwiic breakouts to fit the SEN55 and measures 3.25" x 1.75" (82.55mm x 44.45mm) and has four mounting holes that fit a [4-40 screw](https://www.sparkfun.com/products/10453). The SEN55 is a bit of an odd shape to fit everything in the housing but it measures 0.878" (22.3mm) at it's tallest and it's footprint is 2.06" x  1.70" (52.3 mm x 43.3 mm). For detailed measurements of the entire sensor package, refer to the [SEN55 datasheet](./assets/component_documentation/Sensirion_Datasheet_Environmental_Node_SEN5x.pdf).

<figure markdown>
[![Board dimensions](./assets/board_files/SparkFun_Indoor_Air_Quality_Sensor-Dimensions.jpg){ width="400}](./assets/board_files/SparkFun_Indoor_Air_Quality_Sensor-Dimensions.jpg "Click to enlarge")
</figure markdown>