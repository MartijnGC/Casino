
#ifndef CASINO_DECK_H
#define CASINO_DECK_H
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"

class Deck {
public:
    Deck() {
        Cards = getDeck();
    }

    std::vector<Card> Cards;

    // Creates a deck
    std::vector<Card> getDeck();

    // Shuffles the deck
    std::vector<Card> shuffle();

    // Creates amount of decks and returns it as one
    Deck CreateDeck(int amount);

};


#endif //CASINO_DECK_H

