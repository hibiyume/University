#include "Game.h"

Game::Game(string name, string genre, float price, float hours)
	: name(name), price(price), genre(genre), hours(hours), price_wt_discount(price), isInstalled(false),
	  hasDiscount(false), percent(0) {}
Game::Game(const Game& game)
	: name(game.name), genre(game.genre), price(game.price), hours(game.hours), isInstalled(game.isInstalled),
	  hasDiscount(game.hasDiscount), price_wt_discount(game.price_wt_discount) {}

string Game::getName()
{
	return name;
}
string Game::getGenre()
{
	return genre;
}
float Game::getPrice()
{
	return price;
}
float Game::getHours()
{
	return hours;
}

void Game::setName(string name)
{
	this->name = name;
}
void Game::setGenre(string genre)
{
	this->genre = genre;
}

void Game::setPrice(float price)
{
	this->price = price;
}
void Game::setHours(float hours)
{
	this->hours = hours;
}

void Game::makeDiscount(int percent)
{
	this->percent = percent;

	//Rounding discount to cool number (14.97 -> 14.99; 14.45 -> 14.49);
	float intg, frac;
	frac = modf(this->price, &intg);
	
	if (frac < 0.5) frac = 0.49;
	else frac = 0.99;

	intg = intg - round(intg / 100 * percent);
	this->price = intg + frac;
	hasDiscount = true;
}
void Game::removeDiscount()
{
	this->price = price_wt_discount;
	hasDiscount = false;
}
void Game::install()
{
	isInstalled = true;
}
void Game::uninstall()
{
	isInstalled = false;
}

ostream& operator<<(ostream& os, const Game& game)
{
	cout << game.name << endl;
	cout << game.genre << endl;

	if (game.hasDiscount)
	{
		if (game.price != 0)
			cout << "Price : \t" << game.price << "$ " << "(-" << game.percent << "%)" << endl;
		else
			cout << "Price : \tfree to play (promotion)" << endl;
	}
	else
	{
		if (game.price != 0)
			cout << "Price : \t" << game.price << "$" << endl;
		else
			cout << "Price : \tfree to play" << endl;
	}

	game.isInstalled ? cout << "Installed" << endl : cout << "Not Installed" << endl;
	cout << "Time played : \t" << game.hours << " hrs" << endl;

	return os;
}