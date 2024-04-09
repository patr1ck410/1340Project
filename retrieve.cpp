#include "retrieve.h"
#include "structures.h"
#include <fstream>
using namespace std;

void retrievegame(player  *& playerlist)
{
    ifstream lastgame;
    lastgame.open("lastgame.txt");
    string data;
    int i =0;

    while (lastgame >> data)
    {
        lastgame >> 
            playerlist[i].name >>
            playerlist[i].chips >> 
            playerlist[i].ingame >> 
            playerlist[i].hand >>
            playerlist[i].chipsput>>
            playerlist[i].allin>>
            playerlist[i].next;
    }
    

};
