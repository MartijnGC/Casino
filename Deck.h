
#ifndef CASINO_DECK_H
#define CASINO_DECK_H
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"

class Deck {
public:
    Deck(int amount) {
        Cards = getDeck();
        Cards = shuffle(Cards);
    }

    std::vector<Card> Cards;

    std::vector<Card> getDeck();
    std::vector<Card> shuffle(std::vector<Card> Cards);
};


#endif //CASINO_DECK_H
