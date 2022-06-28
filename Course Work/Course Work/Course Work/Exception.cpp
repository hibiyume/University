#include "Exception.h"

const char* Exception::what()
{
	return message.data();
}
