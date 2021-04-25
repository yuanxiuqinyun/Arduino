// DS1307 & TM1637 7-segment with Arduino
#include "TM1637.h"
#include "RTClib.h"
// pins definitions for TM1637 and can be changed to other ports       
#define CLK 10
#define DIO 9
TM1637 tm1637(CLK,DIO);
// Holds current clock time
RTC_DS1307 RTC; 
DateTime theTime; 
int8_t TimeDisp[] = {0xff, 0xff, 0xff, 0xff};

void setup() {

  Serial.begin(9600);
  Serial.println(F("第六组实验内容："));
  if (!RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }
  if (!RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  tm1637.init();
  tm1637.set(2);         // TYPICAL = 2, DARKEST = 0, BRIGHTEST = 7;
  tm1637.display(0,10);  // show A B C D for testing
  tm1637.display(1,11);   
  tm1637.display(2,12); 
  tm1637.display(3,13);
  delay(3000);
}

int hour, minute, second;
unsigned char ClockPoint = 1;
void loop() {
   
  DateTime theTime = RTC.now();
  second = theTime.second();  // get seconds
  minute = theTime.minute();  // get minutes

  TimeDisp[0] = 0;
  TimeDisp[1] = 6;
  TimeDisp[2] = minute / 10;
  TimeDisp[3] = minute % 10;
  
  tm1637.display(0,TimeDisp[0]);
  tm1637.display(1,TimeDisp[1]); 
  tm1637.display(2,TimeDisp[2]);
  tm1637.display(3,TimeDisp[3]);
  Serial.print(F("显示器上的内容：06:"));
  Serial.print(minute);
  Serial.print(F("\n"));
  Serial.print("Set to ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println();
  ClockPoint = (~ClockPoint) & 0x01;
  if(ClockPoint)tm1637.point(POINT_ON);
  else tm1637.point(POINT_OFF); 
  delay(1000);  
}
