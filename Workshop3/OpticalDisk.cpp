#include "OpticalDisk.h"
#include <string>

using namespace std;

OpticalDisk::OpticalDisk()
{
	name = "UNKNOWN FLOPPY DISK";
	size = 0;
}
OpticalDisk::OpticalDisk(string name, double size)
{
	this->name = name;
	this->size = size;
}
OpticalDisk::OpticalDisk(const OpticalDisk& fd)
{
	name = fd.name;
	size = fd.size;
}

void OpticalDisk::printInfo()
{
	cout << "Optical disk name : " << name << endl;
	cout << "Optical disk size : " << size << endl;
}

void OpticalDisk::valueInput()
{
	string name;
	double size;

	cout << "Enter the name of the optical disk : ";
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

