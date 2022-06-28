#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

#include "ElectricityMeter.h"
#include "Exception.h"
#include "Iterator.h"
#include "Iterator.cpp"

using namespace std;

class PaymentBook
{
private:
	ElectricityMeter* meters;
	int size;

	bool initialized;
	double cost_kh; // Kilowatt hour cost
	string last_date; //Last payment last_date

public:
	PaymentBook();
	PaymentBook(const PaymentBook& book);
	PaymentBook(double cost_kh);
	~PaymentBook();

	ElectricityMeter* getMeters() const;
	int getSize() const;
	bool isInitialized() const;
	double getKilowattHourCost() const;
	string getLastDate() const;
	double getAmountOfConsumedEnergy() const;
	double getCostOfConsumedEnergy() const;

	Iterator<ElectricityMeter> begin() const;
	Iterator<ElectricityMeter> end() const;

	void addMeter(const ElectricityMeter& meter);
	void deleteMeter(const int& index);
	void deleteBook();
	void setKilowattHourCost(const double& cost);
	void setLastDate(const string date);
};
