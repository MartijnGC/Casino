#ifndef CASINO_BLACKJACK_H
#define CASINO_BLACKJACK_H
#include <vector>
#include "Card.h"
#include "Deck.h"

class Blackjack {
public:
    Blackjack();
    int Turns(Deck PlayDeck);
    int Dealer(int Score);


};


#endif //CASINO_BLACKJACK_H
