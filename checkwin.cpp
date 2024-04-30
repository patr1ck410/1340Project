#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "output.h"
#include "checkwin.h"
#include "structures.h"
using namespace std;



long assignvalue(int combine[7][2]){ // assigning values with 0 is the largest , comment in combination.pdf
	long value = 0; // default 0 first
	int suit[4]={0,0,0,0};
	int rank [13]={0,0,0,0,0,0,0,0,0,0,0,0,0}; // staticial data of the cards
	map <int, int> trank; // key is the rank , and the value is the occurreence
	for (int i =0;i<7;i++)
		suit[combine[i][0]]+=1;
	for (int i =0; i<7;i++){// trank is map with keys are the rank , and the value is the occurenece , with A is smallest , 2 is largest
		rank[combine[i][1]]+=1;
		if (trank.find(12-(12+combine[i][1])%13)!=trank.end()){
			trank[12-(combine[i][1]+12)%13]++; // add if exist
		}
		else{
			trank[12-(combine[i][1]+12)%13]=1; // create if not
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
		{
			straight = 9 - i; // if straight !=14 , then exist straight , the value straight representing is useful in assigning values
			break;
		}
	}
	vector <int> suits;
	map <int,int> suitmap;// use to count highcard 
	if (suited!=4){
		for (int i=0 ; i<7 ; i++){
			if(combine[i][0]==suited){
				suits.push_back(combine[i][1]);
				suitmap[12-((combine[i][1]+12)%13)]=1;
			}
		}
		sort(suits.begin(), suits.end()); // sorted vector for ranks in same flush in acsedning order
	}
	int four=13;
	int three=13; // only have one value of the highest rank 
	vector <int> two;
	for (map<int, int>::iterator card = trank.begin(); card != trank.end(); ++card) {
		if (card->second==4)
			four=card->first; 
		else if (card->second==3){
			if (three==13)
				three=card->first;
			else if (card->first <three)
				three=card->first;
		}
		else if (card->second==2)
			two.push_back(card->first);
	}
	for (map<int, int> ::iterator card = trank.begin(); card!=trank.end(); ++card){
		cout << card->first << ":" << card->second<<endl;
	} 
	sort(two.begin(),two.end()); // sort in asending order
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
				value=(9-suits[i]); // so only 0-9 will be returned 
		}
		if (value!=0)
			return value;
	}
	if (four !=13)
	{
		long local = localvalue(trank , 1 ,4);
		value =10+four*13+local;
		return value ;
	}  // checking for four of a kind
	else if (three!=13 && two.size()!=0){
		value = 179+three*13+two[0];
		return value;
	}// checking of full house 
	else if (suited!=4){
		long local = localvalue(suitmap , 5 , 0 );
		value = 348 + local;
		return value;
	}// checking of flush
	else if (straight!=14){
		value = 371641+ straight ;
		return value;
	}// checking of straight 
	else if (three!=13){
		long local = localvalue(trank , 2 , 3);
		value = 371651+local;
		return value;
	}// checking for three of a kind
	else if (two.size()>=2){
		long local = localvalue(trank , 1 , 2);
		value = 373848+pow(13,2)*two[0]+13*two[1]+local;
		return value;
	}// checking for two pairs
	else if (two.size()==1){
		long local = localvalue(trank , 3 , 2);
		value = 376045+pow(13,3)*two[0]+local;
		return value;
	}// checking for pair
	else {
		long local = localvalue(trank , 5 ,0);
		value = 404606+local;
		return value;
	}// checking for highcard
	return value;
}

void outputwinner(player * current,double reward){ // for output winner
	cout << current-> name <<  " won chips : " << reward<< endl;
	showhand (current);
	cout << "Current chips: " << current->chips <<endl;
}

void givewinner(int poolsize, player * button)
{
	long min = 780000;
	player * winner = NULL, * current=button;
	do 
	{
		if (current -> ingame==true )
		{
			if (current->value < min)
			{
				min = current->value;
				winner = current;
			}
		}
		current = current->next;
	} while (current != button);
	cout << "Winner is: " << winner->name << endl;
	if (winner-> allin==false){
		winner->chips+=poolsize; // without allin can get the whole pool
		outputwinner(winner, poolsize);
		poolsize=0;
	}
	else{
	
		winner->chips+=winner->sidepool; // for player all in 
		outputwinner(winner, winner->sidepool);
		winner->ingame=false;
		poolsize-=winner->sidepool; 
	
	}
	if (poolsize>0)
		givewinner(poolsize, button); // the pool is not yet 0, means still can distribute chips to players
}

long localvalue (  map<int,int> rank , int n , int used )// the local n highcards values 
{ 
	long value=0;
	vector<int> cardrank;
	for (map<int, int>::iterator pair = rank.begin(); pair != rank.end(); ++pair) {
		if (pair->second != used)
		{	
			cardrank.push_back(pair->first);
		}
	}
	sort(cardrank.begin() , cardrank.end()); // sort in asceding order	
	for (int i = 0;i < n ;i++)
		value += pow (13,n-i-1) * cardrank[i];
	return value;
}
void checkwin(player * button, int publiccard[5][2],int poolsize) //check which type of poker hand player have
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
					combine[i][j]=publiccard[i][j]; // add community cards
				}
			}
			for (int i=5;i<7;i++)
			{
				for (int j=0;j<2;j++){
					combine[i][j]=current->hand[i-5][j]; // add player's handd cards
				}
			}
			cout << "Name:" << current-> name<< endl;
			current->value = assignvalue(combine); //the approach here you can refer to the file "combination.pdf" 
			cout << "Value: " << current->value <<endl;
		}		
		current = current -> next;
		
	} while(current!= button);
	givewinner(poolsize, button); // for giving chips
}
