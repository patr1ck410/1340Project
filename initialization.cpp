#include<iostream>
#include"initialization.h"
#include "structures.h"
using namespace std;
void gamestart(bool (&deck)[4][13], player *button, player *tail){
	for (int i=0;i<=3;i++)
		for (int j=0;j<=12;j++)
			deck[i][j]=true;//initilize 2d array deck with True representing the card is still in the deck
	player * current = button;
	do {
		current -> allin=false;
		current-> chipsput=0;
		current -> ingame = true;
		current = current -> next;
	} while (current!=button)  // refreshing game stats of player 
	

}
  
