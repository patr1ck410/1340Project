#include<iostream>
#include<time.h>
#include<stdlib.h>
#include "structures.h"
using namespace std;

void printcard(int card[2])
{   
	string suits[] = {"Diamond", "Club", "Heart", "Spade"};
	string ranks[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	int suit = card[0];
	int rank = card[1];
	cout << suits[suit] << " " << ranks[rank] ;
}

void showhand(player *individual)
{
	cout << "Your hands are " ;
	for(int i = 0; i < 2; i++){ 
   		printcard(individual->hand[i]);
		if (i!=1)
			cout << ", ";
   	}
	cout << endl;
}
void showpublic(int cards[5][2],int num){
	cout << "Community "<< num << "cards are" ; 
	for (int i=0;i < num;i++){
		printcard(cards[i]);
		if (i!=num-1)
			cout << ", ";
	}
	cout << endl;
}

