#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#include "checkwin.h"
# include "structures.h"

void checkwin(player * button, int publiccard[5][2]) //check which type of poker hand player have
{ 
	player * current = button;
	do {
		if (current ->ingame)
    {
			int combine[7][2];// combining the community cards and hand cards of individuals 
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
			current->value = assignvalue(combine); //the approach here you can refer to the file "combination.pdf"  
		}		
		current = current -> next;
	} while(current!= button);
	
}
long localvalue (  map<int,int> rank , int n , int used ){ // the local n highcards values 
	long value=0;
	vector<int> cardrank;
    	for (const auto &pair : rank) {
        	if (pair.second != used) {
            		cardrank.push_back(pair.first);
        	}
    	}
	sort(cardrank.rbegin() , cardrank.rend());
	for (i=0;i < n ;i++)
		value = pow (13,n-i-1) * cardrank[i];
	return value;
		
}
long assignvalue(int combine[7][2]){
	long value;
	int suit[4]={0,0,0,0};
	int rank [13]={0,0,0,0,0,0,0,0,0,0,0,0,0}; // staticial data of the cards
	map <int, int> trank; // key is the rank , and the value is the occurreence
	int value=0; // default 0 first
	for (int i =0;i<7;i++)
		suit[combine[i][0]]+=1;
	for (int i =0; i<7;i++){
		rank[combine[i][1]]+=1;
		if (trank.find(combine[i][1])!=trank.end()){
			trank[(combine[i][1]+12)%13]++;
		}
		else{
			trank[(combine[i][1]+12)%13]=1;
		}
	}
	int suited =4;
	int straight = 14;
	for (int i =0;i<4;i++)
		if (suit[i]>=5)
			suited=i; // check if 0-3 is suited, 4 represetning not suited
	int count=0;
	for (int i=13; i>0 ;i++){
		if (rank[i%13]!=0)
			count+=1;
		else 
			count=0;
		if (count==5)
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
	int four=13;
	int three=13; // only have one value of the highest rank 
	vector <int> two;
	for (const auto &pair : trank) {
		if (pair.second==4)
			four=pair.first;
		else if (pair.second==3)
			if (three==13)
				three=pair.first;
			else if (pair.first >three) // A is 12 , K is 11, 2 is 0 
				three=pair.first;
		else if (pair.second==2)
			two.push_back(pair.second);
	}
	sort(two.rbegin(),two.rend());
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
	if (four !=13)
	{
		long local = localvalue(trank , 1 ,4)
		value =10+local;
		return value ;
	}  // checking for four of a kind
	else if (three!=13 && two.size()!=0){
		value = 179+three*13+two[0];
		return value;
	}
	else if (suited!=4){
		long local = localvalue(trank , 5 , 0 )
		value = 348 + local;
		return value;
	}
	else if (straight!=14){
		value = 371641+ straight ;
		return value;
	}
	else if (three!=13){
		long local = localvalue(trank , 2 , 3)
		value = 371651+local;
		return value;
	}
	else if (two.size()>=2){
		long local = localvalue(trank , 1 , 2)
		value = 373848+local;
		return value;
	}
	else if (two.size()==1){
		long local = localvalue(trank , 3 , 2)
		value = 376045+local;
		return value;
	}
	else {
		long local = localvalue(trank , 1 ,4)
		value = 404606+local;
		return value;
	}
	return value;
}

