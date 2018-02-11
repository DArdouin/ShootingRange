#pragma once

#include "Arduino.h"

class HitSensor
{
private:
	const int _minimumthreshold = 50;
	const int _maximumthreshold = 250;
	const int _upDelay = 5000;

	int _inputPin;
	long _upTime;
	bool _isTriggered;

public:
	HitSensor(int inputPin);
	void Fetch(double thresholdPercentage);
	bool IsTriggered();
};

