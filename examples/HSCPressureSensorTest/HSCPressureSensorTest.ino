/*
 * PressureSensorTest
 *
 * Fetch and print values from a Honeywell 
 * TruStability HSC Pressure Sensor over SPI
 * 
 * The sensor values used in this demo are 
 * for a -15 to 15 psi gauge pressure sensor. 
 * 
 */

#include <HoneywellTruStabilitySPI.h>

#define SLAVE_SELECT_PIN SS
TruStabilityPressureSensor sensor( SLAVE_SELECT_PIN, -15.0, 15.0 );

void setup() {
  Serial.begin(115200); // start Serial communication
  SPI.begin(); // start SPI communication
  sensor.begin(); // run sensor initialization
}

void loop() {
  // the sensor returns 0 when new data is ready
  if( sensor.readSensor() == 0 ) {
    Serial.print( "temp [C]: " );
    Serial.print( sensor.temperature() );
    Serial.print( "\t pressure [psi]: " );
    Serial.println( sensor.pressure() );
  }
  
  delay( 100 ); // Slow down sampling to 10 Hz. This is just a test.

}
