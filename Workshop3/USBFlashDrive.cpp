#include "USBFlashDrive.h"
#include <string>

using namespace std;

USBFlashDrive::USBFlashDrive()
{
	name = "UNKNOWN FLOPPY DISK";
	size = 0;
}
USBFlashDrive::USBFlashDrive(string name, double size)
{
	this->name = name;
	this->size = size;
}
USBFlashDrive::USBFlashDrive(const USBFlashDrive& fd)
{
	name = fd.name;
	size = fd.size;
}

void USBFlashDrive::printInfo()
{
	cout << "USB flash drive name : " << name << endl;
	cout << "USB flash drive size : " << size << endl;
}

void USBFlashDrive::valueInput()
{
	string name;
	double size;

	cout << "Enter the name of the USB flash drive : ";
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
