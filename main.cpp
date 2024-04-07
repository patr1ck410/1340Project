#include <iostream>
#include "initialization.h"
#include "startgame.h"
#include <random>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
struct player{
	string name;
	double chips;
	bool ingame;
	int hand[][];
	double chipsput;
	bool allin;
	player *next;
};
	 
int main()
{
	ifstream data;
	data.open("lastgame.txt") // lastgame.txt saves last game details
	double poolsize;
	int playernum;
	bool newgame;
	if (data.fail()==False){    // lastgame.txt exists
		cout << "previous game dedected . Retrieve ? (1=Yes/0=No)" <<endl;
		bool ans;
		cin >> ans;
		if (ans==true){
			retrievegame();//not done
			newgame=false;
		}
	}
	if (newgame==false){
		cout << "Number of players?" << endl;
		cin >> playernum;
				 
	initializegame();
	startgame();
	Deck deck;
	deck.setupcards();
}
