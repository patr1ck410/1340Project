#include <iostream>
#include "action.h"
#include "checkwin.h"
#include "drawcard.h"
#include "initialization.h"
#include "insert.h"
#include "loadandsave.h"
#include "minigame.h"
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

	ifstream data; // lastgame.txt saves last game details
	double poolsize;
	int playernum = 0;
	bool newgame = true;
	player *button = NULL, *tail = NULL;
	if (checkempty("lastgame.txt"))
	{ // lastgame.txt exists
		cout << "Did you save the game last time?" << endl;
		cout << "Retrieve? (1 = Yes / 0 = No)" << endl;
		bool ans;
		cin >> ans;
		if (ans == true)
		{
			retrievegame(button, tail, playernum); // not done
			newgame = false;
		}
	}
	if (newgame)
	{
		bool flag = false; // for input playeernum , re-input if <4
		do
		{
			cout << "Number of players? (>=4)" << endl;
			cin >> playernum;
			if (playernum < 4)
				cout << "Invalid input! Please input the number of players again. " << endl;
			else
				flag = true;
		} while (!flag); // restricting playernum has to >4

		/*
		need to set playernumber limit
		*/
		for (int i = 0; i < playernum; i++)
		{
			cout << "Input Player " << i + 1 << " name: ";
			string name;
			cin >> name;
			bool lastplayer = (i == (playernum - 1));
			appendplayer(button, tail, name, lastplayer); // for input player info in struct
		}
	}
	bool ongoing = true;   // boolean in game status
	int seq[] = {3, 1, 1}; // for flop(3), river(1) and turn(1)
	int card[2];		   // for temporary storage for the card draw from the deck
	while (ongoing)
	{
		double poolsize = 0;
		int cardsremaining = 5; // tracking number of cards not dealed
		bool allfold = false;
		bool terminate = false;				 // boolean value for
		bool deck[4][13];					 // set up the deck
		gamestart(deck, button, tail);		 // reset the deck
		distribute(deck, button, playernum); // for distributing two cards to each player
		int publiccard[5][2];
		int playerinpool = playernum; // player that still  have actions , i.e. not fold or have not all in
		int playerleft = playernum;	  // onlyfor not have fold
		action(button, poolsize, playernum, playerinpool, terminate, true, allfold, playerleft);
		if (allfold)
		{
			continue;
			button = button->next;
		}
		if (terminate)
		{
			for (int j = 0; j < 5; j++)
			{ // draw all the public cards if terminate = true
				cardDraw(deck, card);
				publiccard[j][0] = card[0];
				publiccard[j][1] = card[1];
			}
			showpublic(publiccard, 5); // show all public card
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{ // for 3 action (flop, river, turn)
				for (int j = 0; j < seq[i]; j++)
				{ // as seq = {3,1,1} so flop, river and turn
					cardDraw(deck, card);
					publiccard[5 - cardsremaining][0] = card[0];
					publiccard[5 - cardsremaining][1] = card[1];
					cardsremaining -= 1;
				}
				showpublic(publiccard, 5 - cardsremaining);
				action(button, poolsize, playernum, playerinpool, terminate, false, allfold, playerleft);
				if (allfold)
					break;
				if (terminate)
				{
					for (int j = (5 - cardsremaining); j < 5; j++)
					{ // draw all the public cards if terminate = true
						cardDraw(deck, card);
						publiccard[j][0] = card[0];
						publiccard[j][1] = card[1];
					}
					showpublic(publiccard, 5);
					break;
				}
			}
		}
		button = button->next;
		if (allfold)
			continue;
		checkwin(button, publiccard, poolsize);
		int temp;
		// temp = minigame(); //when player do not have enough chips to continue
		cout << "Continue playing? (1: Yes / 0: No)"; // ask quit game or not
		int quitoption;
		cin >> quitoption; // if quit, set ongoing = false
		while (quitoption > 1 || quitoption < 0)
		{
			cout << "Invalid choice! Please choose again." << endl;
			cin >> quitoption;
		}
		if (quitoption == 0)
		{
			ongoing = false;
		}
	}
	savegame(button);
	cout << "Game saved successfully, BYE!!" << endl;
	return 0;
}
