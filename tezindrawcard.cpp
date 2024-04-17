#include <iostream>
#include <ctime>
#include <cstdlib>
#include "initialization.h"
#include "structures.h"
using namespace std;

void cardDraw(Deck &deck, int &card[])
{
   srand(time(NULL));
   bool exists = false;
   while(!exists)
   {
      int randomsuit = rand() % 4;
      int randomrank = rand() % 13;
      if(deck[randomsuit][randomrank])
      {
         exists = true;
         card[0] = randomsuit;
         card[1] = randomrank;
         deck[randomsuit][randomrank] = false;
         return;
      }
   }
}

void distribute(Deck &deck, player *button, int playernum)
{
   for(int i = 0; i < playernum ; i++)
   {
      for (int j =0; j<2 ;j++)
      {
         cardDraw(deck, int &card[]);
         button->hand[j][0] = card[0] ; //suit
         button->hand[j][1] = card[1] ; //rank
         button = button->next;
      }
   }
}

