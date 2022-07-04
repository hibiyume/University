#pragma once

#include <iostream>

using namespace std;

class GameGenre
{
protected:
	string description;		// Genre description
	float popularity_score; // Genre popularity
	float difficulty_score;	// Difficulty for the player

public:
	string getDescription();
	float getPopularity();
	float getDifficulty();

	virtual void printGenre() = 0;
	void setDescription(string description);
	void setPopularity(float popularity_score);
	void setDifficulty(float difficulty_score);
};

