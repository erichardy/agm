/* TODO
A completer avec les déclarations... cf temperature.cpp
*/
// #ifndef TEMPERATURE_H
// #define TEMPERATURE_H
#pragma once

#include <DallasTemperature.h>

#define WIRE Wire

// related to DS18B20
#define DS18B20_PIN 4
#define TEMPERATURE_PRECISION 12
/*
OneWire ds(DS18B20_PIN);
DallasTemperature sensors(&ds);
DeviceAddress insideThermometer;
*/

/* Code de retour de la fonction getTemperature() */
enum DS18B20_RCODES {
  READ_OK,  // Lecture ok
  NO_SENSOR_FOUND,  // Pas de capteur
  INVALID_ADDRESS,  // Adresse reçue invalide
  INVALID_SENSOR  // Capteur invalide (pas un DS18B20)
};

float getInternalTemp(DallasTemperature sensors, DeviceAddress insideThermometer);
byte getTemperature(float *temperature, byte reset_search, OneWire ds);
void printAddress(DeviceAddress deviceAddress);

// #endif