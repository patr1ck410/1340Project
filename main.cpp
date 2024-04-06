#include <iostream>
#include "initialization.h"
#include "startgame.h"
#include <random>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
struct 
int main()
{
	ifstream data;
	data.open("lastgame.txt") // lastgame.txt saves last game details
	double poolsize;
	int numbernum;
	if (data.fail()==False){    // lastgame.txt exists
		cout << "previous game dedected . Retrieve ? (1=Yes/0=No)" <<endl;
		bool ans;
		cin >> ans;
		if (ans==true)
			retrievegame();//not done
	}
			 
	initializegame();
	startgame();
	Deck deck;
	deck.setupcards();
}
