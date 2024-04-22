#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
int main() {
    // Define the ranks of a card
    const vector<string> ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    // Create a deck of cards
    vector<string> deck;
    for (const auto& rank : ranks) {
        deck.push_back(rank);
    }

    // Shuffle the deck
    random_device rd;
    mt19937 gen(rd());
    shuffle(deck.begin(), deck.end(), gen);

    // Draw the first card
    if (deck.empty()) {
        cout << "The deck is empty." << std::endl;
        return 0;
    }
    string prevCard = deck.back();
    deck.pop_back();
    cout << "The first card is: " << prevCard << endl;

    // Play the game
    while (!deck.empty()) {
        string nextCard = deck.back();
        deck.pop_back();
        cout << "The next card is: " << nextCard << endl;

        string guess;
        cout << "Guess whether the next card is larger (L), smaller (S), or the same (E): ";
        cin >> guess;

        int prevRank = find(ranks.begin(), ranks.end(), prevCard) - ranks.begin();
        int nextRank = find(ranks.begin(), ranks.end(), nextCard) - ranks.begin();

        if (guess == "L" && nextRank > prevRank) {
            cout << "Correct! The next card is larger." << endl;
        } else if (guess == "S" && nextRank < prevRank) {
            cout << "Correct! The next card is smaller." << endl;
        } else if (guess == "E" && nextRank == prevRank) {
            cout << "Correct! The next card is the same." << endl;
        } else {
            cout << "Incorrect. The next card is " << nextCard << "." << endl;
            break;
        }

        prevCard = nextCard;
    }

    if (deck.empty()) {
        cout << "You made it through the entire deck!" << endl;
    }

    return 0;
}
