#pragma once

#include <iostream>

#include "MOBA.h"
#include "FPS.h"

using namespace std;

class Game : public MOBA, public FPS
{
protected:
	string name;
	string genre;
	float price;
	float hours;

	bool isInstalled;

	bool hasDiscount;
	int percent;
	float price_wt_discount;

public:
	Game(string name, string genre, float price, float hours);
	Game(const Game& game);

	string getName();
	string getGenre();
	float getPrice();
	float getHours();

	void setName(string name);
	void setGenre(string genre);
	void setPrice(float price);
	void setHours(float hours);

	void makeDiscount(int percent); // Decreases game price
	void removeDiscount();			// Increases game price
	void install();					// Installes game on the computer
	void uninstall();				// Deletes game from computer

	friend ostream& operator<<(ostream& os, const Game& game);
};

