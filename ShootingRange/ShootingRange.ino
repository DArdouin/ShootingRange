/*
 Name:		ShootingRange.ino
 Created:	10/02/2018 23:26:56
 Author:	Damien
*/

#include "SensitivitySensor.h"
#include "HitSensor.h"

//Analog
#define sensorPin 0
#define sensitivityInput 1

//Digital
#define ledPin 2

SensitivitySensor sensitivitySensor(sensitivityInput);
HitSensor hitSensor(sensorPin);

void setup() {
	pinMode(2, OUTPUT);
	Serial.begin(19200);
}

void loop() {
	sensitivitySensor.Fetch();
	hitSensor.Fetch(sensitivitySensor.Value());

	if (hitSensor.IsTriggered()) 
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}

	delay(2);
}

