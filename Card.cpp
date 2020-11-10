
#include "Card.h"

// Returns the value and type of card in string format
std::string Card::toString() {

    std::string vc, cc,card_string; // value card, color card, complete string of card

    // Determine the value of the card
    switch(value) {
        case CardValue::Ace:
            vc = "ACE";
            break;
        case CardValue::Two:
            vc = "2";
            break;
        case CardValue::Three:
            vc = "3";
            break;
        case CardValue::Four:
            vc = "4";
            break;
        case CardValue::Five:
            vc = "5";
            break;
        case CardValue::Six:
            vc = "6";
            break;
        case CardValue::Seven:
            vc = "7";
            break;
        case CardValue::Eight:
            vc = "8";
            break;
        case CardValue::Nine:
            vc = "9";
            break;
        case CardValue::Ten:
            vc = "10";
            break;
        case CardValue::Jack:
            vc = "JACK";
            break;
        case CardValue::Queen:
            vc = "QUEEN";
            break;
        case CardValue::King:
            vc = "KING";
            break;
    }

    // Determine the color of the card
    switch (color) {
        case CardColor::Diamonds:
            cc = "Diamonds";
            break;
        case CardColor::Clubs:
            cc = "Clubs";
            break;
        case CardColor::Hearts:
            cc = "Hearts";
            break;
        case CardColor::Spades:
            cc = "Spades";
            break;
    }

    // Combine value of card + color of card and return it
    card_string = vc + " of " + cc;
    return card_string;
}

// Returns the value of the card as an integer
int Card::toValue() {

    int cv;  // card value

    // Determine the value of the card
    switch(value) {
        case CardValue::Ace:
            cv = 11;
            break;
        case CardValue::Two:
            cv = 2;
            break;
        case CardValue::Three:
            cv = 3;
            break;
        case CardValue::Four:
            cv = 4;
            break;
        case CardValue::Five:
            cv = 5;
            break;
        case CardValue::Six:
            cv = 6;
            break;
        case CardValue::Seven:
            cv = 7;
            break;
        case CardValue::Eight:
            cv = 8;
            break;
        case CardValue::Nine:
            cv = 9;
            break;
        case CardValue::Ten:
            cv = 10;
            break;
        case CardValue::Jack:
            cv = 10;
            break;
        case CardValue::Queen:
            cv = 10;
            break;
        case CardValue::King:
            cv = 10;
            break;
    }
    // returns the card value
    return cv;
}
