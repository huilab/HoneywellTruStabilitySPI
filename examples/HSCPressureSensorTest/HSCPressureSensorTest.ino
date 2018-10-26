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
TruStability_PressureSensor sensor( SLAVE_SELECT_PIN, -15.0, 15.0 );

void setup() {

  Serial.begin(115200);
  sensor.begin();

}

void loop() {

  if( sensor.fetchData() == 0 ) {
    Serial.print( "temp [C]: " );
    Serial.print( sensor.temperature() );
    Serial.print( "\t pressure [psi]: " );
    Serial.print( sensor.pressure() );
    Serial.print( "\t time [µs]: " );
    Serial.println( sensor.lastUpdateTime() );
  }
  
  delay( 10 ); // Slow down sampling. This is just a test.

}
