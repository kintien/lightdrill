#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include <Adafruit_NeoPixel.h>


Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 6);

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
//Adafruit_TSL2561_Unified tsl1 = Adafruit_TSL2561_Unified(TSL2561_ADDR_HIGH (0 x 49), 12345);
//Adafruit_TSL2561_Unified tsl2 = Adafruit_TSL2561_Unified(TSL2561_ADDR_HIGH (0 x 29), 12345);

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Light Sensor Test"); Serial.println("");
  strip.begin();
  strip.setPixelColor(0, 200, 200, 200);
  strip.show();
  delay(300);

  /* Initialise the sensor */
  //use tsl.begin() to default to Wire,
  //tsl.begin(&Wire2) directs api to use Wire2, etc.
  if (!tsl.begin())
  {
    /* There was a problem detecting the TSL2561 ... check your connections */
    Serial.print("Ooops, no TSL2561 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }




}



void loop(void)
{ delay(300);

  sensors_event_t event;
  tsl.getEvent(&event);

  double light1 = event.light;
  int x =  random(1000, 8000);
  //make x the delay so randomly between 0 & 5sec the following steps happen

  delay(x);
  int y = random(1, 3);

  if (y == 1) {
    int var = 0;
    while (var < 1) {

      tsl.getEvent(&event);
      double light2 = event.light;
      tsl.getEvent(&event);
      Serial.print(event.light); Serial.println(" lux");
      if (light1 > light2) {
        //turn lights green
        strip.setPixelColor(0, 200, 200, 0);
        strip.show();
        var = 1;
      }
      else {
        strip.setPixelColor(0, 200, 0, 0);
        strip.show();
      }
    }
  }


  /*give the sensors new names for bottom 2, and same for neopixels*/

  /*
    if (y == 2) {
    int var = 0;
    while (var < 1) {

      tsl1.getEvent(&event);
      double light2 = event.light;
      tsl1.getEvent(&event);
      Serial.print(event.light); Serial.println(" lux");
      if (light1 > light2) {
        //turn lights green
        strip.setPixelColor(0, 200, 200, 0);
        strip.show();
        var = 1;
      }
      else {
        strip.setPixelColor(0, 200, 0, 0);
        strip.show();
      }
    }
    }


    else {
    int var = 0;
    while (var < 1) {

      tsl2.getEvent(&event);
      double light2 = event.light;
      tsl2.getEvent(&event);
      Serial.print(event.light); Serial.println(" lux");
      if (light1 > light2) {
        //turn lights green
        strip.setPixelColor(0, 200, 200, 0);
        strip.show();
        var = 1;
      }
      else {
        strip.setPixelColor(0, 200, 0, 0);
        strip.show();
      }
    }
    }



  */
}



