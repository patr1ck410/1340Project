#include <iostream>
#include <string>
using namespace std;

void checkwin(player * button,publiccard) { //check which type of poker hand player have
	player * current = button;
	do {
		if (current ->ingame){
			int combine[7][2];
			for (int i=0;i<5;i++){
				for (int j=0 ;j<2;j++){
					combine[i][j]=publiccard[i][j];
				}
			}
			for (int i=5;i<7;i++){
				for (int j-0;j<2;j++){
					combine[i][j]=current->hand[i-5][j];
				}
			}
			current->value=assignvalue(combine));		
		current = curent -> next;
	}while(current!= button);
}
int assignvalue(
