#include <iostream>
#include "action.h"
#include "initialization.h"
#include "insert.h"
#include "structures.h"
#include "loadandsave.h"
#include "drawcard.h"
#include <random>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
// the definition of player is now defined in "structures.h"

int main()
{
	ifstream data;
	data.open("lastgame.txt"); // lastgame.txt saves last game details
	double poolsize;
	int playernum = 0;
	bool newgame=false;
	if (data.fail()==false){    // lastgame.txt exists
		cout << "previous game dedected . Retrieve ? (1=Yes/0=No)" <<endl;
		bool ans;
		cin >> ans;
		if (ans==true){
			data.close();
			player * button = NULL, * tail= NULL;
			retrievegame(button, tail, playernum);
			newgame=false;
		}
		else
		{
			newgame = true;
		}
	}
	player *button = NULL ,*tail =NULL;
		if (newgame==true)
		{
			cout << "Number of players?" << endl;
			cin >> playernum;
			/*
			need to set playernumber limit
			*/
			for (int i=0;i<playernum;i++){
				cout << "Input Player " << i << "name: " ;
				string name;
				cin >> name;
				bool lastplayer = ( i == (playernum-1));
				appendplayer(button,tail ,name,lastplayer); // for input player info in struct 
			}
		}
	bool ongoing=true;
	int seq[3]=[3,1,1];
	while (ongoing){
		double poolsize=0;
		int playerinpool=playernum;
		int cardsremianing =5;
		bool terminate=false;
		bool deck[4][13];
		gamestart(deck, button); // deck is ready 
		distribute(deck, button, playernum); // for distributing two cards
		int publiccard[5][2];
		int playerleft=playernum;
		action(button,poolsize,playernum,playerleft,terminate);
		for (int i=0;i<3;i++){
			if (terminate){
				break;
			}
		
		
		
	}
}
