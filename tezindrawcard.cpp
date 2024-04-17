#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void cardDraw(Deck &deck, int &suit, int &rank){
   srand(time(NULL));
   int randomsuit = rand() % 3;
   int randomrank = rand() % 12;
   if(deck[randomsuit][randomrank]){
      
   }
} 
                                                      
