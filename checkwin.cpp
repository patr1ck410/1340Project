#include <iostream>
#include <string>
using namespace std;

# include "structures.h"

void checkwin(player * button, int publiccard[5][2]) //check which type of poker hand player have
{ 
	player * current = button;
	do {
		if (current ->ingame){
			int combine[7][2];
			for (int i=0;i<5;i++)
			{
				for (int j=0 ;j<2;j++){
					combine[i][j]=publiccard[i][j];
				}
			}
			for (int i=5;i<7;i++)
			{
				for (int j=0;j<2;j++){
					combine[i][j]=current->hand[i-5][j];
				}
			}
			current->value = assignvalue(combine);
		}		
		current = current -> next;
	} while(current!= button);
	
}

int assignvalue(int combine[7][2]){
	int suit[4]={0,0,0,0};
	int rank [13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	int value;
	for (int i =0;i<7;i++)
		suit[combine[i][0]]+=1;
	for (int i =0; i<7;i++)
		rank[combine[i][1]]+=1;
}
