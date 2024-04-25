#ifndef CHECKWIN_H 
#define CHECKWIN_H 


#include "structures.h"
#include <map>

long assignvalue(int combine[7][2]);
void givewinner(int poolsize, player * button);
long localvalue ( std::map<int,int> rank, int n , int used ); // the local n highcards values 
void checkwin(player * button, int publiccard[5][2],int poolsize); //check which type of poker hand player have


#endif
