#include "PaymentBook.h"

PaymentBook::PaymentBook()
{
	cost_kh = -1;
	last_date = "null";
	initialized = false;
}
PaymentBook::PaymentBook(const PaymentBook& book)
{
	size = book.size;
	meters = new ElectricityMeter[size];
	auto this_book = begin();
	for (auto it = book.begin(); it != book.end(); it++)
	{
		*this_book = *it;
		this_book++;
	}

	cost_kh = book.cost_kh;
	last_date = book.last_date;
	initialized = book.initialized;
}
PaymentBook::PaymentBook(double cost_kh)
{
	this->cost_kh = cost_kh;
	this->initialized = true;
}
PaymentBook::~PaymentBook()
{
	delete[] meters;
	meters = 0;
}

bool PaymentBook::isInitialized() const
{
	return initialized;
}
ElectricityMeter* PaymentBook::getMeters() const 
{
	return meters;
}
int PaymentBook::getSize() const
{
	return size;
}
double PaymentBook::getKilowattHourCost() const
{
	return cost_kh;
}
string PaymentBook::getLastDate() const
{
	string date = last_date;
	if (date.at(date.length() - 1) == '\n')
		date.pop_back();
	return date;
}
double PaymentBook::getAmountOfConsumedEnergy() const
{
	double result = 0;

	if (size != 0)
	{
		for (auto it = begin(); it != end(); it++)
		{
			result += (*it).getValue();
		}

		return result;
	}
	else
		throw Exception("The array is not initialized!");
}
double PaymentBook::getCostOfConsumedEnergy() const
{
	return getAmountOfConsumedEnergy() * cost_kh;
}

Iterator<ElectricityMeter> PaymentBook::begin() const
{
	return Iterator<ElectricityMeter>(&meters[0]);
}
Iterator<ElectricityMeter> PaymentBook::end() const 
{
	return Iterator<ElectricityMeter>(&meters[size]);
}

void PaymentBook::addMeter(const ElectricityMeter& meter)
{
	ElectricityMeter* m = new ElectricityMeter[size + 1];
	if (size != 0) {
		auto it_m = Iterator<ElectricityMeter>(&m[0]);
		for (auto it = begin(); it != end(); it++)
		{
			*it_m = *it;
			it_m++;
		}
		m[size] = meter;

		time_t now = time(0);
		last_date = ctime(&now);

		delete[] meters;
		meters = m;
	}
	else
	{
		time_t now = time(0);
		last_date = ctime(&now);
		meters = new ElectricityMeter[1]{ meter };
	}

	size++;
	initialized = true;
}
void PaymentBook::deleteBook()
{
	delete[] meters;
	meters = 0;

	size = 0;
	initialized = false;
	cost_kh = 1;
	last_date = "";
}
void PaymentBook::deleteMeter(const int& index)
{
	ElectricityMeter* m = new ElectricityMeter[size - 1];
	auto it_m = Iterator<ElectricityMeter>(&m[0]);
	for (auto it = begin(); it != Iterator<ElectricityMeter>(&meters[index]); it++)
	{
		*it_m = *it;
		it_m++;
	}
	for (auto it = Iterator<ElectricityMeter>(&meters[index + 1]); it != end(); it++)
	{
		*it_m = *it;
		it_m++;
	}

	delete[] meters;
	meters = m;
	size--;
	initialized = true;
}
void PaymentBook::setKilowattHourCost(const double& cost)
{
	cost_kh = cost;
} 
void PaymentBook::setLastDate(const string date)
{
	last_date = date;
	if (last_date.at(last_date.length() - 1) == '\n')
		last_date.pop_back();
}
