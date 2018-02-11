#include "HitSensor.h"

HitSensor::HitSensor(int inputPin)
{
	_inputPin = inputPin;
}

void HitSensor::Fetch(double thresholdPercentage)
{
	double value = analogRead(_inputPin);
	double threshold = (thresholdPercentage / 100) * (_maximumthreshold - _minimumthreshold) + _minimumthreshold;

	if (value > threshold) 
	{
		_upTime = millis();
		_isTriggered = true;
		Serial.print("Triggered value : ");
		Serial.print(value);
		Serial.print(" threshold : ");
		Serial.println(threshold);
	}
	else 
	{
		long time = millis();
		if (time > _upTime + _upDelay)
		{
			_isTriggered = false;
		}
	}
}

bool HitSensor::IsTriggered()
{
	return _isTriggered;
}