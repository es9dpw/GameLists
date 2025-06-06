#include "Dropped.h"

/*
When the hash table is inititalised the hash table's size is set
*/
Dropped::Dropped(int size) {
	this->size = size; //sets the size variable of the hash table to the size entered
	data = new Game* [size]; //creates the hash table with the size entered
	for (int i = 0; i < size; i++) { //loops through every element of the has table
		data[i] = NULL; //sets each element in the hash table to null
	}
}

/*
Displays the hash table
*/
void Dropped::Display() {
	for (int i = 0; i < size; i++) { //loops through every element of the has table
		if (data[i] != NULL) { //checks if the current element is not null
			cout << data[i]->name << ", " << data[i]->hoursPlayed << "h" << endl; //displays the name of the game and the time played
		}
	}
}

/*
Inserts a new game into the hash table
*/
void Dropped::Insert(Game* item) {
	string key = item->name; //sets the key to the name of the game
	int hash = HashFunction(key); //calls the hash function to calculate the hash
	while (data[hash] != NULL) { //checks if the current element already contains data 
		++hash; //increments hash by 1
		hash %= size; //divides hash by size and takes the remainder, then sets hash to this remainder
	}
	data[hash] = item; //sets the current element to the game entered
}

/*
Calculates the hash for storing a game using the game names's ascii value and the size of the hash table
*/
int Dropped::HashFunction(string key) {
	int asciiValue = 0; //sets current ascii value to 0
	for (int i = 0; i < key.length(); i++) { //loops 1 time for each character in the game name
		asciiValue = asciiValue + int(key[i]); //finds the ascii value of each character in the game name and adds them together
	}
	return asciiValue % size; //returns the remainder of the final ascii value divided by the hash table size
}

/*
Finds a game in the hash table
*/
Game* Dropped::Find(string key) {
	int hash = HashFunction(key); //calls the hash function to calculate the hash
	while (data[hash] != NULL) { //checks if the current element already contains data 
		if (data[hash]->name == key) { //checks if the current element is the same game as the one entered
			return data[hash]; //returns the current element
		}
		++hash; //increments hash by 1
		hash %= size; //divides hash by size and takes the remainder, then sets hash to this remainder
	}
	return NULL; //returns null if the game wasn't found
}

/*
Deletes a game in the hash table
*/
Game* Dropped::Delete(string key) {
	int hash = HashFunction(key); //calls the hash function to calculate the hash
	while (data[hash] != NULL) { //checks if the current element already contains data 
		if (data[hash]->name == key) { //checks if the current element is the same game as the one entered
			Game* temp = data[hash]; //creates a tempoary game pointer to store the game that will be deleted
			data[hash] = NULL; //sets the current element to null
			return temp; //returns the deleted game
		}
		++hash; //increments hash by 1
		hash %= size; //divides hash by size and takes the remainder, then sets hash to this remainder
	}
	return NULL; //returns null if the game wasn't found
}