#include "Printer.h"

vector<COORD> Printer::allocatedLines = { {-1, -1} };

HANDLE Printer::handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO Printer::bufferInfo;

bool operator==(const COORD& c1, const COORD& c2)
{
	return (c1.X == c2.X && c1.Y == c2.Y);
}

void Printer::SetFullScreen()
{
	SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //pressing ALT+ENTER programmatically
}
void Printer::EraseConsole()
{
	allocatedLines.clear();
	allocatedLines.push_back({ -1, -1 });

	system("CLS");
}

void Printer::PrintLine(string message, COORD coord, bool isCentered)
{
	COORD _coord;
	if (isCentered)
	{
		GetConsoleScreenBufferInfo(handle, &bufferInfo);
		_coord = { (short)(((bufferInfo.srWindow.Right - message.length()) / 2) + coord.X), (short)((bufferInfo.srWindow.Bottom / 2) + coord.Y) };
	}

	bool allocated = false;
	for (COORD value : allocatedLines)
	{
		if (_coord.Y == value.Y)
		{
			allocated = true;
			break;
		}
	}

	if (!allocated)
	{
		SetConsoleCursorPosition(handle, _coord);
		cout << message;
		allocatedLines.push_back(_coord);

		Printer::SetCursorPosition({ _coord.X, (short)(_coord.Y + 2) });
	}
	else
		throw Exception("Exception : Printing text on allocated line.");
}
void Printer::PrintDependentLine(string message, COORD coord, bool singleTab, int singleTabSize)
{
	GetConsoleScreenBufferInfo(handle, &bufferInfo);

	COORD _coord = { ((bufferInfo.srWindow.Right - message.length()) / 2) + coord.X, (bufferInfo.srWindow.Bottom / 2) + coord.Y };

	COORD closest_line = { 0, 0 };
	for (COORD value : allocatedLines)
	{
		if (value.Y > closest_line.Y)
			closest_line = value;
	}
	if (singleTab)
		_coord.X = closest_line.X + singleTabSize;
	else
		_coord.X = closest_line.X;

	bool allocated = false;
	for (COORD value : allocatedLines)
	{
		if (_coord.Y == value.Y)
		{
			allocated = true;
			break;
		}
	}

	if (!allocated)
	{
		SetConsoleCursorPosition(handle, _coord);
		cout << message;
		allocatedLines.push_back(_coord);

		Printer::SetCursorPosition({ _coord.X, (short)(_coord.Y + 2) });
	}
	else
		throw Exception("Exception : Printing text on allocated line.");
}
void Printer::PrintBookPage(Meter& m, COORD coord, bool isCentered)
{
	if (find(allocatedLines.begin(), allocatedLines.end(), coord) == allocatedLines.end() && allocatedLines.back().Y != coord.Y)
	{
		GetConsoleScreenBufferInfo(handle, &bufferInfo);
		string message;
		if (isCentered) {
			// First line
			string value = to_string(m.getValue());
			value.erase(value.find_last_not_of('0') + 1);
			if (value.back() == '.')
				value.pop_back();
			message = "Current Value : " + value;
			PrintLine(message, coord);

			// Second line
			string minValue = to_string(m.getMinValue());
			string maxValue = to_string(m.getMaxValue());
			minValue.erase(minValue.find_last_not_of('0') + 1);
			maxValue.erase(maxValue.find_last_not_of('0') + 1);
			if (minValue.back() == '.')
				minValue.pop_back();
			if (maxValue.back() == '.')
				maxValue.pop_back();
			message = "Value's Range : " + minValue + "..." + maxValue;
			PrintDependentLine(message, { coord.X, (short)(coord.Y + 2) });
		}
		else
		{
			cout << "Current Value : " << m.getValue() << endl;
			cout << "Value's Range : " << m.getMinValue() << "..." << m.getMaxValue() << endl;
		}
	}
	else
	{
		throw Exception("Exception : Printing text on allocated line.");
	}
}
void Printer::SetCursorPosition(COORD coord)
{
	SetConsoleCursorPosition(handle, coord);
}