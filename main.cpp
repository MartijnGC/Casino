#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"



int main() {

    Card c1 = Card(CardValue::Ace, CardColor::Hearts);
    Card c2 = Card(CardValue::Jack, CardColor::Spades);

    //std::cout << c1.toString() << " , the value is: " << c1.toValue() << std::endl;
    //std::cout << c2.toString() << " , the value is: " << c2.toValue() << std::endl;

    Deck d1 = Deck(1);

    std::cout << d1.Cards[24].toString() << std::endl;
    for (int i = 0; i < d1.Cards.size(); ++i) {
        std::cout << d1.Cards[i].toString() << " , the value is: " << d1.Cards[i].toValue() << std::endl;
    }



    return 0;
}
