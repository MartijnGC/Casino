
#include "Blackjack.h"
#include <iostream>

Blackjack::Blackjack() {

    // Ask user for amount of decks they want to use
    int amountDecks = 1;
    std::cout << "Enter the amount of decks you want to play with: " << std::endl;
    std::cin >> amountDecks;

    // Call function CreateDeck which create deck based on amount of decks player wants to use
    Deck PlayDeck;
    PlayDeck = PlayDeck.CreateDeck(amountDecks);
    PlayDeck.shuffle(); // Shuffle the deck


    std::cout << PlayDeck.Cards[0].toString() << std::endl;
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
    std::cout << PlayDeck.Cards[0].toString() << std::endl;
}


