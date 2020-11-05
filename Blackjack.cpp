
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

    Turns(PlayDeck);

}

int Blackjack::Turns(Deck PlayDeck) {
    // Starts a player turn, takes the deck as an input

    // Declare variables
    bool Playing = true;
    char HitStand;
    int PlayerScore = 0, DealerScore;

    // Set initial score (first two cards of the deck)
    PlayerScore = PlayDeck.Cards[0].toValue() + PlayDeck.Cards[1].toValue();

    // Output cards and score to player
    std::cout << "Your cards are: " << PlayDeck.Cards[0].toString() << " and " << PlayDeck.Cards[1].toString() << std::endl;
    std::cout << "Your score is: " << PlayDeck.Cards[0].toValue() + PlayDeck.Cards[1].toValue() << std::endl;

    // Erases the two cards dealt from the deck
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());

    // Output card of the dealer to player, save value to dealer score and remove card from pile
    std::cout << "The dealers card is: " << PlayDeck.Cards[0].toString() << std::endl;
    DealerScore = PlayDeck.Cards[0].toValue();
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());

    // Keep
    while(Playing) {
        std::cout << "Do you want to stand or hit (s/h)? " << std::endl;
        std::cin >> HitStand;

        // Check input of player
        if (HitStand == 's') {
            // When stand stop loop and let dealer play
            Playing = false;
            Dealer(PlayerScore,DealerScore);
        }

        else if (HitStand == 'h') {
            // When player hits display next card
            std::cout << "Your new card is: " << PlayDeck.Cards[0].toString() << std::endl;
            PlayerScore = PlayerScore + PlayDeck.Cards[0].toValue();
            PlayDeck.Cards.erase(PlayDeck.Cards.begin());
            std::cout << "Your new score is: " << PlayerScore << std::endl;
            if (PlayerScore > 21){
                std::cout << "Bust! Your score is above 21" << std::endl;
                break;
            }

        } else {
            std::cout << "False input, please enter a hit (h) or a stand (s)";
        }
    }

    std::cout << "Thanks for playing! ";
    return 0;
}


int Blackjack::Dealer(int PlayerScore, int DealerScore) {

    return 0;
}

