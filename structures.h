#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string>

struct player{
	std::string name;
	double chips; // store chips remaining;
	bool ingame; // true indicates the player has not fold
	int hand[2][2]; // storing hands 
	double chipsput; // stroing deadn chips in front
	bool allin; // true indicates the player has all in
	int sidepool; // only have value when a player all in and determine the pot he can get if he wins
	int handranking[7][2]; // combining ht ecommunity cards and hand cards
	int value; // assigning a value of the rank of player after check win 
	player *next;   //circular linked list
};

#endif
