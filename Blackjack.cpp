
#include "Blackjack.h"
#include <iostream>
#include <string>


Blackjack::Blackjack() {
    // Initialization of the game
    //Declaring variables
    int amountDecks = 0;
    int Money = 1000;
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


    //Run all the functions as long as the player wants to play
    while(Playing){
    //    int PlayerScore = 0;
    //    int PlayerScore2 = 0;
    //    int DealerScore = 0;
      //  bool Bust = false;
        //bool BlackJack = false;
       // int valCard1;
      //  int valCard2;


    //    BeginGame(Bet, Money, PlayDeck, PlayerScore, DealerScore, BlackJack, valCard1, valCard2);
    //    if(!BlackJack) {
    //        Player(PlayDeck, PlayerScore, PlayerScore2, Bust, Bet, valCard1, valCard2);
    //
    //            Dealer(DealerScore, PlayDeck);
    //        }
    //    }
    //    Endgame(PlayerScore, DealerScore, Bet, Money, BlackJack);

        PlayBlackJack(Money,PlayDeck);
        do {
            if(Money < 5){
                std::cout << "You do not have enough money to play anymore." << std::endl;
                Playing = false;
            }
            std::cout << "Do you want to continue playing? (y/n)" << std::endl;
            std::cin >> ContinuePlaying;

            if (ContinuePlaying == 'n') {
                Playing = false;
                WrongInput = false;
            } else if (ContinuePlaying == 'y'){
                Playing = true;
                WrongInput = false;
            } else{
                std::cout << "Please enter either 'y' of 'n'.";
                WrongInput = true;
            }
        }while(WrongInput);
    }
    std::cout<<"Thanks for playing!";
}


void Blackjack::PlayBlackJack(int &Money, Deck &PlayDeck) {


/*-----------------------------------------------------------------------------------------------------
 * THE BEGINNING OF THE GAME:
 * --------------------------------------------------------------------------------------------------*/


    //Declaration of variables
    double Bet;
    bool ValidBet = false;
    int PlayerScore, PlayerScore2, DealerScore;
    bool BlackJack;
    bool Bust = false;
    int valCard1, valCard2;
    std::string NameCard1, NameCard2;

    // Creating the bet
    std::cout << "Your bank has " << Money << std::endl;
    std::cout << "How much do you want to bet? The minimum bet is 5." << std::endl;

    // Check whether the bet entered is valid
    do {
        std::cin >> Bet;

        while (true) {   //From internet
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter an integer to place your bet" << std::endl;
                std::cin >> Bet;
            }
            if (!std::cin.fail())
                break;
        }

        if (Bet < 5) {
            std::cout << "The minimum bet is 5. Please enter a valid bet." << std::endl;
            ValidBet = false;
        } else if (Money - Bet >= 0) {
            ValidBet = true;
        } else {
            std::cout << "You don't have enough money for this bet." << std::endl;
        }
    } while (!ValidBet);


    // Dealing the cards
    // Set initial score (first two cards of the deck)
    PlayerScore = PlayDeck.Cards[0].toValue() + PlayDeck.Cards[1].toValue();
    if (PlayerScore == 21) {
        BlackJack = true;
    } else {
        BlackJack = false;
    }

    // Output cards and score to player
    std::cout << "Your cards are: " << PlayDeck.Cards[0].toString() << " and " << PlayDeck.Cards[1].toString()
              << std::endl;
    std::cout << "Your score is: " << PlayDeck.Cards[0].toValue() + PlayDeck.Cards[1].toValue() << std::endl;

    // Save the value and name of the individual cards
    valCard1 = PlayDeck.Cards[0].toValue();
    valCard2 = PlayDeck.Cards[1].toValue();
    NameCard1 = PlayDeck.Cards[0].toString();
    NameCard2 = PlayDeck.Cards[1].toString();

    // Erases the two cards dealt from the deck
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());

    // Output card of the dealer to player, save value to dealer score and remove card from pile
    std::cout << "The dealers card is: " << PlayDeck.Cards[0].toString() << std::endl;
    DealerScore = PlayDeck.Cards[0].toValue();
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());



/* -----------------------------------------------------------------------------------------------------
 * PLAYING THE GAME: HERE THE USER CAN MAKE HIS/HER CHOICES
 * ---------------------------------------------------------------------------------------------------*/

// Declaration of variables
    char ChoiceSplit;
    bool Split = false;
    bool AskAgain = false;
    bool DoubledDown = false;
    bool PlayerTurn = true;
    char PlayerAction;
    int CardSet = 1;
    int ScoreSet1 = 0;
    int ScoreSet2 = 0;
    int Turn = 1;
    bool Bust1 = false;
    bool Bust2 = false;

    if (!BlackJack) { //If the player hits blackjack right away no cards need to be dealt to the player


        //Allow the user to split in case of two similar cards
        //NameCard1[0] = NameCard2[0];   to check the split function
        if (NameCard1[0] == NameCard2[0]) {
            std::cout << "You have two cards that are the same. Do you want to split (y/n)?" << std::endl;
            do {
                std::cin >> ChoiceSplit;
                if (ChoiceSplit == 'y') {
                    Split = true;
                    std::cout << "Your new cards are: " << PlayDeck.Cards[0].toString() << " and "
                              << PlayDeck.Cards[1].toString() << std::endl;
                    PlayerScore = valCard1 + PlayDeck.Cards[0].toValue();
                    PlayerScore2 = valCard2 + PlayDeck.Cards[1].toValue();
                    std::cout << "The score of your first set is: " << PlayerScore << std::endl;
                    std::cout << "The score of your second set is: " << PlayerScore2 << std::endl;

                    // Erases the two cards dealt from the deck
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());

                } else if (ChoiceSplit == 'n') {
                    AskAgain = false;
                } else {
                    std::cout << "Please enter yes (y) or no (n).";
                    AskAgain = true;
                }
            } while (AskAgain);
        }

        do { //Run it multiple times if the player splits

            // Keep playing as long as the player hits or until he/she busts
            while (PlayerTurn) {

                //Display this only if the player split
                if (Split && CardSet == 1) {
                    std::cout << "On your first set: ";
                } else if (Split && CardSet == 2) {
                    std::cout << "On your second set: ";
                }

                // Ask what the player w
                if (!DoubledDown && Turn == 1) {
                    std::cout << "Do you want to stand, hit or double down (s/h/d)? " << std::endl;
                } else {
                    std::cout << "Do you want to stand or hit (s/h)? " << std::endl;
                }
                std::cin >> PlayerAction;

                // Check input of player
                if (PlayerAction == 's') {
                    // If stand: stop loop and let dealer play
                    PlayerTurn = false;
                } else if (PlayerAction == 'h') {

                    // Display next card
                    std::cout << "Your new card is: " << PlayDeck.Cards[0].toString() << std::endl;
                    PlayerScore = PlayerScore + PlayDeck.Cards[0].toValue();
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
                    std::cout << "Your new score is: " << PlayerScore << std::endl;

                    if (PlayerScore > 21) {
                        std::cout << "Bust! Your score is above 21" << std::endl;
                        Bust = true;
                        PlayerTurn = false;
                    }
                } else if (PlayerAction == 'd' && !DoubledDown && Turn == 1) {

                    Bet = Bet * 2;
                    DoubledDown = true;
                    // Display next card
                    std::cout << "Your new card is: " << PlayDeck.Cards[0].toString() << std::endl;
                    PlayerScore = PlayerScore + PlayDeck.Cards[0].toValue();
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
                    std::cout << "Your new score is: " << PlayerScore << std::endl;

                    if (PlayerScore > 21) {
                        std::cout << "Bust! Your score is above 21" << std::endl;
                        Bust = true;
                        PlayerTurn = false;;
                    }
                } else {
                    std::cout << "False input." << std::endl;
                }

                if (PlayerScore == 21) {
                    std::cout << "You hit BlackJack!" << std::endl;
                    PlayerTurn = false;
                }

                Turn++;
            }
            if (Split && CardSet == 1) {
                CardSet = 2;
                PlayerTurn = true;
                ScoreSet1 = PlayerScore;
                PlayerScore = PlayerScore2;
                DoubledDown = false;
                Turn = 1;
                if (Bust) {
                    Bust1 = true;
                    Bust = false;
                }
            } else if (Split && CardSet == 2) {
                CardSet = 1;
                ScoreSet2 = PlayerScore;
                PlayerTurn = false;
                if (Bust && !Bust1) {
                    Bust2 = true;
                    Bust = false;
                }
                break;
            }
        } while (Split);

        if (Bust1 && Bust2) {
            Bust = true;
        }
    }


//* -----------------------------------------------------------------------------------------------------
// * THE DEALER GETS DEALT CARDS
// -----------------------------------------------------------------------------------------------------*/


    if (!Bust) {
        do {
            std::cout << "The dealers new card is: " << PlayDeck.Cards[0].toString() << std::endl;
            DealerScore = DealerScore + PlayDeck.Cards[0].toValue();
            PlayDeck.Cards.erase(PlayDeck.Cards.begin());
        } while (DealerScore <= 17);

        std::cout << "The dealers score is: " << DealerScore << std::endl;
    }


/* -----------------------------------------------------------------------------------------------------
 * THE END OF THE GAME
 -----------------------------------------------------------------------------------------------------*/

    bool Done = false;

    if (BlackJack) {
        std::cout << "You hit BlackJack right away!" << std::endl;
        Money = Money + 1.5 * Bet;
    } else if(Bust){
        Money = Money - Bet;
        if(Split){
            Money = Money - 2*Bet;
        }
    }else{
        do {
            if (Split && CardSet == 1 && !Bust1){
                PlayerScore = ScoreSet1;
                std::cout << "For your first set: ";
                CardSet = 2;
            } else if (Split && CardSet == 2 && !Bust1) {
                PlayerScore = ScoreSet2;
                std::cout << "For your second set: ";
                Done = true;
            }else{
                Done = true;
            }

            if (PlayerScore > 21) {

            } else if (DealerScore > 21) {
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

        } while (!Done);
    }
}