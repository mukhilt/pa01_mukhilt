// card.cpp
// Author: Mukhil Thavathiru Murugan
// Implementation of the classes defined in card.h

#include "card.h"
#include <ostream>
using namespace std;

static int mapper(char suit) {
    if (suit == 'c') {
        return 0;
    }
    else if (suit == 'd') {
        return 1;
    }
    else if (suit == 's') {
        return 2;
    }
    else if (suit == 'h') {
        return 3;
    }
    return -1;
}
Card::Card() {
    suit = 'c';
    value = 1;
}
Card::Card(char suit, int value) {
    this->suit = suit;
    this->value = value;
}
bool Card::operator<(const Card &c) const {
    int thisSuitVal = mapper(this->suit);
    int otherSuitVal = mapper(c.suit);

     if (thisSuitVal != otherSuitVal) {
         bool isLessThan = thisSuitVal < otherSuitVal;
         return isLessThan;
     }
    return this->value < c.value;
}
bool Card::operator==(const Card &c) const {
    int thisSuitVal = mapper(this->suit);
    int otherSuitVal = mapper(c.suit);

    if (thisSuitVal == otherSuitVal && this->value == c.value) {
        return true;
    }
    return false;
}
bool Card::operator>(const Card &c) const {
    int thisSuitVal = mapper(this->suit);
    int otherSuitVal = mapper(c.suit);
    if (thisSuitVal != otherSuitVal) {
        bool isGreaterThan = thisSuitVal > otherSuitVal;
        return isGreaterThan;
    }
    return this->value > c.value;
}
ostream &operator<<(ostream &os, const Card &c) {
    if (c.value == 1) {
        os << c.suit << " " << "a";
    }
    else if (c.value == 11) {
        os << c.suit << " " << "j";
    }
    else if (c.value == 12) {
        os << c.suit << " " << "q";
    }
    else if (c.value == 13) {
        os << c.suit << " " << "k";
    }
    else {
        os << c.suit << " " << c.value;
    }
    return os;
}