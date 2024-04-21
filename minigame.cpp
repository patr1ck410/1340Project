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
cardDraw();
