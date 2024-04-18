#include <iostream>
#include <ctime>
#include <cstdlib>
#include "initialization.h"
#include "structures.h"
using namespace std;

void cardDraw(bool (&deck)[4][13], int (& card)[])
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

void distribute(bool (&deck)[4][13], player *button, int playernum)
{
   for(int i = 0; i < playernum ; i++)
   {
      for (int j = 0; j < 2 ;j++)
      {
         int card[2];
         cardDraw(deck, card);
         button->hand[j][0] = card[0] ; //suit
         button->hand[j][1] = card[1] ; //rank
         button = button->next;
      }
   }
}

void flop(bool (&deck)[4][13], int (&publiccard)[2][2]){ //publiccard define in main function
                                                     //2d array like hands[2][2]
   srand(time(NULL));
   for(int i = 0; i < 3; i++)
   {
      bool flag = false;
      while(!flag)
      {
         int randomsuit = rand() % 4;
         int randomrank = rand() % 13;
         if(deck[randomsuit][randomrank])
         {
            flag = true;
            publiccard[i][0] = randomsuit;
            publiccard[i][1] = randomrank;
            deck[randomsuit][randomrank] = false;
            i++;
            printcard(); //implment later
         }
      }
   }
}

