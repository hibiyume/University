#include "HardDiskDrive.h"
#include <string>

using namespace std;

HardDiskDrive::HardDiskDrive()
{
	name = "UNKNOWN HARD DISK DRIVE";
	size = 0;
}
HardDiskDrive::HardDiskDrive(string name, double size)
{
	this->name = name;
	this->size = size;
}
HardDiskDrive::HardDiskDrive(const HardDiskDrive& hdd)
{
	name = hdd.name;
	size = hdd.size;
}

void HardDiskDrive::printInfo()
{
	cout << "Hard disk drive name : " << name << endl;
	cout << "Hard disk drive size : " << size << endl;
}
void HardDiskDrive::valueInput()
{
	string name;
	double size;

	cout << "Enter the name of the hard disk drive : ";
	cin.ignore();
	getline(cin, name);

	while (true) {
		cout << "Enter its size (use '.' to write fractictional part) : ";
		if (cin >> size)
			break;
		else {
			cout << "Invalid input" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	this->name = name;
	this->size = size;
}