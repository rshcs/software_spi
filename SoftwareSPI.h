// SoftwareSPI.h

#ifndef _SOFTWARESPI_h
#define _SOFTWARESPI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SoftwareSPI 
{
 private:
	 int _misoPin, _mosiPin, _sckPin;
 public:
	SoftwareSPI(int mosiPin = 11, int misoPin = 12, int sckPin = 13);

	byte transfer(byte outByte);
	int16_t transfer16(int16_t outInt);
	
	//void printPins();
};

#endif

