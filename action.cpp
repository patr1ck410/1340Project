#include<iostream>
#include "action.h"
#include "structures.h"
using namespace std;
void action (player *button , double &poolsize ,int playernum )
{
	bool endturn=false;
	player * current= button;
	double max=0;
	while (!endturn )
	{
		if (current -> ingame == false || current -> allin == true)
		{
			current = current -> next ;
			continue; // pass to next player if the player has all in or fold
		} 
		cout << "It's " << current->name << "'s turn . Choose an action below:" << endl;
		cout << " 1. Check or call"  << endl;
		cout << " 2. Bet " << endl;
		cout << " 3. Fold " << endl;
		cout <<  " Dead chips : " << current-> chipsput << "chips remaining : " << current -> chips <<endl;
		int opt;
		cin >> opt;
		bool check = false;
		while (!check) // validate the action, incorrect then input again
		{ 
			while (opt > 1 || opt < 3)
			{
				cout <<"Invalid choice . Please choose again. " << endl;
				cin >> opt;
				continue;
			}
			if (opt == 2)
			{
				cout << "input bet size" <<endl;
				double betsize;
				cin >> betsize ;
				if (betsize < max *2 || betsize > current ->chips)
				{
					cout << " Invalid betsize , please input your choice again :" <<endl;
					cin >> opt;
					continue;
				}
				check = true; 
			}
			if (opt==1)
			{
				int diff = max - current-> chipsput;
				if (diff >= max)
				{
					current -> allin = true;
					current -> chipsput += current -> chips;
					current -> chips = 0; // allin if chips remaining is not enough 
				}
				else
				{
					current -> chipsput += diff;
					current -> chips-=diff;
				}
			}
			else if (opt==2)
			{
				max = betsize;
				current -> chips = current -> chips - (betsize- current->chipsput);
				current -> chipsput = betsize;
			}
			else 
				current->ingame =false;
			player * check = button;
			endturn == true;
			for (int i = 0 ; i < playernum ; i++) // check if all players have put same amount of chips (max) , or have all in 
			{ 
				if (current -> ingame == true && current-> allin == false && current -> chipsput< max )
				{
					endturn=false;
					break;
				}
			}		
		}
	}
	player * current=button;
	for (int i = 0 ; i < playernum ; i++)
	{
		poolsize += current->chipsput;
		current->chipsput=0; // initilize chipsput
		current= current -> next;
	}

}