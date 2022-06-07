#pragma once
#include "DataStorage.h"
#include <iostream>

class USBFlashDrive : public DataStorage
{
public:
	USBFlashDrive();
	USBFlashDrive(string name, double size);
	USBFlashDrive(const USBFlashDrive& fd);

	void printInfo() override;
	void valueInput() override;
};

