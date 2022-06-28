#include "ElectricityMeter.h"
#include <string>

ElectricityMeter::ElectricityMeter() {}
ElectricityMeter::ElectricityMeter(double value, double min, double max) : Meter(value, min, max)
{
	//Integral count
	integralCount = 0;
	std::string s = std::to_string((int)floor(this->value));
	integralCount = s.length();

	//Fractional count
	double f = this->value - floor(this->value);
	int _i = 0; // No zeros
	s = std::to_string(f);
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) != '0')
			_i++;
	}
	fractionalCount = _i - 1;
}
ElectricityMeter::ElectricityMeter(double min, double max) : Meter(min, max)
{
	//Integral count
	integralCount = 0;
	std::string s = std::to_string((int)floor(this->value));
	int _i = s.length();

	//Fractional count
	double f = this->value - floor(this->value);
	_i = 0; // No zeros
	s = std::to_string(f);
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) != '0')
			_i++;
	}
	fractionalCount = _i - 1;
}
ElectricityMeter::ElectricityMeter(const ElectricityMeter& meter) : Meter(meter)
{
	integralCount = meter.integralCount;
	fractionalCount = meter.fractionalCount;
}
ElectricityMeter::~ElectricityMeter() {};

int ElectricityMeter::getIntegralCount()
{
	return integralCount;
}
int ElectricityMeter::getFractionalCount()
{
	return fractionalCount;
}