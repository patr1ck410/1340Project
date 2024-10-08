#include <iostream>
#include <ctime>
#include <cstdlib>
#include "structures.h"
#include "drawcard.h"
#include <string>
using namespace std;

void cardDraw(bool (&deck)[4][13], int (&card)[2])	//Carddraw function
{
   srand(time(NULL));	//Generate random seed using system time
   bool found = false;	//Use flag to identity whether the card is available in deck
   while(!found)
   {
      int randomsuit = rand() % 4;
      int randomrank = rand() % 13;
      if(deck[randomsuit][randomrank])	//Check the existence of the random card in deck
      {
         found = true;	//Control the while loop
         card[0] = randomsuit;
         card[1] = randomrank;
         deck[randomsuit][randomrank] = false;
      }
   }
}

void distribute(bool (&deck)[4][13], player * button, int playernum)	//Distribute function
{
	player * current = button;	//Start distributing card from button
	for(int i = 0; i < playernum; i++){
		for(int j = 0; j < 2; j++) {
 			int card[2];
  			cardDraw(deck, card);
			current->hand[j][0] = card[0];
			current->hand[j][1] = card[1];
		}
		current= current-> next;	//Update pointer
	}
}


