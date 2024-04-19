#include<iostream>
using namespce std;
void printcard(int card[2])
{   
   string suits[] = {"Diamond", "Club", "Heart", "Spade"};
   string ranks[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
   int suit = card[0];
   int rank = card[1];
   cout << suits[suit] << " " << ranks[rank] << endl;
}

void showhand(player *individual)
{
   for(int i = 0; i < 2; i++)
   {
      printcard(button->hand[i]);
   }      
}
void showpublic(

