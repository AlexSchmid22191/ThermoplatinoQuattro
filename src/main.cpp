#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Adafruit_MAX31865.h>
#include <Adafruit_I2CDevice.h>


Adafruit_MAX31865 sensors[4] {{7}, {8}, {9}, {10}};

#define R_REF 430
#define R_NOM 100

void setup()
{
  for(byte i=0; i<4; i++)
  {
    sensors[i].begin(MAX31865_4WIRE);
  }
  Serial.begin(9600);
}

void loop()
{
  for(auto &sensor:sensors)
  {
    Serial.println(sensor.temperature(R_NOM, R_REF));
  }
}