#include <iostream>
#include <ctime>
#include <cstdlib>
#include "structures.h"
#include "drawcard.h"
#include <string>
using namespace std;

void cardDraw(bool (&deck)[4][13], int (&card)[2])
{
   srand(time(NULL));
   bool flag = false;
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
         cout << randomsuit << " " << randomrank << endl;
      }
   }
}

void distribute(bool (&deck)[4][13], player * button, int playernum)
{
   player * current = button;
   for(int i = 0; i < playernum; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         int card[2];
         cardDraw(deck, card);
         button->hand[j][0] = card[0];
         button->hand[j][1] = card[1];
         current = current->next;
      }
   }
}


