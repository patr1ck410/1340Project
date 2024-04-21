#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include "structures.h"
using namespace std;

void printcard(int card[2]);

void showhand(player *individual);

void showpublic(int cards[5][2],int num);


#endif
