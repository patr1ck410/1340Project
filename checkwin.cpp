#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
	int value=NULL;
	int suit[4]={0,0,0,0};
	int rank [13]={0,0,0,0,0,0,0,0,0,0,0,0,0}; // staticial data of the cards
	map <int, int> trank; // key is the rank , and the value is the occurreence
	int value=0; // default 0 first
	for (int i =0;i<7;i++)
		suit[combine[i][0]]+=1;
	for (int i =0; i<7;i++){
		rank[combine[i][1]]+=1;
		if (trank.find(combine[i][1])!=trank.end()){
			trank[combine[i][1]]++;
		}
		else{
			trank[combine[i][1]]=1;
		}
	}
	int suited =4;
	int straight = 14;
	for (int i =0;i<4;i++)
		if (suit[i]>=5)
			suited=i; // check if 0-3 is suited, 4 represetning not suited
	int count=0;
	for (int i=13; i>=0 ;i++){
		if (rank[i%13]!=0)
			count+=1;
		else 
			count=0;
		if (count>=5)
			straight=i; // if straight !=14 , then exist straight , the value straight representing is useful in assigning values
	}
	vector <int> suits;
	if (suited!=4){
		for (int i=0 ; i<7 ; i++){
			if(combine[i][0]==suited){
				suits.push_back(combine[i][1]);
			}
		}
		sort(suits.begin(), suits.end()); // sorted vector for ranks in same flush
	}
	
	int four=NULL;
	int three=NULL; // only have one value of the highest rank 
	vector <int> two;
	for (const auto &pair : trank) {
		if (pair.second==4)
			four=pair.first;
		else if (pair.second==3)
			if (three==NULL)
				three=pair.first;
			else if ((pair.first+12)%13 > (three+12)%13) // A is 12 , K is 11, 2 is 0 
				three=pair.first;
		else if (pair.second==2)
			two.push_back(pair.second);
	}
	sort(two.begin(),two.end());
	if (suited !=4 && straight !=14){ //possibility in striaght flush
		int count=1;
		int prev=suits[suits.size()-1]; // checking from the back 
		for (int i=suits.size()-2;i>=0;i--){
			if (suits[i]==(prev-1)){
				count+=1;
				prev=suits[i];
			}
			else
				count=0;
			if (count>=5)
				value=suits[i]; // so only 0-9 will be returned 
		}
		if (value!=0)
			return value;
	}
	if (four !=NULL)
	{
		int highcard=0;
		for (const auto &pair : trank){
			if (pair .second !=4 && ((pair.first+12)%13)> highcard) 
				highcard=(pair.first+12)%13;
		}
		value =10+((four+12)%13)*13+highcard;
		return value ;
	}// checking for four of a kind
	else if (three!= NULL && two.size()!=0)
		value = 179+((three+12)%13)*13+((two.back()+12)%13);
		return value;
	else if (suited!=4){
		value = 
	else if (straight!=14)
	
	
		
	

	return value;

}
