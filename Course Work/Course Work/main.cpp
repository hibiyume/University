#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "Printer.h"
#include "Exception.h"

#include "Meter.h"
#include "ElectricityMeter.h"
#include "PaymentBook.h"

using namespace std;

CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
const COORD newLine = { 0, 2 };
COORD _coord;
PaymentBook book;

void PrintMenuPage();
void PrintBookPage();
void PrintCreateMeterPage();
void DeleteLastMeterPage();
void DeleteLastMeterByIndexPage();
void DeleteBookPage();
void SetCostPage();

// Return true if success
bool readFile(); 
bool writeFile();

template <typename T>
void ValidateInput(T& value);

COORD operator*(int i, const COORD& c);
COORD operator+(const COORD& c1, const COORD& c2);

int main()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	Printer::SetFullScreen();

	readFile();

	bool firstLaunch = true;
	while (true) {
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
		cin.clear();
		if (!firstLaunch)
		{
			cin.ignore(); 
		}
		firstLaunch = false;

		PrintMenuPage();

		int option;
		cin >> option;
		switch (option)
		{
		case 1: // 1 - Create new electricity meter
			PrintCreateMeterPage();
			_getch();
			break;
		case 2: // 2 - Delete last electricity meter
			DeleteLastMeterPage();
			_getch();
			break;
		case 3: // 3 - Delete last electricity meter by index
			DeleteLastMeterByIndexPage();
			_getch();
			break;
		case 4: // 4 - Set new kilowatt per hour cost
			SetCostPage();
			_getch();
			break;
		case 5: // 5 - Open payment book
			PrintBookPage();
			_getch();
			break;
		case 6: // 6 - Delete payment book
			DeleteBookPage();
			break;
		case 7: // 7 - Exit Program
			return(0);
			break;
		default:
			Printer::EraseConsole();
			Printer::PrintLine("Invalid input. Press any key to try again.");
			_getch();
			break;
		}
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3, (short)(bufferInfo.srWindow.Bottom - 3) });
}

void PrintMenuPage()
{
	Printer::EraseConsole();
	Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);
	Printer::PrintDependentLine("1 - Create new electricity meter", -4 * newLine, true, 5);
	Printer::PrintDependentLine("2 - Delete last electricity meter", -3 * newLine);
	Printer::PrintDependentLine("3 - Delete electricity meter by index", -2 * newLine);
	Printer::PrintDependentLine("4 - Set new kilowatt per hour cost", -1 * newLine);
	Printer::PrintDependentLine("5 - Open payment book", 0 * newLine);
	Printer::PrintDependentLine("6 - Delete payment book", 1 * newLine);
	Printer::PrintDependentLine("7 - Exit Program", 2 * newLine);

}
void PrintCreateMeterPage()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
	double min, max, value;
	string message;
	Printer::EraseConsole();
	message = "Program \"Payment Book\". Made by Piskarov Dmytro";
	Printer::PrintLine(message, -5 * newLine);
	message = "Enter the minimum value : ";
	Printer::PrintDependentLine(message, -4 * newLine, true, 5);
	message = "Enter the maximum value : ";
	Printer::PrintDependentLine(message, -3 * newLine);
	message = "Enter the value : ";
	Printer::PrintDependentLine(message, -2 * newLine);


	message = "Enter the minimum value : ";
	_coord = { (short)((bufferInfo.srWindow.Right / 2 + message.length() / 4 + 1) + (-4 * newLine.X)),
		(short)((bufferInfo.srWindow.Bottom / 2) + (-4 * newLine.Y)) };
	Printer::SetCursorPosition(_coord);
	ValidateInput(min);
	message = "Enter the maximum value : ";
	_coord = { (short)((bufferInfo.srWindow.Right / 2 + message.length() / 4 + 1) + (-3 * newLine.X)),
		(short)((bufferInfo.srWindow.Bottom / 2) + (-3 * newLine.Y)) };
	Printer::SetCursorPosition(_coord);
	ValidateInput(max);
	message = "Enter the value : ";
	_coord = { (short)((bufferInfo.srWindow.Right / 2 - 1 + (-2 * newLine.X))),
		(short)((bufferInfo.srWindow.Bottom / 2) + (-2 * newLine.Y)) };
	Printer::SetCursorPosition(_coord);
	ValidateInput(value);
	try
	{
		ElectricityMeter m(value, min, max);
		book.addMeter(m);
		writeFile();
	}
	catch (Exception exc)
	{
		Printer::PrintLine((string)exc.what() + " Action failed.", 3 * newLine);
		_getch();
	}
}
void DeleteLastMeterPage()
{
	Printer::EraseConsole();
	Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);
	if (book.getSize() != 0)
	{
		book.deleteMeter(book.getSize() - 1);
		Printer::EraseConsole();
		Printer::PrintLine("Last meter has been successfully deleted.", -3 * newLine);
		writeFile();
	}
	else
	{
		Printer::PrintLine("Can't delete the meter. The book is empty.", -3 * newLine);
	}
}
void DeleteLastMeterByIndexPage()
{
	Printer::EraseConsole();
	Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);
	if (book.getSize() != 0) {
		Printer::PrintLine("Enter the index of the meter to delete : ", -3 * newLine);
		string message = "Enter the index of the meter to delete : ";
		_coord = { (short)((bufferInfo.srWindow.Right / 2 + message.length() / 2) + (-3 * newLine.X)), //still didn't set correct cursor position to enter index
			(short)((bufferInfo.srWindow.Bottom / 2) + (-3 * newLine.Y)) };
		Printer::SetCursorPosition(_coord);
		int i;
		ValidateInput(i);
		if (book.getSize() >= i)
		{
			book.deleteMeter(i - 1); //Deletes element starting from 1st
			Printer::PrintLine("The meter has been successfully deleted", -2 * newLine);
			writeFile();
		}
		else
		{
			Printer::PrintLine("The meter with index " + to_string(i) + " does not exist.");
		}
	}
	else
	{
		Printer::PrintLine("Can't delete the meter. The book is empty.", -3 * newLine);
	}
}
void SetCostPage()
{
	Printer::EraseConsole();
	Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);

	Printer::PrintLine("Enter new cost : ", -3 * newLine);
	string message = "Enter new cost : ";
	_coord = { (short)((bufferInfo.srWindow.Right / 2 + message.length() / 3 + 3) + (-3 * newLine.X)),
		(short)((bufferInfo.srWindow.Bottom / 2) + (-3 * newLine.Y)) };
	Printer::SetCursorPosition(_coord);
	double cost;
	ValidateInput(cost);

	book.setKilowattHourCost(cost);
	writeFile();
	Printer::PrintLine("The cost has been successfully set.", -2 * newLine);

}
void PrintBookPage()
{
	Printer::EraseConsole();
	Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);

	if (book.getSize() > 0)
	{
		int i = 1, _i = -3;

		bool singleTab = true; // Needed to do single tab only one time
		for (auto it = book.begin(); it != book.end(); it++)
		{
			string m_value = to_string((*it).getValue()).erase(to_string((*it).getValue()).find_last_not_of('0') + 1);
			if (m_value.back() == '.') m_value.pop_back();
			string m_min = to_string((*it).getMinValue()).erase(to_string((*it).getMinValue()).find_last_not_of('0') + 1);
			if (m_min.back() == '.') m_min.pop_back();
			string m_max = to_string((*it).getMaxValue()).erase(to_string((*it).getMaxValue()).find_last_not_of('0') + 1);
			if (m_max.back() == '.') m_max.pop_back();
			string int_count = to_string((*it).getIntegralCount());
			/*to_string((*it).getIntegralCount()).erase(to_string((*it).getIntegralCount()).find_last_not_of('0') + 1);*/
			/*if (int_count.back() == '.') int_count.pop_back();*/
			string frac_count = to_string((*it).getFractionalCount());
			/*to_string((*it).getFractionalCount()).erase(to_string((*it).getFractionalCount()).find_last_not_of('0') + 1);*/
			/*if (frac_count.back() == '.') frac_count.pop_back();*/

			Printer::PrintDependentLine("Meter : " + to_string(i) + "\t\t Range : " + m_min + "..." + m_max + "\t\tValue : " + m_value
				+ "\t\tInt and frac count : " + int_count + "," + frac_count, _i * newLine, singleTab, -28);

			i++;
			_i++;
			singleTab = false;
		}

		singleTab = true;
		string cost = to_string(book.getKilowattHourCost()).erase(to_string(book.getKilowattHourCost()).find_last_not_of('0') + 1);
		if (cost.back() == '.') cost.pop_back();
		Printer::PrintDependentLine("Kilowatt per hour cost : " + cost, (_i + 1) * newLine, singleTab, -8);

		string consumed_energy = to_string(book.getAmountOfConsumedEnergy()).erase(to_string(book.getAmountOfConsumedEnergy()).find_last_not_of('0') + 1);
		if (consumed_energy.back() == '.') consumed_energy.pop_back();
		string total_cost = to_string(book.getCostOfConsumedEnergy()).erase(to_string(book.getCostOfConsumedEnergy()).find_last_not_of('0') + 1);
		if (total_cost.back() == '.') total_cost.pop_back();
		Printer::PrintDependentLine("Total amount of consumed energy: " + consumed_energy, (_i + 3) * newLine);
		Printer::PrintDependentLine("Total cost : " + total_cost + "\t\t\t\t\t\t\t\t\t\tLast payment date : " + book.getLastDate(), (_i + 4) * newLine);
	}
	else
	{
		Printer::PrintLine("The book is empty. ", -4 * newLine);
	}
}
void DeleteBookPage()
{
	bool action_performed = false;
	while (!action_performed) {
		Printer::EraseConsole();
		Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);
		if (book.getSize() != 0)
		{
			Printer::PrintLine("Write \"yes\" or \"no\" to confirm or cancel book deletion", -3 * newLine);
			Printer::PrintLine("NOTE : THIS OPTION DELETES BOOK FROM FILE", -2 * newLine);
			string option;
			cin >> option;
			if (option == "yes")
			{
				book.deleteBook();
				Printer::EraseConsole();
				Printer::PrintLine("Program \"Payment Book\". Made by Piskarov Dmytro", -5 * newLine);
				Printer::PrintLine("Book successfully deleted.", -4 * newLine);

				action_performed = true;
			}
			else if (option == "no")
			{
				action_performed = true;
			}
			else
			{
				Printer::PrintLine("Invalid input. Press any key to try again.", -1 * newLine);
				_getch();
			}
		}
		else
		{
			Printer::PrintLine("Book is already empty.", -4 * newLine);
			_getch();
			return;
		}
	}
}

bool readFile() // Reading meters.txt file
{
	fstream data_file;
	data_file.open("meters.txt", ios::in);
	if (data_file)
	{
		string line;
		getline(data_file, line);
		book.setKilowattHourCost(stod(line));
		getline(data_file, line);
		string date = line;
		while (getline(data_file, line))
		{
			string token;
			char* _line = new char[line.length()];
			strcpy(_line, line.data());

			token = strtok(_line, " ");
			double min = stod(token);
			token = strtok(NULL, " ");
			double max = stod(token);
			token = strtok(NULL, " ");
			double value = stod(token);

			ElectricityMeter m(value, min, max);
			book.addMeter(m);
		}
		book.setLastDate(date);
		data_file.close();
		return true;
	}
	else
		return false;
}
bool writeFile()
{
	fstream data_file;
	data_file.open("meters.txt", ios::out);
	if (!data_file)
		throw Exception("File is not opened!");
	else
	{
		data_file << book.getKilowattHourCost() << endl;
		data_file << book.getLastDate() << endl;
		for (auto it = book.begin(); it != book.end(); it++)
		{
			data_file << (*it).getMinValue() << " " << (*it).getMaxValue() << " " << (*it).getValue() << endl;
		}
	}
}

template <typename T>
void ValidateInput(T& value)
{
	while (true) {
		if (cin >> value)
			break;
		else
		{
			Printer::SetCursorPosition(_coord);
			cout << "Invalid input.";
			_getch();
			Printer::SetCursorPosition(_coord);
			cout << string(15, ' ');
			Printer::SetCursorPosition(_coord);
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}
COORD operator*(int i, const COORD& c)
{
	COORD result = { (short)i * c.X, (short)i * c.Y };
	return result;
}
COORD operator+(const COORD& c1, const COORD& c2)
{
	COORD result = { c1.X + c2.X, c1.Y + c2.Y };
	return result;
}