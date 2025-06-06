#include "Game.h"

/*
When initialised sets the name and hours played to the values entered
*/
Game::Game(string name, int hoursPlayed) {
	this->name = name; //inserts the inputted name into the name variable
	this->hoursPlayed = hoursPlayed; //inserts the inputted time into the hoursPlayed variable
}