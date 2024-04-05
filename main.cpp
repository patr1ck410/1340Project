#include <iostream>
#include "initialization.h"
#include "startgame.h"
#include <random>

enum class Suit = {CLUB, DIAMOND, HEART, SPADE};
enum class Rank = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct Card = {
    Suit suit;
    Rank rank;
};

class Deck {
public:

private:
    static const int NUM_CARDS = 52;
    Card cards[NUM_CARDS];
    int currentCardindex;
}

int main()
{
    initializegame();
    startgame();
}
