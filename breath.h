
#ifndef Breath_h
#define Breath_h

#include <Arduino.h>

#define ON true
#define OFF false

class Breath
{
public:
	Breath(int pin);  //Constructor. attach pin to breath
	void breath(bool value);  //enable breathing with 1s duration
	void breath(bool value, int breathLength);   //enable breathing with blink duration
	void breath(bool value, int breathLength, int breathLoops);  //enable breathing with breath duration and number of loops
private:
	uint8_t pinNumber;
};

#endif
