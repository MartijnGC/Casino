
#include "Card.h"
#include <string>
#include <ctime>

std::string Card(){
    // Define variables
    std::string numbers[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    std::string types[] = {"Spades","Hearts", "Diamonds", "Clubs"};
    std::string card;

    // Set random number stream
    srand(std::time(nullptr));

    // Set random number for numbers and types
    int numRand = rand() %12;
    int typeRand = rand() %3;

    // get card
    card = numbers[numRand] + " of " + types[typeRand];
    return card;
}