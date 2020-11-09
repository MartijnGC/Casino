#ifndef CASINO_BLACKJACK_H
#define CASINO_BLACKJACK_H
#include <vector>
#include "Card.h"
#include "Deck.h"

class Blackjack {
public:
    Blackjack();
    void PlayBlackJack(int &Money, Deck &PlayDeck);

    //int BeginGame(int &Bet, int &Money, Deck &PlayDeck, int &PlayerScore, int &DealerScore, bool &BlackJack, int &valCard1, int &valCard2);
    //int Player(Deck &PlayDeck, int &PlayerScore, int& PlayerScore2, bool &Bust, int &Bet, int &valCard1, int &valCard2);
    //int Dealer(int &DealerScore, Deck &Playdeck);
    //int Endgame(int &PlayerScore, int &DealerScore, int &Bet, int &Money, bool &BlackJack);


};


#endif //CASINO_BLACKJACK_H
