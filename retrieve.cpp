#include "retrieve.h"
#include "structures.h"
#include <fstream>
#include <sstream>
using namespace std;
void retrievegame(player  *& playerlist, int & playernum)
{
    ifstream lastgame;
    lastgame.open("lastgame.txt");
    string data;
    int i =0;
    while (getline(lastgame, data))
    {
        istringstream iss(data);
        string temp[2];
        int j = 0;
        while (iss >> data)
        {
            temp[j] = data;
            j++;
        }
        playerlist[i].name = temp[0];
        playerlist[i].chips = stoi(temp[1]);
        i++;
    }
};
