#include "Meter.h"

Meter::Meter() {}
Meter::Meter(double value, double min, double max)
{
	setMinValue(min);
	setMaxValue(max);
	setValue(value);
}
Meter::Meter(double min, double max)
{
	setMinValue(min);
	setMaxValue(max);

	setValue(min);
};
Meter::Meter(const Meter& meter)
{
	max = meter.max;
	min = meter.min;
	value = meter.value;
}
Meter::~Meter() {}

double Meter::getValue() const
{
	return value;
}
double Meter::getMinValue() const
{
	return min;
}
double Meter::getMaxValue() const 
{
	return max;
}
void Meter::setValue(double value)
{
	this->value = value;

	if (this->value >= max)
		setValue(this->value - max);
	else if (this->value < min)
		this->value = min;
}
void Meter::setMinValue(double value)
{
	min = value;
	if (this->value < min)
		this->value = min;
}
void Meter::setMaxValue(double value)
{
	max = value;

	if (max < min)
		throw Exception("Exception - Maximum is greater than minimum.");
}

Meter& Meter::operator++(int)
{
	setValue(value + 1.0);
	return *this;
}
Meter& Meter::operator--(int)
{
	setValue(value - 1.0);
	return *this;
}
Meter& Meter::operator+=(double value)
{
	setValue(this->value + value);
	return *this;
}
Meter& Meter::operator-=(double value) {
	setValue(this->value - value);
	return *this;
}
Meter& Meter::operator=(const Meter& m)
{
	max = m.max;
	min = m.min;
	value = m.value;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Meter& m)
{
	os << "Current Value : " << m.value << std::endl;
	os << "Value's Range : " << m.min << "..." << m.max << std::endl;
	return os;
}
std::istream& operator>>(std::istream& is, Meter& m)
{
	double min, max, value;
	while (true) {
		std::cout << "Enter the meter's minimum value" << std::endl;
		if (is >> min)
		{
			m.setMinValue(min);
			break;
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
			is.clear();
			while (is.get() != '\n');
		}
	}

	while (true) {
		std::cout << "Enter the meter's maximum value" << std::endl;
		if (is >> max)
		{
			try {
				m.setMaxValue(max);
			}
			catch (Exception ex) {
				std::cout << ex.what() << std::endl;
				continue;
			}
			break;
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
			is.clear();
			while (is.get() != '\n');
		}
	}

	while (true) {
		std::cout << "Enter the meter's value" << std::endl;
		if (is >> value)
		{
			m.setValue(value);
			break;
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
			is.clear();
			while (is.get() != '\n');
		}
	}
	
	return is;
}