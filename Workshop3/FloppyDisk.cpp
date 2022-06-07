#include "FloppyDisk.h"
#include <string>

using namespace std;

FloppyDisk::FloppyDisk()
{
	name = "UNKNOWN FLOPPY DISK";
	size = 0;
}
FloppyDisk::FloppyDisk(string name, double size)
{
	this->name = name;
	this->size = size;
}
FloppyDisk::FloppyDisk(const FloppyDisk& fd)
{
	name = fd.name;
	size = fd.size;
}

void FloppyDisk::printInfo()
{
	cout << "Floppy disk name : " << name << endl;
	cout << "Floppy disk size : " << size << endl;
}

void FloppyDisk::valueInput()
{
	string name;
	double size;

	cout << "Enter the name of the floppy disk : ";
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
