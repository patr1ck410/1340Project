#include<iostream> 
#include "insert.h"
#include "structures.h"
using namespace std;
void appendplayer( player *& button, player *tail, string pname, bool lastplayer){
	player * p = new player;
	p -> name = pname;
	p -> chips = 100;
	p -> ingame = true;
	p -> chipsput = 0;
	p -> allin = false;
	if (button == NULL){
		button = p;
		tail = p;
		p -> next = NULL;
	}
	else 
	{
		tail -> next = p;
		if (lastplayer==true){
			p->next = button;
		}
		else 
		{
			tail=p;
			p->next =NULL;
		}
	}
}
