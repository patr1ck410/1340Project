#include <iostream>
#include "action.h"
#include "structures.h"
#include "output.h"
using namespace std;
void action(player *button, double &poolsize, int playernum, int &playerinpool, bool &terminate, bool first, bool &allfold, int &playerleft, int publiccard[5][2], int& turn)
{
	bool endturn = false;
	player *current, *last;
	double max;
	if (first)
	{
		current = button->next->next->next; // the one next to big blind start first
		last = current;						// for stroing the last player for endturn
		max = 1;
		button->next->chipsput = 0.5; // antecedent
		button->next->chips -= 0.5;
		button->next->next->chipsput = 1;
		button->next->next->chips -= 1;
	}
	else
	{
		current = button->next; // small blind action first
		max = 0;
		last = current;
	}
	while (!endturn)
	{
		if (current->ingame == false || current->allin == true)
		{
			current = current->next;
			continue; // pass to next player if the player has all in or fold
		}
		cout << "\n";
		cout << "\n";
		cout << "Now, it is " << current->name << "'s turn!!!" << endl; // user-menu
		cout << "\n";
		cout << "Current pool size: " << poolsize << endl;
		cout << "Your Dead chips: " << current->chipsput << endl;
		cout << "Chips remaining: " << current->chips << endl;
		double diff = max - current->chipsput;
		cout << "Chips to call :" << diff << endl;
		cout << "\n";
		showhand(current); // user-menu
		cout << "Please choose an action below:" << endl;
		cout << "\n";
		cout << "turn" << turn << endl;
		if (turn < playernum)
		{
			cout << "\t1. Check or call" << endl;
			cout << "\t2. Bet" << endl;
			cout << "\t3. Fold" << endl;
			cout << "\n";
			turn += 1;
		}
		else
		{
			cout << "\t1. Check or call" << endl;
			cout << "\t2. Bet" << endl;
			cout << "\t3. Fold" << endl;
			cout << "\t4. Show community card" << endl;
			cout << "\n";
			turn ++;
		}
		bool check = false;
		double betsize;
		int opt;
		cin >> opt;
		while (!check) // validate the action, incorrect then input again
		{
			if (turn < playernum)
			{
				while (opt > 3 || opt < 1)
				{
					cout << "Invalid choice! Please choose your action again:" << endl;
					cin >> opt;
					continue;
				}
			}
			else if (turn >= playernum)
			{
				while (opt > 4 || opt < 1)
				{
					cout << "Invalid choice! Please choose your action again:" << endl;
					cin >> opt;
					continue;
				}
			}
			if (opt == 2)
			{
				cout << "Input bet size: " << endl;
				cin >> betsize;
				if ((betsize < max * 2 && betsize!=current->chips || betsize > current->chips ) // wrong betsize
				{
					cout << "Invalid betsize! Please choose your action again:" << endl;
					cin >> opt;
					continue;
				}
			}
			check = true;
		}
		if (opt == 1)
		{
			if (diff >= current->chips)
			{
				current->allin = true;
				current->chipsput += current->chips;
				current->chips = 0; // allin if chips remaining is not enough
				playerinpool -= 1;
			}
			else
			{
				current->chipsput += diff;
				current->chips -= diff;
			}
		}
		else if (opt == 2) // raise
		{
			last = current;
			max = betsize;
			current->chips = current->chips - (betsize - current->chipsput);
			current->chipsput = betsize;
			if (current->chips == 0) // allin
			{
				current->allin = true;
				playerinpool -= 1;
			}
		}
		else if (opt == 3) // fold
		{
			current->ingame = false;
			playerleft -= 1;
			playerinpool -= 1;
		}
		else if (opt == 4) // show community card
		{	
			turn--;
			showpublic(publiccard, 2 + turn/playernum); // turn/playernum will get which round in the match, then can know how many card should be shown
			continue;
		}
		current = current->next;
		if (last == current)
			endturn = true;
	}
	current = button;
	for (int i = 0; i < playernum; i++) // storing sidepool size for player who has all in
	{
		if (current->allin == true)
		{
			double size = current->chipsput;
			double reward = poolsize;
			player *individual = button;
			for (int i = 0; i < playernum; i++)
			{
				if (individual->chipsput >= size)
					reward += size;
				else
					reward += individual->chipsput;
				individual = individual->next;
			}
			current->sidepool = reward;
		}
	}
	for (int i = 0; i < playernum; i++) // adding dead chips to the pool
	{
		poolsize += current->chipsput;
		current->chipsput = 0; // initilize chipsput
		current = current->next;
	}
	if (playerleft == 1)
	{ // detects if everyone fold;
		giverewards(button, poolsize);
		allfold = true;
	}
	else if (playerinpool == 1) // one one has not fold and all in
	{
		terminate = true;
	}
}
void giverewards(player *button, double poolsize)
{
	player *current = button;
	do
	{
		if (current->ingame == true)
		{
			current->chips += poolsize; // give rewards to the player not flod if anyone else has fold
			cout << "Player " << current->name << " wins " << poolsize << endl;
			cout << "Current chips of the player: " << current->chips << endl;
			break;
		}
		current = current->next;
	} while (current != button);
}
