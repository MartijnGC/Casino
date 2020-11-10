#ifndef CASINO_BLACKJACK_H
#define CASINO_BLACKJACK_H
#include <vector>
#include "Card.h"
#include "Deck.h"

class Blackjack {
public:
    Blackjack();
    void PlayBlackJack(int &Money, Deck &PlayDeck);
};


#endif //CASINO_BLACKJACK_H
