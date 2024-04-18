#include <iostream>
#include <ctime>
#include <cstdlib>
#include "initialization.h"
#include "structures.h"
using namespace std;

void cardDraw(bool &deck[4][13], int card[])
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

void distribute(bool &deck[4][13], player *button, int playernum)
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

void flop(bool (&deck)[4][13], int (&publiccard)[5][2])   //publicard define in main function
                                                          //2d array like hands[2][2]
{
   for(int i = 0; i < 3; i++)
   {
      int card[2];
      cardDraw(deck, card);
      publiccard[i][0] = card[0];
      publiccard[i][1] = card[1];
      printcard()      //haven't desgin function
   }
}

void turn(bool (&deck)[4][13], int (&publiccard)[2][2])

{
   int card[2];
   cardDraw(deck, card);
   publiccard[3][0] = card[0];
   publiccard[3][1] = card[1];
   printcard();
}

void river(bool (&deck)[4][13], int (&publiccard)[5][2])
{
   int card[2];
   cardDraw(deck, card);
   publiccard[4][0] = card[0];
   publiccard[4][1] = card[1];
   printcard();
}


   
