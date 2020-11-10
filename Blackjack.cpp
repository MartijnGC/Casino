
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

    // Welcome player to blackjack
    std::cout << "Welcome to: \n" << std::endl;
    std::cout << "'||''|.   '||                  '||         '||'                 '||     \n"
                 " ||   ||   ||   ....     ....   ||  ..      ||   ....     ....   ||  .. \n"
                 " ||'''|.   ||  '' .||  .|   ''  || .'       ||  '' .||  .|   ''  || .'  \n"
                 " ||    ||  ||  .|' ||  ||       ||'|.       ||  .|' ||  ||       ||'|.  \n"
                 ".||...|'  .||. '|..'|'  '|...' .||. ||.  ||.|'  '|..'|'  '|...' .||. ||.\n"
                 "__________________________________________________________________________\n"<< std::endl;

    // Ask user for amount of decks they want to use
    std::cout << "Enter the amount of decks you want to play with: " << std::endl;
    std::cin >> amountDecks;

    // Call function CreateDeck to create deck based on amount of decks player wants to use
    Deck PlayDeck;
    PlayDeck = PlayDeck.CreateDeck(amountDecks);
    PlayDeck.shuffle(); // Shuffle the deck


    //Run all the functions as long as the player wants to play
    while(Playing){

        // Play game
        PlayBlackJack(Money,PlayDeck);

        //  Check conditions and ask player if he wants to play again
        std::cout << "__________________________________________________________________________\n"<< std::endl;
        do {
            if(Money < 5){
                std::cout << "You do not have enough money to play anymore." << std::endl;
                Playing = false;
                break;
            }
            if(PlayDeck.Cards.size() <= 15){
                std::cout << "There are not enough cards left in the deck to play with." << std::endl;
                Playing = false;
                break;
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
    } // Playing = true

    // When player is done playing end game and show money left
    std::cout<<"You left the casino with " << Money << " in the bank." << std::endl;
    std::cout<<"Thanks for playing!";
}



void Blackjack::PlayBlackJack(int &Money, Deck &PlayDeck) {

/*-----------------------------------------------------------------------------------------------------
 * PLACE BETS:
 * --------------------------------------------------------------------------------------------------*/

    //Declaration of variables
    double Bet;
    bool ValidBet = false;
    int PlayerScore, PlayerScore2, DealerScore;
    bool BlackJack;
    bool Bust = false;
    int valCard1, valCard2;
    std::string NameCard1, NameCard2, NewCardName;
    int numAce = 0;

    // Creating the bet
    std::cout << "\nYour bank has " << Money << std::endl;
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

/*-----------------------------------------------------------------------------------------------------
 * DEAL CARDS:
 * --------------------------------------------------------------------------------------------------*/

    // Set initial player score (first two cards of the deck)
    PlayerScore = PlayDeck.Cards[0].toValue() + PlayDeck.Cards[1].toValue();

    // Check if score is blackjack (21 points)
    if (PlayerScore == 21) {
        BlackJack = true;
    } else {
        BlackJack = false;
    }

    // Output cards and score to player
    std::cout << "\nYour cards are: " << PlayDeck.Cards[0].toString() << " and " << PlayDeck.Cards[1].toString()
              << std::endl;
    std::cout << "Your score is: " << PlayDeck.Cards[0].toValue() + PlayDeck.Cards[1].toValue() << std::endl;

    // Save the value and name of the individual cards
    valCard1 = PlayDeck.Cards[0].toValue();
    valCard2 = PlayDeck.Cards[1].toValue();
    NameCard1 = PlayDeck.Cards[0].toString();
    NameCard2 = PlayDeck.Cards[1].toString();

    //Check whether the player has aces
     if(NameCard1[0] == 'A' && NameCard2[0] == 'A'){
        numAce = 2;
    } else if(NameCard1[0] == 'A' || NameCard2[0] == 'A'){
        numAce = 1;
    }

    // Erases the two cards dealt from the deck
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
    PlayDeck.Cards.erase(PlayDeck.Cards.begin());

    // Output card of the dealer to player, save value to dealer score and remove card from pile
    std::cout << "\nThe dealers card is: " << PlayDeck.Cards[0].toString() << std::endl;
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
    int numAce1 = 0;
    int numAce2 = 0;

    if (!BlackJack) { //If the player hits blackjack right away no cards need to be dealt to the player

        //Allow the user to split in case of two similar cards
        if (NameCard1[0] == NameCard2[0]) {
            std::cout << "\nYou have two cards that are the same. Do you want to split (y/n)?" << std::endl;
            do {
                std::cin >> ChoiceSplit;

                // Player wants to split
                if (ChoiceSplit == 'y') {
                    Split = true;
                    std::cout << "\nYour new cards are: " << PlayDeck.Cards[0].toString() << " and "
                              << PlayDeck.Cards[1].toString() << std::endl;
                    PlayerScore = valCard1 + PlayDeck.Cards[0].toValue();
                    PlayerScore2 = valCard2 + PlayDeck.Cards[1].toValue();

                    //Save in which set there are aces
                    if(numAce == 2){
                        numAce1 = 1;
                        numAce2 = 1;
                    }

                    if(PlayDeck.Cards[0].toValue() == 11){
                        numAce1++;
                    } else if(PlayDeck.Cards[1].toValue() == 11){
                        numAce2++;
                    }

                    // When player has two aces, make substract 10 (one ace becomes a 1)
                    if(PlayerScore == 22) {
                        std::cout << "\nThe score of your first set is: " << PlayerScore - 10<< std::endl;
                    } else{
                        std::cout << "\nThe score of your first set is: " << PlayerScore << std::endl;
                    }
                    if(PlayerScore2 == 22) {
                        std::cout << "\nThe score of your second set is: " << PlayerScore2 - 10<< std::endl;
                    } else{
                        std::cout << "\nThe score of your second set is: " << PlayerScore2 << std::endl;
                    }

                    // Erases the two cards dealt from the deck
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());

                    AskAgain = false;

                } else if (ChoiceSplit == 'n') {
                    AskAgain = false;
                } else {
                    std::cout << "Please enter yes (y) or no (n).";
                    AskAgain = true;
                }
            } while (AskAgain);
        } // Split cards

        // Stand, hit or double down
        do { //Run it multiple times if the player splits
            // Keep playing as long as the player hits or until he/she busts
            while (PlayerTurn) {
                //Display this only if the player split
                if (Split && CardSet == 1) {
                    std::cout << "\nOn your first set: ";
                    numAce = numAce1;
                } else if (Split && CardSet == 2) {
                    std::cout << "\nOn your second set: ";
                }

                // Ask what the player wants to do
                if (!DoubledDown && Turn == 1) {
                    std::cout << "\nDo you want to stand, hit or double down (s/h/d)? " << std::endl;
                } else {
                    std::cout << "\nDo you want to stand or hit (s/h)? " << std::endl;
                }
                std::cin >> PlayerAction;

                // Check input of player
                if (PlayerAction == 's') { // Player stands
                    // If stand: stop loop and let dealer play
                    PlayerTurn = false;
                } else if (PlayerAction == 'h') {  // Player hits
                    // If player hits, draw a new card and add to score
                    // Display next card
                    std::cout << "\nYour new card is: " << PlayDeck.Cards[0].toString() << std::endl;
                    PlayerScore = PlayerScore + PlayDeck.Cards[0].toValue();
                    NewCardName = PlayDeck.Cards[0].toString();
                    if(NewCardName[0] == 'A'){
                        numAce++;
                    }
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
                    std::cout << "Your new score is: " << PlayerScore << std::endl;

                    // Check if score is over 21, if so player is bust when no aces left
                    if (PlayerScore > 21 && numAce == 0) {
                        std::cout << "Bust! Your score is above 21" << std::endl;
                        Bust = true;
                        PlayerTurn = false;
                    } else if (PlayerScore > 21 && numAce != 0){
                        std::cout << "You went above 21, so your Ace is now worth 1 point" << std::endl;
                        PlayerScore = PlayerScore - 10;
                        std::cout << "Your new score is: " << PlayerScore << std::endl;
                        numAce--;
                    }
                } else if (PlayerAction == 'd' && !DoubledDown && Turn == 1) { // Player doubles down
                    Bet = Bet * 2; // increase bet
                    DoubledDown = true;

                    // Display next card
                    std::cout << "\nYour new card is: " << PlayDeck.Cards[0].toString() << std::endl;
                    PlayerScore = PlayerScore + PlayDeck.Cards[0].toValue();
                    NewCardName = PlayDeck.Cards[0].toString();
                    if(NewCardName[0] == 'A'){
                        numAce++;
                    }
                    PlayDeck.Cards.erase(PlayDeck.Cards.begin());
                    std::cout << "Your new score is: " << PlayerScore << std::endl;

                    // Check if score is over 21, if so player is bust when no aces left
                    if (PlayerScore > 21 && numAce == 0) {
                        std::cout << "Bust! Your score is above 21"<< std::endl;
                        Bust = true;
                    }else if (PlayerScore > 21 && numAce != 0){
                        std::cout << "You went above 21, so your Ace is now worth 1 point" << std::endl;
                        PlayerScore = PlayerScore - 10;
                        std::cout << "Your new score is: " << PlayerScore << std::endl;
                        numAce--;
                    }
                    PlayerTurn = false;
                } else {
                    std::cout << "False input." << std::endl;
                }

                if (PlayerScore == 21) {
                    std::cout << "You hit BlackJack!" << std::endl;
                    PlayerTurn = false;
                }

                Turn++;
            }
            // When player has split their cards change to the second set of cards
            if (Split && CardSet == 1) {
                CardSet = 2;
                PlayerTurn = true;
                ScoreSet1 = PlayerScore;
                PlayerScore = PlayerScore2;
                DoubledDown = false;
                Turn = 1;
                numAce = numAce2;

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

    // When player hasn't busted deal cards for dealer
    if (!Bust) {
        do {
            std::cout << "The dealers new card is: " << PlayDeck.Cards[0].toString() << std::endl;
            DealerScore = DealerScore + PlayDeck.Cards[0].toValue();
            PlayDeck.Cards.erase(PlayDeck.Cards.begin());
        } while (DealerScore <= 17);  // Deal cards until dealer has a score that is 17 or bigger
        // Display dealers final score
        std::cout << "The dealers score is: " << DealerScore << std::endl;
    }


/* -----------------------------------------------------------------------------------------------------
 * THE END OF THE GAME
 -----------------------------------------------------------------------------------------------------*/

    bool Done = false;
    // Check if player has a blackjack (21) or busted
    if (BlackJack) {
        std::cout << "You hit BlackJack right away!" << std::endl;
        Money = Money + 1.5 * Bet;
        std::cout << "You've won: " << 1.5*Bet << std::endl;
    } else if(Bust){
        Money = Money - Bet;
        std::cout << "You've lost: " << Bet << std::endl;
        if(Split){
            Money = Money - 2*Bet;
            std::cout <<"And because of the split you've lost: " << Bet << std::endl;
        }
    }else{ // Chck if player score is higher, lower or equal to dealers score.
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
            } else if (DealerScore > 21) { // When dealer has busted
                std::cout << "\nThe dealer busts! You double your bet! " << std::endl;
                Money = Money + Bet;
                std::cout << "You've won: " << Bet << std::endl;

            } else if (DealerScore == PlayerScore) { // When dealer has score equal to player
                std::cout << "\nYou got the same score as the dealer! Your bet stays!" << std::endl;

            } else if (DealerScore > PlayerScore) { // When dealer scored higher than player
                std::cout << "\nThe dealer got a higher score! You lose your bet!" << std::endl;
                Money = Money - Bet;
                std::cout << "You've lost: " << Bet << std::endl;

            } else if (DealerScore < PlayerScore) { // When dealer scored lower than player
                std::cout << "\nYou got a higher score than the dealer! Your double your bet!" << std::endl;
                Money = Money + Bet;
                std::cout << "You've won: " << Bet << std::endl;
            }

        } while (!Done);
    }
}
