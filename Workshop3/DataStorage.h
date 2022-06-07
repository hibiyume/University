#pragma once
#include <iostream>

using namespace std;

class DataStorage
{
protected:
	double size;
	string name;
public:
	virtual ~DataStorage() = 0;

	double getSize();
	void setSize(double size);

	string getName();
	void setName(string name);

	virtual void printInfo() = 0;
	virtual void valueInput() = 0;
};

