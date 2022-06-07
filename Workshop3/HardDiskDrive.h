#pragma once
#include "DataStorage.h"
#include <iostream>

class HardDiskDrive : public DataStorage
{
public:
	HardDiskDrive();
	HardDiskDrive(string name, double size);
	HardDiskDrive(const HardDiskDrive& fd);

	void printInfo() override;
	void valueInput() override;
};

