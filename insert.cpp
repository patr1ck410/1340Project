#include<iostream> 
#include "insert.h"
#include "structures.h"
using namespace std;
void appendplayer( player * &button ,string pname, bool lastplayer){
	player * p = new player;
	p -> name = pname;
	p -> chips = 100;
	p -> ingame = true;
	p -> chipsput = 0;
	p -> allin = false;
	if (lastplayer==true)
		p -> next =button;
	else
		p -> next = NULL;
	if (button= NULL)
		button = p;
	

}
