#include <Adafruit_Sensor.h>
#include <breath.h>
#include <DHT.h>
#include <DHT_U.h>


Breath pin(13);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  pin.breath(ON);

}
