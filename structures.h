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
	double sidepool; // only have value when a player all in and determine the pot he can get if he wins
	int value; // assigning a value of the rank of player after check win 
	player *next;   //circular linked list
};

#endif
