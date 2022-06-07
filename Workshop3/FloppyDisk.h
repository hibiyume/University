#pragma once
#include "DataStorage.h"
#include <iostream>

class FloppyDisk : public DataStorage
{
public:
	FloppyDisk();
	FloppyDisk(string name, double size);
	FloppyDisk(const FloppyDisk& fd);

	void printInfo() override;
	void valueInput() override;
};

