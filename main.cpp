#include <iostream>
#include "initialization.h"
#include "startgame.h"
#include <random>
#include <cstdlib>
#include <time.h>


enum class Suit = {CLUB, DIAMOND, HEART, SPADE};
enum class Rank = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, RIGHT, NINE, TEN, JACK, QUEEN, ACE};

struct Card{
    Suit suit;
    Rank rank;
};

class Deck{
public:
    void setupdeck(){
        int index = 0;
        for (int suit = 0; suit < 4; suit++){
            for (int rank = 0; rank < 13; rank++){
                cards[index++] = {static_cast<Suit>(suit), static_cast<Rank>(rank)};
            }
        }
    }
    void shuffle(){
        srand(time(0));
    }
private:
    static const int NumOfCards = 52;
    Card cards[NumOfCards];
};

int main()
{
    initializegame();
    startgame();
    Deck deck;
    deck.setupcards();
}
