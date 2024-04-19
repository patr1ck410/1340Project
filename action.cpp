#include<iostream>
#include "action.h"
#include "structures.h"
using namespace std;
void action (player *button , double &poolsize ,int playernum,int &playerleft )
{
	bool endturn = false;
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
		double betsize;
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
				cin >> betsize ;
				if (betsize < max *2 || betsize > current ->chips)
				{
					cout << " Invalid betsize , please input your choice again :" <<endl;
					cin >> opt;
					continue;
				}
				check = true; 
			}
		}
		if (opt==1)
		{
			int diff = max - current-> chipsput;
			if (diff >= max)
			{
				current -> allin = true;
				current -> chipsput += current -> chips;
				current -> chips = 0; // allin if chips remaining is not enough
				playerleft-=1; 
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
			if (current->chips==0){
				current->allin=true;
				playerleft-=1;
			}
		}
		else{
			current->ingame =false;
			playerleft-=1;
		}
		endturn == true;
		player * checking = button;
		for (int i = 0 ; i < playernum ; i++) // checking if all players have put same amount of chips (max) , or have all in 
		{
			if (checking->ingame == true && checking -> allin==false && checking ->chipsput < max){
				endturn=false;
				break;
			}
			checking=checking->next;
		}		
	}

	player * current=button;
	for (int i= 0 ; i < playernum ; i++) // adding dead chips to the pool
	{
		poolsize += current->chipsput;
		current->chipsput=0; // initilize chipsput
		current= current -> next;
	}
	if (playerleft==1)
	{
		terminate=true;
	}
}
