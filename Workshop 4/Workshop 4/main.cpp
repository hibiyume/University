#include <iostream>

#include "Game.h"

using namespace std;

int main()
{
	Game games[5]
	{
		Game("League of Legends", "MOBA", 0, 123.5),
		Game("Battlefield 4", "Shooter-FPS", 39.99, 385.64),
		Game("Call of Duty Modern Warfare", "Shooter-FPS", 29.99, 66.6),
		Game("Warframe", "Shooter-MOBA", 0, 114.2),
		Game("S.T.A.L.K.E.R.", "Shooter-FPS", 14.99, 53),
	};

	for (int i = 0; i < 5; i++)
	{
		cout << games[i] << endl;
	}
}