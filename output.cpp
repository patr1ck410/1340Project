#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "structures.h"
using namespace std;

void printcard(int suit, int rank)
{
	string suits[] = {"\u2666", "\u2663", "\u2665", "\u2660"};
	string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	cout << suits[suit] << " " << ranks[rank];
}

void showhand(player *individual)
{
	cout << "Your hands are    ";
	for (int i = 0; i < 2; i++)
	{
		printcard(individual->hand[i][0], individual->hand[i][1]);
		if (i != 1)
			cout << "\t";
	}
	cout << endl;
}
void showpublic(int cards[5][2], int num)
{
	cout << "\n";
	cout << "\n";
	cout << "Community " << num << " cards are    ";
	for (int i = 0; i < num; i++)
	{
		printcard(cards[i][0], cards[i][1]);
		if (i != num - 1)
			cout << "\t";
	}
	cout << "\n";
	cout << "\n";
}
