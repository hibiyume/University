#pragma once

#include "Meter.h"

class ElectricityMeter : public Meter
{
private:
	int integralCount;
	int fractionalCount;
public:
	ElectricityMeter();
	ElectricityMeter(double value, double min, double max);
	ElectricityMeter(double min, double max);
	ElectricityMeter(const ElectricityMeter& meter);
	virtual ~ElectricityMeter();

	int getIntegralCount();
	int getFractionalCount();
};

