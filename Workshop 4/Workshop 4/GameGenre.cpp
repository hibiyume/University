#include "GameGenre.h"

string GameGenre::getDescription()
{
	return description;
}
float GameGenre::getPopularity()
{
	return popularity_score;
}
float GameGenre::getDifficulty()
{
	return difficulty_score;
}

void GameGenre::setDescription(string description)
{
	this->description = description;
}
void GameGenre::setPopularity(float popularity_score)
{
	this->popularity_score = popularity_score;
}
void GameGenre::setDifficulty(float difficulty_score)
{
	this->difficulty_score = difficulty_score;
}