#include "Deck.h"


std::vector<Card> Deck::getDeck() {
    // Makes a deck of playing cards

    // Make a vector that contains all the cards
    std::vector<Card> vecCards;

    // Iterate over all card colors (Spades, Hearts, Clubs and Diamonds), Last is added as a stop.
    for (int i  = static_cast<int>(CardColor::Spades); i != static_cast<int>(CardColor::Last); ++i ) {
        // Iterate over all cardValues (Ace to King)
        for (int j = 1; j <= 13; ++j) {
            // Add each card to the vector
            vecCards.push_back(Card(static_cast<CardValue>(j), static_cast<CardColor>(i)));
        }
    }
    // Return the card vector
    return vecCards;
}

std::vector<Card> Deck::shuffle() {


    // code obtained from techiedelight.com/shuffle-vector-cpp/

    // Set random number generator seed
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();

    // Shuffles all the cards in the Deck
    std::shuffle(std::begin(Cards),std::end(Cards), std::default_random_engine(seed));
    return Cards;
}

Deck Deck::CreateDeck(int amount) {
    // Define two decks used to add to eachother
    Deck CompleteDeck, addDeck;

    // Add amount of decks
    for (int i = 1; i < amount; ++i) {
        addDeck = Deck();

        //append original deck with addDeck
        CompleteDeck.Cards.insert(CompleteDeck.Cards.end(),addDeck.Cards.begin(), addDeck.Cards.end());
    }

    return CompleteDeck;
}
