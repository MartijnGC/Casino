#ifndef CASINO_CARD_H
#define CASINO_CARD_H
#include <string>

enum class CardValue : int {
    Ace = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
};

enum class CardColor {
    Spades,
    Hearts,
    Diamonds,
    Clubs,
    Last
};

class Card{
public:
    Card(CardValue value, CardColor color){
        this->value = value; // this, is a pointer to the object it refers to
        this->color = color;
    }
    CardValue value;
    CardColor color;

    std::string toString();
    int toValue();
};

#endif //CASINO_CARD_H
