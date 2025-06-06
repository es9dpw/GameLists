#include "Link.h"

/*
When initialised sets the data of the link to an existing game object
*/
Link::Link(Game* data) {
	this->data = data; //sets the link's data to an existing game object
}

/*
Displays the game name and play time if there is any
*/
void Link::Display() {
	if (data->hoursPlayed > 0) { //checks if the game has any play time on it
		cout << data->name << " (played previously for " << data->hoursPlayed << "h)" << endl; //displays the game name and play time
	}
	else {
		cout << data->name << endl; //displays only the game name
	}
}

/*
Returns the game object stored in the link
*/
Game* Link::GetData() {
	return data; //returns the game object
}