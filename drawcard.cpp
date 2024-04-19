#include <iostream>
#include <ctime>
#include <cstdlib>
#include "initialization.h"
#include "structures.h"
#include <string>
using namespace std;

void cardDraw(bool (&deck)[4][13], int card[])
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
      }
   }
}

void distribute(bool (&deck)[4][13], player *button, int playernum)
{
   for(int i = 0; i < playernum; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         int card[2];
         cardDraw(deck, card);
         button->hand[j][0] = card[0];
         button->hand[j][1] = card[1];
         button = button->next;
      }
   }
}

void printcard(int card[2])
{   
   string suits[] = {"Diamond", "Club", "Heart", "Spade"};
   string ranks[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
   int suit = card[0];
   int rank = card[1];
   cout << suits[suit] << " " << ranks[rank] << endl;
}

void showhand(player *button)
{
   for(int i = 0; i < 2; i++)
   {
      printcard(button->hand[i]);
   }      
}


