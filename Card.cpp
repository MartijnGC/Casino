
#include "Card.h"
#include <string>

std::string Card::toString() {

    std::string vc, cc,card_string;

    switch(value) {
        case CardValue::Ace:
            vc = "Ace";
            break;
        case CardValue::Two:
            vc = "Two";
            break;
        case CardValue::Three:
            vc = "Three";
            break;
        case CardValue::Four:
            vc = "Four";
            break;
        case CardValue::Five:
            vc = "Five";
            break;
        case CardValue::Six:
            vc = "Six";
            break;
        case CardValue::Seven:
            vc = "Seven";
            break;
        case CardValue::Eight:
            vc = "Eight";
            break;
        case CardValue::Nine:
            vc = "Nine";
            break;
        case CardValue::Ten:
            vc = "Ten";
            break;
        case CardValue::Jack:
            vc = "Ten";
            break;
        case CardValue::Queen:
            vc = "Ten";
            break;
        case CardValue::King:
            vc = "Ten";
            break;
    }

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

    card_string = vc + " of " + cc;
    return card_string;
}

int Card::toValue() {

    int cv;

    // returns the value of the card
    switch(value) {
        case CardValue::Ace:
            cv = 1;
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

    return cv;
}

