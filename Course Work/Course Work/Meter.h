#pragma once

#include <iostream>
#include "Exception.h"
#include "Iterator.h"

class Meter
{
protected:
	double value;
	double min, max;
public:
	Meter();
	Meter(double value, double min, double max);
	Meter(double min, double max);
	Meter(const Meter& meter);
	virtual ~Meter();

	double getValue() const;
	double getMinValue() const;
	double getMaxValue() const;
	void setValue(double value);
	void setMinValue(double value);
	void setMaxValue(double value);

	Meter& operator++(int);
	Meter& operator--(int);
	Meter& operator+=(double value);
	Meter& operator-=(double value);
	Meter& operator=(const Meter& m);

	friend std::ostream& operator<<(std::ostream& os, const Meter& m);
	friend std::istream& operator>>(std::istream& is, Meter& m);
};

