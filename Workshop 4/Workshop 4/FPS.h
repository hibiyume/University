#pragma once

#include "Shooter.h"
#include "War.h"

class FPS : protected Shooter, protected War
{
public:
	static string get_FPS_examples();
	void printGenre();
};
