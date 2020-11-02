
#ifndef CASINO_DECK_H
#define CASINO_DECK_H
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck(int amount) {
        Cards = getDeck();
    }

    std::vector<Card> Cards;

    std::vector<Card> getDeck();
};


#endif //CASINO_DECK_H
