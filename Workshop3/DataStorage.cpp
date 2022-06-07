#include "DataStorage.h"

DataStorage::~DataStorage()
{

}

double DataStorage::getSize()
{
	return size;
}
void DataStorage::setSize(double size)
{
	this->size = size;
}

string DataStorage::getName()
{
	return name;
}
void DataStorage::setName(string name)
{
	this->name = name;
}
