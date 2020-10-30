#include <iostream>
#include <string>
#include <vector>
#include "Card.h"




int main() {

    Card c1 = Card(CardValue::Ace, CardColor::Hearts);
    Card c2 = Card(CardValue::Jack, CardColor::Spades);

    std::cout << c1.toString() << " , the value is: " << c1.toValue() << std::endl;
    std::cout << c2.toString() << " , the value is: " << c2.toValue() << std::endl;



    return 0;
}
