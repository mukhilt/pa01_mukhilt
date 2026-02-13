// card.h
// Author: Mukhil Thavathiru Murugan
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
class Card {
private:
    char suit;
    int value;
public:
    Card();
    Card(char suit, int value);
    bool operator<(const Card &c) const;
    bool operator==(const Card &c) const;
    bool operator>(const Card &c) const;

    friend ostream &operator<<(ostream &os, const Card &c);
};
#endif