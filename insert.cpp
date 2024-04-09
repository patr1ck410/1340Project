#include<iostream> 
using namespace std;
void appendplayer( player * &head,player * & tail ,string pname, bool lastplayer){
	player * p = new player;
	p -> name = pname;
	p -> chips = 100;
	p -> ingame = true;
	p -> chipsput = 0;
	p -> allin-> false;
	p -> next = NULL:
	if (head= NULL){
		head = p;
		tail = p;
	}
	else {
		tail -> next = p;
		tail =p;
	}
	return 0;
}
