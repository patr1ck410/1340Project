#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Card{
   string suit;
   string rank;
 10 };
 11 
 12 void drawcard(Card deck[], int &decksize){
 13   srand(time(0));
 14   int randomindex = rand() % decksize;
 15   Card drawncard = deck[randomindex];
 16   cout << "You drew" << drawncard.suit << drawncard.rank << endl;
 17   deck[randomindex] = deck[decksize - 1];
 18   decksize--;
 19 }
 20 
 21 int main(){
 22   string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    @                                                                           
                                                              1,1           Top
