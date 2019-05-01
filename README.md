# Honeywell TruStability SPI [![Build Status](https://travis-ci.org/huilab/HoneywellTruStabilitySPI.svg?branch=master)](https://travis-ci.org/huilab/HoneywellTruStabilitySPI)
An Arduino library for communicating with Honeywell TruStability HSC or SSC digital pressure sensors over SPI.
Based on the Honeywell technical note at https://sensing.honeywell.com/spi-comms-digital-ouptu-pressure-sensors-tn-008202-3-en-final-30may12.pdf
#### View the documentation
https://huilab.github.io/HoneywellTruStabilitySPI/
#### Install
To download, click the Download Zip button. In the Arduino IDE go to Sketch -> Include Library -> Add .ZIP Library. Or, install this library with the Arduino Library Manager.
For details on installing libraries, see the guide at https://www.arduino.cc/en/Guide/Libraries#toc3
#### Use
Include the library and declare a sensor:
```C
#include <HoneywellTruStabilitySPI.h>
// construct a +/- 15 PSI sensor using the default SPI slave select pin (SS)
TruStabilityPressureSensor sensor( SS, -15.0, 15.0 );
```
initialize the sensor:
```C
SPI.begin(); // start SPI communication
sensor.begin(); // run sensor initialization
```
read values:
```C
// the sensor returns 0 if new data is ready
if( sensor.readSensor() == 0 ) {
  float t = sensor.temperature();
  float p = sensor.pressure();
}
```
For more details, see the handy example sketch.
