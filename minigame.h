#ifndef MINIGAME_H
#define MINIGAME_H

#include "structures.h"

void calodds(double (&odds)[3], int (&card)[2], int (&sto)[1]);
int minigame(bool (&deck)[4][13],player * current);
void checkchips(bool (&deck)[4][13], player * button, int playernum);

#endif