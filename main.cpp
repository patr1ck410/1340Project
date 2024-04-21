#include <iostream>
#include "action.h"
#include "checkwin.h"
#include "drawcard.h"
#include "initialization.h"
#include "insert.h"
#include "loadandsave.h"
#include "output.h"
#include "structures.h"
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
	if (!data.fail()) // lastgame.txt exists
	{ 
		cout << "previous game dedected . Retrieve ? (1=Yes/0=No)" <<endl;
		bool ans;
		cin >> ans;
		if (ans==true){
			data.close();
			player * button = NULL, * tail= NULL;
			retrievegame(button, tail, playernum); //load lastgame's data into current game
			newgame=false;
			cout << "Lastgame retrived" << endl;
		}
		else
		{
			newgame = true;
			cout <<"Yo";
		}
	}
	cout << "Hello";
	player *button = NULL ,*tail =NULL;
	if (newgame)
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

	int seq[3]={3,1,1}; // for flop(3), river(1) and turn(1)
	int card[2]; // for temporary storage for the card draw from the deck
	while (ongoing){
		cout << "Game start";
		double poolsize=0;
		int playerinpool = playernum;
		int cardsremaining = 5;
		bool terminate = false;
		bool deck[4][13]; // set up the deck
		gamestart(deck, button); // reset the deck 
		distribute(deck, button, playernum); // for distributing two cards to each player
		int publiccard[5][2];
		int playerleft = playernum;
		action(button, poolsize, playernum, playerleft, terminate, true);
		if (terminate){
			for (int j=0 ; j < 5 ; j++){ // draw all the public cards if terminate = true	
      				cardDraw(deck, card);
     	 			publiccard[j][0] = card[0];
      				publiccard[j][1] = card[1];
			}
			showpublic(publiccard,5); // show all public card
		}
		else{
			for (int i=0;i<3;i++){ // for 3 action (flop, river, turn)
				for (int j=0 ;j < seq[i];j++){  // as seq = {3,1,1} so flop, river and turn
					cardDraw(deck, card);
					publiccard[5-cardsremaining][0] = card[0];
					publiccard[5-cardsremaining][1] = card[1];
					cardsremaining-=1;
				}
				showpublic(publiccard,5-cardsremaining);
				action(button,poolsize,playernum,playerleft,terminate,false);
				if (terminate){
					for (int j=(5-cardsremaining) ; j < 5 ; j++){ // draw all the public cards if terminate = true	
      						cardDraw(deck, card);
     	 					publiccard[j][0] = card[0];
      						publiccard[j][1] = card[1];
					}
					showpublic(publiccard,5);
					break;
				}
			}
		}
		checkwin(button, publiccard);
		button=button->next;
		cout <<"Contiune playing? (1:Yes, 0: No)"; //ask quit game or not
		int quitoption;
		cin >> quitoption;		//if quit, set ongoing = false
		if (quitoption == 1)
		{
			ongoing = false;
		}
	}
	savegame(button, tail);
	cout << "Game saved suscessfully, BYE" << endl;
	return 0;
}
