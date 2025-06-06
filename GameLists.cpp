#include <iostream>
#include "Game.h"
#include "Link.h"
#include "Node.h"
#include "ToPlay.h"
#include "Completed.h"
#include "Dropped.h"

using namespace std;

int main()
{
	bool menuExit = false;
	string menuOption;
	string listOption;
	int time;
	string name;
	string alreadyTime;
	Link* dlink = nullptr;
	Game* dgame = NULL;

	//creating each data structure
	ToPlay* toPlay = new ToPlay();
	Completed* completed = new Completed();
	Dropped* dropped = new Dropped(100);

	//inserting games into each data structure
	toPlay->Insert(new Link(new Game("Bloodborne", 0)));
	toPlay->Insert(new Link(new Game("Halo", 4)));
	toPlay->Insert(new Link(new Game("Control", 0)));
	toPlay->Insert(new Link(new Game("Stray", 0)));

	completed->Insert(new Game("Bioshock", 51));
	completed->Insert(new Game("Undertale", 27));
	completed->Insert(new Game("Subnautica", 46));
	completed->Insert(new Game("Bioshock", 7));

	dropped->Insert(new Game("Hitman", 8));
	dropped->Insert(new Game("DOOM", 13));
	dropped->Insert(new Game("Infamous", 3));
	dropped->Insert(new Game("Borderlands", 2));

	//setting up a loop until program exit
	while (menuExit == false) {
		//displaying menu and taking user option
		cout << "Game List Menu:" << endl;
		cout << "1. Display to play list" << endl;
		cout << "2. Display completed list" << endl;
		cout << "3. Display dropped list" << endl;
		cout << "4. Display all lists" << endl;
		cout << "5. Add game into To Play list" << endl;
		cout << "6. Add game into Completed list" << endl;
		cout << "7. Add game into Dropped list" << endl;
		cout << "8. Remove game from To Play list" << endl;
		cout << "9. Remove game from Dropped list" << endl;
		cout << "10. Exit" << endl;
		cout << endl;
		cout << "Enter the number of your option: ";
		cin >> menuOption;
		cout << endl;

		if (menuOption == "1") {
			cout << "To Play:" << endl;
			//display the toPlay linked list
			toPlay->Display();
			cout << endl;
		}

		else if (menuOption == "2") {
			cout << "Completed:" << endl;
			//display the completed tree
			completed->DisplayInOrder((*completed).root);
			cout << endl;
		}

		else if (menuOption == "3") {
			cout << "Dropped:" << endl;
			//display the dropped hash table
			dropped->Display();
			cout << endl;
		}

		else if (menuOption == "4") {
			//display all 3 data structures
			cout << "To Play:" << endl;
			toPlay->Display();
			cout << endl;
			cout << "Completed:" << endl;
			completed->DisplayInOrder((*completed).root);
			cout << endl;
			cout << "Dropped:" << endl;
			dropped->Display();
			cout << endl;
		}

		else if (menuOption == "5") {
			cout << "Enter the name of the game: ";
			cin >> name;
			cout << "Do you already have time in the game? yes or no: ";
			cin >> alreadyTime;
			if (alreadyTime == "yes") {
				cout << "Enter the hours you have in the game: ";
				cin >> time;
			}
			else {
				time = 0;
			}
			//Inserting a game into the toPlay linked list
			toPlay->Insert(new Link(new Game(name, time)));
			cout << "Game added" << endl;
			cout << endl;
		}

		else if (menuOption == "6") {
			cout << "Enter the name of the game: ";
			cin >> name;
			cout << "Enter the hours you have in the game: ";
			cin >> time;
			//Inserting a game into the completed tree
			completed->Insert(new Game(name, time));
			cout << "Game added" << endl;
			cout << endl;
		}

		else if (menuOption == "7") {
			cout << "Enter the name of the game: ";
			cin >> name;
			cout << "Enter the hours you have in the game: ";
			cin >> time;
			//Inserting a game into the dropped hash table
			dropped->Insert(new Game(name, time));
			cout << "Game added" << endl;
			cout << endl;
		}

		else if (menuOption == "8") {
			cout << "Enter the name of the game to remove: ";
			cin >> name;
			//Deleting a game from the toPlay linked list, or returning a message if it doesn't exist
			dlink = toPlay->Delete(name);
			if (dlink == nullptr) {
				cout << "Game not in list" << endl;
			}
			else {
				cout << "Game removed" << endl;
			}
			cout << endl;
		}

		else if (menuOption == "9") {
			cout << "Enter the name of the game to remove: ";
			cin >> name;
			//Deleting a game from the dropped hash table, or returning a message if it doesn't exist
			dgame = dropped->Delete(name);
			if (dgame == NULL) {
				cout << "Game not in list" << endl;
			}
			else {
				cout << "Game removed" << endl;
			}
			cout << endl;
		}

		else if (menuOption == "10") {
			menuExit = true;
		}

		else {
			cout << "Inavlid option, try again" << endl;
			cout << endl;
		}
	}
}