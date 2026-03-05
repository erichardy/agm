// Amzer Gozh Monitor

#include <Arduino.h>
#include "temperature.h"

#include "sleep.h"
// #include "display.h"


#define DEBUG
// #undef DEBUG
#ifdef DEBUG
  #define debug(x) Serial.print(x)
  #define debugln(x) Serial.println(x)
#else
  #define debug(x)
  #define debugln(x)
#endif

float jj = 6.3;
u_int16_t nbLoops = 0;

OneWire ds(DS18B20_PIN);
DallasTemperature sensors(&ds);
DeviceAddress insideThermometer;


void setup() {
  Serial.begin(115200);
  Serial.println("dans setup...");
  
  /*
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  if (!sensors.getAddress(insideThermometer, 0)){
    Serial.println("Unable to find address for Device 0");
  }
    Serial.println();
  sensors.setResolution(insideThermometer, TEMPERATURE_PRECISION);
  delay(500);
  */
}

void loop() {
/*   
  display.clearDisplay();
  display.setCursor(0,0);
  tempC = getExternalTemp();
  // display.println(tempC);
  // display.print(jj);
  // display.print (" ");
  // display.println(motionSensorCurrentState);
  display.println(temperature);

  display.display();
  // jj -= .32;
  xl += 2;
*/
  Serial.println(nbLoops++);
  delay(500);
  if (nbLoops > 3) {
    goToBed(5000000);
  }
}