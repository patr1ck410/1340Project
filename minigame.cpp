#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
int minigame() {
    // Define the ranks of a card
    const std::vector<std::string> ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    // Create a deck of cards
    std::vector<std::string> deck;
    for (const auto& rank : ranks) {
        deck.push_back(rank);
    }

    // Shuffle the deck
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);

    // Draw the first card
    if (deck.empty()) {
        std::cout << "The deck is empty." << std::endl;
        return 0;
    }
    std::string prevCard = deck.back();
    deck.pop_back();
    std::cout << "The first card is: " << prevCard << std::endl;

    // Play the game
    while (!deck.empty()) {
        std::string nextCard = deck.back();
        deck.pop_back();
        std::cout << "The next card is: " << nextCard << std::endl;

        std::string guess;
        std::cout << "Guess whether the next card is larger (L), smaller (S), or the same (E): ";
        std::cin >> guess;

        int prevRank = std::find(ranks.begin(), ranks.end(), prevCard) - ranks.begin();
        int nextRank = std::find(ranks.begin(), ranks.end(), nextCard) - ranks.begin();

        if (guess == "L" && nextRank > prevRank) {
            std::cout << "Correct! The next card is larger." << std::endl;
        } else if (guess == "S" && nextRank < prevRank) {
            std::cout << "Correct! The next card is smaller." << std::endl;
        } else if (guess == "E" && nextRank == prevRank) {
            std::cout << "Correct! The next card is the same." << std::endl;
        } else {
            std::cout << "Incorrect. The next card is " << nextCard << "." << std::endl;
            break;
        }

        prevCard = nextCard;
    }

    if (deck.empty()) {
        std::cout << "You made it through the entire deck!" << std::endl;
    }

    return 0;
}
