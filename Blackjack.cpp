
#include "Blackjack.h"
#include <iostream>

Blackjack::Blackjack() {
    // Initialization of the game
    //Declaring variables
    int amountDecks = 0;
    int PlayerScore = 0;
    int DealerScore = 0;
    bool Bust = false;
    int Money = 1000;
    int Bet = 0;
    bool Playing = true;
    char ContinuePlaying;
    bool WrongInput = false;

    // Ask user for amount of decks they want to use
    std::cout << "Enter the amount of decks you want to play with: " << std::endl;
    std::cin >> amountDecks;

    // Call function CreateDeck to create deck based on amount of decks player wants to use
    Deck PlayDeck;
    PlayDeck = PlayDeck.CreateDeck(amountDecks);
    PlayDeck.shuffle(); // Shuffle the deck


    //Run all the functions as long as the player wants to pla
    while(Playing){
        BeginGame(Money, PlayDeck);
        Player(PlayDeck, Money);
        Dealer(DealerScore, PlayDeck, Bust);
        Endgame(PlayerScore, DealerScore, Bet, Money);


        do {
            std::cout << "Do you want to continue playing? (y/n)" << std::endl;
            std::cin >> ContinuePlaying;
            if (ContinuePlaying == 'n') {
                Playing = false;
                WrongInput = false;
            } else if (ContinuePlaying == 'y'){

            } else{
                std::cout << "Please enter either 'y' of 'n'.";
                WrongInput = true;
            }
        }while(WrongInput);
    }


    std::cout<<"Thanks for playing!";
}


/*
 * The BeginGame Function:
 * Create the Bet, deal 2 cards to the player and deal 1 card to the dealer
 */

int Blackjack::BeginGame(int Money, Deck PlayDeck) {
    int Bet, DealerScore, PlayerScore;

    //Start with asking how much the player wants to bet
    std::cout << "Your bank has " << Money << std::endl;
    std::cout << "How much do you want to bet? " << std::endl;
    std::cin >> Bet;

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

    return 0;
}


/*
 * The Player Function:
 * Here the player can choose what he wants to do (Hit or stand)
 */

int Blackjack::Player(Deck PlayDeck, int PlayerScore) {
    // Starts a player turn, takes the deck and score as input

    // Declare variables
    bool PlayerTurn = true;
    char HitStand;
    bool Bust;
    //int DealerScore;

    // Keep
    while(PlayerTurn) {
        std::cout << "Do you want to stand or hit (s/h)? " << std::endl;
        std::cin >> HitStand;

        // Check input of player
        if (HitStand == 's') {
            // When stand stop loop and let dealer play
            PlayerTurn = false;
        } else if (HitStand == 'h') {
            // When player hits display next card
            std::cout << "Your new card is: " << PlayDeck.Cards[0].toString() << std::endl;
            PlayerScore = PlayerScore + PlayDeck.Cards[0].toValue();
            PlayDeck.Cards.erase(PlayDeck.Cards.begin());
            std::cout << "Your new score is: " << PlayerScore << std::endl;
            if (PlayerScore > 21) {
                std::cout << "Bust! Your score is above 21" << std::endl;
                Bust = true;
                break;
            }

        } else {
            std::cout << "False input, please enter a hit (h) or a stand (s)";
        }
    }
    return 0;
}


/*
 * The Dealer Function:
 * Here the dealer gets cards until his score is score is higher than or equal to 17
 */

int Blackjack::Dealer(int DealerScore, Deck PlayDeck, bool Bust) {
    // Dealer function
    if(Bust != true) {
        do {
            std::cout << "The dealers new card is: " << PlayDeck.Cards[0].toString() << std::endl;
            DealerScore = DealerScore + PlayDeck.Cards[0].toValue();
            std::cout << "The dealers score is: " << DealerScore << std::endl;
            PlayDeck.Cards.erase(PlayDeck.Cards.begin());
        } while (DealerScore <= 17);
    }

    return 0;
}


/*
 * The Endgame Function:
 * Here it is decided who wins the game and the player wins or loses his bet
 */

int Blackjack::Endgame(int PlayerScore, int DealerScore, int Bet, int Money) {

    if (DealerScore > 21) {
        std::cout << "The dealer busts! You double your bet! " << std::endl;
        Money = Money + Bet;
    } else if (DealerScore == PlayerScore) {
        std::cout << "You got the same score as the dealer! Your bet stays!" << std::endl;
    } else if (DealerScore > PlayerScore) {
        std::cout << "The dealer got a higher score! Your lose your bet!" << std::endl;
        Money = Money - Bet;
    } else if (DealerScore < PlayerScore) {
        std::cout << "You got a higher score than the dealer! Your double your bet!" << std::endl;
        Money = Money + Bet;
    }




    return Money;

}