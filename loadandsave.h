#ifndef LOADANDSAVE_H
#define LOADANDSAVE_H
struct player;


void retrievegame(player  *& head, player *& tail, int & playernum);
void savegame(player *& head, player *& tail);

#endif