#ifndef DRAWCARD_H
#define DRAWCARD_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "structures.h"
using namespace std;

void cardDraw(bool (&deck)[4][13], int (& card)[2]);

void distribute(bool (&deck)[4][13], player *button, int playernum);


#endif
