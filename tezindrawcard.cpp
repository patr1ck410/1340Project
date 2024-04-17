#include <iostream>
#include <ctime>
#include <cstdlib>
#include "initialization.h"
#include "structures.h"
using namespace std;

void cardDraw(Deck &deck, player* head, int &suit, int &rank){
   srand(time(NULL));
   while(head != nullptr){
      int randomsuit = rand() % 3;
      int randomrank = rand() % 12;
      while(!deck[randomsuit][randomrank]){
         int randomsuit = rand() % 3;
         int randomrank = rand() % 12;
         head->hand[randomsuit][randomrank];
         head = head->next;
      }
   }
                                          
