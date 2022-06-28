#pragma once

#include <iostream>

using namespace std;

class Exception : public exception
{
private:
	std::string message;
public:
	Exception(std::string message) : message(message) {};

	const char* what();
};

