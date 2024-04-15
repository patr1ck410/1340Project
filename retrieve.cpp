#include "loadandsave.h"
#include "structures.h"
#include "insert.h"
#include <fstream>
#include <sstream>
using namespace std;
void retrievegame(player  *& head, player *& tail, int & playernum)
{
    ifstream lastgame;
    lastgame.open("lastgame.txt");
    string line;
    int i =0;
    while (getline(lastgame, line))
    {
        istringstream iss(line);
        string name, chips;
        iss >> name >> chips;
        player * p = new player;
        p -> name = name;
        p -> chips = stod(chips);
        p -> ingame = true;
        p -> chipsput = 0;
        p -> allin = false;
        p -> next = NULL;
        if (head= NULL){
            head = p;
            tail = p;
        }
        else {
            tail -> next = p;
            tail = p ;
    }
    p->next = head;
    }
};
