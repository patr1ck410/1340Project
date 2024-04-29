#ifndef ACTION_H
#define ACTION_H

#include "structures.h"
void action(player *button, double &poolsize, int playernum, int &playerinpool, bool &terminate, bool first, bool &allfold, int &playerleft, int publiccard[5][2], int& trun);
void giverewards(player *button, double poolsize);



#endif
