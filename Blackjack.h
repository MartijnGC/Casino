#ifndef CASINO_BLACKJACK_H
#define CASINO_BLACKJACK_H
#include <vector>
#include "Card.h"
#include "Deck.h"

class Blackjack {
public:
    Blackjack();
    int BeginGame(int &Bet, int &Money, Deck &PlayDeck, int &PlayerScore, int &DealerScore);
    int Player(Deck &PlayDeck, int &PlayerScore, bool &Bust);
    int Dealer(int &DealerScore, Deck &Playdeck);
    int Endgame(int &PlayerScore, int &DealerScore, int &Bet, int &Money);


};


#endif //CASINO_BLACKJACK_H
