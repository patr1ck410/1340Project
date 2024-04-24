#include "loadandsave.h"
#include "structures.h"
#include "insert.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

bool checkempty(string filename)
{
    ifstream data(filename);
    if (!data.is_open()) 
    {
        cerr << "Failed to open the data." << endl;
        return true;
    }
    if (data.eof()) 
    {
        return false;
    }
    data.seekg(0, ios::end);
    if (data.tellg() == 0) 
    {
        return false;
    }
    return true;
};
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
        if (head == NULL){
            head = p;
            tail = p;
        }
        else {
            tail -> next = p;
            tail = p ;
        }
    p->next = head;
    }
    lastgame.close();
}

void savegame(player *& button)
{
    ofstream lastgame ;
    lastgame.open("lastgame.txt");

    player * current = button;
    lastgame << current->name << " " << current->chips <<"\n";
    current = current->next;
	while (current != button)
    {
		lastgame << current->name << " " << current->chips <<"\n";
		current = current->next;
	}
    lastgame.close();

};

