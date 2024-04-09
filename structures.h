#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string>

struct player{
	std::string name;
	double chips;
	bool ingame;
	int hand[2][2];
	double chipsput;
	bool allin;
	player *next;
};

#endif