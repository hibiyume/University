#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

#include "Exception.h"
#include "Meter.h"

using namespace std;

class Printer
{
private:
	Printer() {}; // Disallow creating an instance of this object

	static HANDLE handle;
	static CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	static vector<COORD> allocatedLines;
public:
	static void SetFullScreen();
	static void EraseConsole();
	
	static void PrintLine(string message, COORD coord = {0, 0}, bool isCentered = true);
	static void PrintDependentLine(string message, COORD coord = { 0, 0 }, bool singleTab = false, int singleTapSize = 0);
	static void PrintBookPage(Meter& m, COORD coord = {0, 0}, bool isCentered = true);
	static void SetCursorPosition(COORD coord);
};

