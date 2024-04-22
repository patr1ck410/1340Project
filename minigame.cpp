#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int minigame(bool (&deck)[4][13], int (&gamecard)[2]) {
   srand(time(NULL));
   char choice;
   bool result;
   bool flag = false;
   while(!flag)
   {
      int randomsuit = rand() % 4;
      int randomrank = rand() % 13;
      if(deck[randomsuit][randomrank])
      {
         flag = true;
         card[0] = randomsuit;
         card[1] = randomrank;
         deck[randomsuit][randomrank] = false;
      }
   }
   // Translate the suit and rank indices to card names and symbols
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string cardName = ranks[card[1]] + " of " + suits[card[0]];
    string cardSymbol;
    switch (card[0]) {
        case 0: cardSymbol = "♣"; break;
        case 1: cardSymbol = "♦"; break;
        case 2: cardSymbol = "♥"; break;
        case 3: cardSymbol = "♠"; break;
    }

    // Display the selected card
    cout << "The card drawn is: " << cardName << " (" << cardSymbol << ")" << endl;
    cout << "Please choose whether next card drawn will be Larger (L) or Smaller (S) or The Same (D):" << endl;
    cin << choice
    
    
    
}
void checkchips(head) {
    current = head;
    while current != tail {
        if current.chips == 0:
            minigame();
        current = current.next
    }
}
