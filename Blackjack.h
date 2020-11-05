#ifndef CASINO_BLACKJACK_H
#define CASINO_BLACKJACK_H
#include <vector>
#include "Card.h"
#include "Deck.h"

class Blackjack {
public:
    Blackjack();
    int Turns(Deck PlayDeck);
    int Dealer(int PlayerScore, int DealerScore);


};


#endif //CASINO_BLACKJACK_H
