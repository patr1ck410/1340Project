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
	bool newgame=false;
	if (data.fail()==false){    // lastgame.txt exists
		cout << "previous game dedected . Retrieve ? (1=Yes/0=No)" <<endl;
		bool ans;
		cin >> ans;
		if (ans==true){
			retrievegame();//not done
			newgame=true;
		}
	}
	player *head = NULL , *tail=NULL;
	if (newgame==true){
		cout << "Number of players?" << endl;
		cin >> playernum;
		for (int i=0;i<playernum;i++)
			cout << "Input Player " << i << "name: " ;
			string name;
			cin >> name;
			appendplayer(head,tail,name); // for input player info in struct 
		}
	bool ongoing=true;
	while (ongoing){
		int deck[4][13];
		gamestart(deck,); // deck is ready 
		distribute(); // for distributing two cards
		
		
	}
}
