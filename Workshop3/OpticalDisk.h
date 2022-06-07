#pragma once
#include "DataStorage.h"
#include <iostream>

class OpticalDisk : public DataStorage
{
public:
	OpticalDisk();
	OpticalDisk(string name, double size);
	OpticalDisk(const OpticalDisk& fd);

	void printInfo() override;
	void valueInput() override;
};



