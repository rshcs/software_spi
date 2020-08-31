
#include "arduino.h"
#include "SoftwareSPI.h"

SoftwareSPI::SoftwareSPI(int mosiPin, int misoPin, int sckPin)
{
	_mosiPin = mosiPin;
	_misoPin = misoPin;
	_sckPin = sckPin;
	
	pinMode(_mosiPin, OUTPUT);
	pinMode(_misoPin, INPUT);
	pinMode(_sckPin, OUTPUT);
	
	digitalWrite(_mosiPin, LOW);
	digitalWrite(_sckPin, LOW);
}

byte SoftwareSPI::transfer(byte outByte)
{
	byte inByte = 0;
	delayMicroseconds(10);
	for (int i = 7; i > -1; i--)
	{
		digitalWrite(_mosiPin, bitRead(outByte, i));
		digitalWrite(_sckPin, HIGH);
		bitWrite(inByte, i, digitalRead(_misoPin));
		digitalWrite(_sckPin, LOW);
	}
	delayMicroseconds(10);
	return inByte;
}

int SoftwareSPI::transfer16(int16_t outInt)
{
	byte inInt_High = transfer(highByte(outInt));
	byte inInt_Low = transfer(lowByte(outInt));
	
	int inInt = inInt_High << 8 | inInt_Low;

	return inInt;
}
/*
void SoftwareSPI::printPins()
	{
		Serial.print("Mosi=");
		Serial.print(_mosiPin);
		Serial.print(" |miso=");
		Serial.print(_misoPin);
		Serial.print(" |sck=");
		Serial.println(_sckPin);
	}
*/
