#include <iostream>
#include "initialization.h"
#include "insert.h"
#include "structures.h"
#include "retrieve.h"
#include <random>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
// the definination of player is now defined in "structures.h"
	 
int main()
{
	ifstream data;
	data.open("lastgame.txt"); // lastgame.txt saves last game details
	double poolsize;
	int playernum;
	bool newgame=false;
	if (data.fail()==false){    // lastgame.txt exists
		cout << "previous game dedected . Retrieve ? (1=Yes/0=No)" <<endl;
		bool ans;
		cin >> ans;
		if (ans==true){
			data.close();
			player playerlist;
			retrievegame(playerlist, playernum);//not done
			newgame=true;
		}
	}
	player *head = NULL , *tail=NULL;
	if (newgame==true){
		cout << "Number of players?" << endl;
		cin >> playernum;
		/*
		need to set playernumber limit
		*/
		for (int i=0;i<playernum;i++)
			cout << "Input Player " << i << "name: " ;
			string name;
			cin >> name;
			bool lastplayer = ( i == (playernum-1));
			appendplayer(head,tail,name,lastplayer); // for input player info in struct 
		}
	bool ongoing=true;
	while (ongoing){
		double poolsize=0;
		int playerinpool=playernum;
		int cardsremianing =5;
		int deck[4][13];
		gamestart(deck); // deck is ready 
		distribute(); // for distributing two cards
		action();// for player action
		for (int i =0 ;i<3 ; i++)
			flop();// for fkop cards
		
		
		
	}
}
