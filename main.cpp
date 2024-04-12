#include <iostream>
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
			player *playerlist;
			retrievegame(playerlist, playernum);//not done
			newgame=true;
		}
	}
}
