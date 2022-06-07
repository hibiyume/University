#include "Printer.h"

void Printer::Printing(DataStorage* ds)
	{
		cout << "Name : " << ds->getName() << endl;
		cout << "Size : " << ds->getSize() << endl;
	}