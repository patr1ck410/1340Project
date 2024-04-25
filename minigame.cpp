#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int minigame(bool (&deck)[4][13], int (&gamecard)[2],player * current) {
   char choice;
   int card[2];
   int sto[1];
   bool result = true;
   cardDraw(deck, card);
   sto[0] = card[1];
   printcard(int card[2]);    // Display the selected card
   cout << "Please choose whether next card drawn will be Larger (L) or Smaller (S) or The Same (D):" << endl;
   cin << choice;
   cardDraw(deck, card);
   if (card[1] > sto[0])  {
      if (choice == 'S') {
         current -> chips = 100;
      }
      else {
         current -> chips = 50;
      }
   }
   if (card[1] == sto[0])  {
      if (choice == 'D') {
         current -> chips = 200;
      }
      else {
         current -> chips = 100;
   }
   }
   else {
      if (choice == 'L') {
         current -> chips = 100;
      }
      else {
         current -> chips = 50;
   }
   }
}
   }
}
void checkchips(bool deck[4][13], player * button, int playernum) {
   current = button;
   for (int i = 0 ; i < playernum ; i++){
      if (button->next->next==current && current ->chips <=1) // big blind chips cannot smaller than 1
         minigame(deck ,card , current);
      else if (button->next==current && current ->chips <=0.5) // small blind chips cannot smaller than 0.5
         minigame(deck, card, current);
      else if (current->chips == 0)
         minigame(deck, card, current);
      current = current->next;
   }
