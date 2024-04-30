#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "minigame.h"
#include "drawcard.h"
#include "structures.h"
#include "output.h"
using namespace std;
void calodds(double (&odds)[3], int (&card)[2], int (&sto)[1]) 
{
   int count;
   double odd = 0;
   if (sto[0] == 7)
   {
      odds[0] = 1.0;
      odds[2] = 1.0;
   } else if (sto[0] < 7)
   {
      count = sto[0];
      if (count >= 2)
      {
         for (int i = 1; i < count; i++) 
         {
            odd += 4; 
         }
         odd = 2.0 - (odd/(48.0-odd));
         odds[0] = odd;
         odds[2] = (3-odd);
      }
      else
      {
         odds[2] = 1.0;
      }
   } else if (sto[0] > 7)
   {
      count = 14 - sto[0];
      if (count >= 2) 
      {
         for (int i = 1; i < count; i++) 
         {
            odd += 4; 
         }
         odd = 2.0 - (odd/(48.0-odd));
         odds[2] = odd;
         odds[0] = (3-odd);
      }
      else 
      {
         odds[0] = 1.0;
      }
   }
}
void minigame(bool (&deck)[4][13],player * current) {
   char choice;
   int card[2];
   double odds[3] = {0.0, 3.0, 0.0};
   int sto[1]; //variable for storing the first card drawn
   bool result = true;
   cardDraw(deck, card);
   sto[0] = card[1]; //storing the first card drawn
   printcard(card[0], card[1]);    // Display the selected card
   cout << "" << endl; 
   cout << "Please choose whether next card drawn will be Larger (L) or Smaller (S) or The Same (D):" << endl;
   cin >> choice;
   cardDraw(deck, card);
   calodds(odds, card, sto);
   if (card[1] > sto[0]) {
      if (choice == 'S') {
         cout << "Correct Choice!!" << endl;
         current ->chips = 100 * odds[0];
      }
      else {
         cout << "Wrong Choice!!" << endl;
         current -> chips = 30;
      }
   }
   if (card[1] == sto[0])  {
      if (choice == 'D') {
         cout << "Correct Choice!!" << endl;
         current ->chips = 100* odds[1];
      }
      else {
         cout << "Wrong Choice!!" << endl;
         current -> chips = 30;
      }
   }
   else {
      if (choice == 'L') {
         cout << "Correct Choice!!" << endl;
         current ->chips = 100* odds[2];
      }
      else {
         cout << "Wrong Choice!!" << endl;
         current -> chips = 30;
      }
   }
}
void checkchips(bool (&deck)[4][13], player * button, int playernum) {
   player *current = button;
   for (int i = 0 ; i < playernum ; i++){
      if (button->next->next==current && current ->chips <=1) // big blind chips cannot smaller than 1
         minigame(deck, current);
      else if (button->next==current && current ->chips <=0.5) // small blind chips cannot smaller than 0.5
         minigame(deck, current);
      else if (current->chips == 0)
         minigame(deck, current);
      current = current->next;
   }
}
