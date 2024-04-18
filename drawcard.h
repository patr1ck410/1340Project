#ifndef DRAWCARD_H
#define DDRAWCARD_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "initialization.h"
#include "structures.h"
using namespace std;

void cardDraw(bool (&deck)[4][13], int (& card)[]);

void distribute(bool (&deck)[4][13], player *button, int playernum);

void flop(bool (&deck)[4][13], int (&publiccard)[2][2]);


#endif
