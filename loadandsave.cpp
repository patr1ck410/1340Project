#include "loadandsave.h"
#include "structures.h"
#include "insert.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

bool checkempty(string filename) // check whether the file is empty or not
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
void retrievegame(player  *& button, player *& tail, int & playernum) // load last game data into the main game
{
    ifstream lastgame;
    lastgame.open("lastgame.txt");
    string line;
    int i =0;
    while (getline(lastgame, line))
    {
        playernum++; // counting the number of player
        istringstream iss(line);
        string name, chips;
        iss >> name >> chips;
        player * p = new player; // appending player
        p -> name = name;
        p -> chips = stod(chips);  //set the chips from the txt file
        p -> ingame = true;
        p -> chipsput = 0;
        p -> allin = false;
        p -> next = NULL;
        if (button == NULL){
            button = p;
            tail = p;
        }
        else {
            tail -> next = p;
            tail = p ;
        }
    p->next = button;
    }
    lastgame.close(); // close the file after reading data
}

void savegame(player *& button)
{
    ofstream lastgame ;
    lastgame.open("lastgame.txt");

    player * current = button; 
    lastgame << current->name << " " << current->chips <<"\n"; //first put the first button player data inside
    current = current->next; // set the player next to button as the next player to be save
	while (current != button)   // travel through the list
    {
		lastgame << current->name << " " << current->chips <<"\n"; // save the data
		current = current->next;
	}
    lastgame.close(); // close the file after saving data

};

