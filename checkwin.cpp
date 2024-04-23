#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "checkwin.h"
# include "structures.h"

void checkwin(player * button, int publiccard[5][2]) //check which type of poker hand player have
{ 
	player * current = button;
	do {
		if (current ->ingame)
    {
			int combine[7][2];
			for (int i=0;i<5;i++)
			{

				for (int j=0 ;j<2;j++)
        {
					combine[i][j]=publiccard[i][j];
				}
			}
			for (int i=5;i<7;i++)
			{
				for (int j=0;j<2;j++){
					combine[i][j]=current->hand[i-5][j];
				}
			}
			current->value = assignvalue(combine); //the approach here  
		}		
		current = current -> next;
	} while(current!= button);
	
}

int assignvalue(int combine[7][2]){
	int suit[4]={0,0,0,0};
	int rank [13]={0,0,0,0,0,0,0,0,0,0,0,0,0}; // staticial data of the cards
	int value;
	for (int i =0;i<7;i++)
		suit[combine[i][0]]+=1;
	for (int i =0; i<7;i++)
		rank[combine[i][1]]+=1;
	int suited =4;
	int straight = 14;
	for (int i =0;i<4;i++)
		if (suit[i]>=5)
			suited=i; // check if 0-3 is suited, 4 represetning not suited
	int count=0;
	for (int i=0;i<14;i++){
		if (rank[i%13]!=0)
			count+=1;
		else 
			count=0;
		if (count==5)
			straight=i; // if straight !=14 , then exist straight , the value straight representing is useful in assigning values
	}
	vector <int> suits;
	if (suited!=4){
		for (i=0;i<7;i++){
			if(combine[i][0]==suited){
				suits.push_back(combine[i][1]);
			}
		}
		sort(suits.begin(), suits.end()); // sorted vector for ranks in same flush
	}
	if (suited !=4 && straight !=14) //possibility in striaght flush
		int count=1;
		int prev=suits[0];
		for (int i=1;i<suits.size();i++){
			if (suits[i]==(prev+1)){
				count+=1;
				prev=suits[i];
			else
				count=0;
		}
		
	

	return value;

}
