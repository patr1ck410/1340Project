#ifndef LOADANDSAVE_H
#define LOADANDSAVE_H

#include "structures.h"
#include <string>

bool checkempty(std::string filename);
void retrievegame(player  *& button, player *& tail, int & playernum);
void savegame(player *& button);

#endif