#pragma once

#include "GameGenre.h"

class Shooter : public GameGenre
{
public:
	static string get_shooters_examples();
	void printGenre();
};
