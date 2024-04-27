#include <iostream>
#include <ctime>
#include <cstdlib>
#include "structures.h"
#include "drawcard.h"
#include <string>
#include <map>
using namespace std;

void cardDraw(bool (&deck)[4][13], int (&card)[2])
{
   srand(time(NULL));
   bool flag = false;
   string suits[] = {"\u2660", "\u2663", "\u2665", "\u2666"};
   while(!flag)
   {
      int randomsuit = rand() % 4;
      int randomrank = rand() % 13;
      if(deck[randomsuit][randomrank])
      {
         flag = true;
         card[0] = randomsuit;
         card[1] = randomrank;
         deck[randomsuit][randomrank] = false;
      }
   }
}

void distribute(bool (&deck)[4][13], player * button, int playernum)
{
   for(int i = 0; i < playernum; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         int card[2];
         cardDraw(deck, card);
         cout << card[0] << "  " << card[1] << endl;
         button->hand[j][0] = card[0];
         button->hand[j][1] = card[1];
         button = button->next;
      }
   }
}


