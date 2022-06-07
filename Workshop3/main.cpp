#include <iostream>
#include <conio.h>
#include "DataStorage.h"
#include "FloppyDisk.h"
#include "HardDiskDrive.h"
#include "OpticalDisk.h"
#include "USBFlashDrive.h"
#include "Printer.h"

using namespace std;

void printMenu();

int main()
{
	int option = 0;
	while (option != 5)
	{
		printMenu();
		cin >> option;
		cin.clear();
		cin.ignore();
		switch (option)
		{
			case 1:
			{
				FloppyDisk fd;
				fd.valueInput();
				cout << endl;
				cout << "Printing info using printInfo() virtual function that DataStorage class contain and FloppyDisk class implement" << endl;
				fd.printInfo();
				cout << endl;
				cout << "Press any key to continue" << endl;
				_getch();
			}
				break;
			case 2:
			{
				HardDiskDrive hdd;
				hdd.valueInput();
				cout << endl;
				cout << "Printing info using printInfo() virtual function that DataStorage class contain and FloppyDisk class implement" << endl;
				hdd.printInfo();
				cout << endl;
				cout << "Press any key to continue" << endl;
				_getch();
			}
				break;
			case 3:
			{
				OpticalDisk od;
				od.valueInput();
				cout << endl;
				cout << "Printing info using Printer::Printing() function" << endl;
				Printer::Printing(&od);
				cout << endl;
				cout << "Press any key to continue" << endl;
				_getch();
			}
				break;
			case 4:
			{
				USBFlashDrive usb;
				usb.valueInput();
				cout << endl;
				cout << "Printing info using Printer::Printing() function" << endl;
				Printer::Printing(&usb);
				cout << endl;
				cout << "Press any key to continue" << endl;
				_getch();
			}
				break;
			case 5:
				break;
			default:
				cout << "Invalid option" << endl;
				break;
		}
	}
}

void printMenu()
{
	system("cls");
	cout << "Enter the number to continue." << endl;
	cout << "1 - Enter new floppy disk" << endl;
	cout << "2 - Enter new hard disk drive" << endl;
	cout << "3 - Enter new optical disk" << endl;
	cout << "4 - Enter new USB flash drive" << endl;
	cout << "5 - Close program" << endl;
}