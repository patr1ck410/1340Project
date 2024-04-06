#include<iostream>
#include"initialization.h"
using namespace std;
void gamestart(&bool deck[][]){
	for (int i=0;i<=3;i++)
		for (int j=0;j<=12;j++)
			deck[i][j]=True;
return 0;//initilize 2d array deck with True representing the card is still in the deck
}
  
