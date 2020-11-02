

#include "Deck.h"
#include <array>

std::vector<Card> Deck::getDeck() {
    std::vector<Card> vecCards;

    //std::array<std::string,4> colors = {"Spades", "Hearts", "Clubs", "Diamonds"};
    for (int i  = static_cast<int>(CardColor::Spades); i != static_cast<int>(CardColor::Last); ++i ) {
        for (int j = 1; j <= 13; ++j) {
            vecCards.push_back(Card(static_cast<CardValue>(j), static_cast<CardColor>(i)));
        }
    }

    return vecCards;

}
