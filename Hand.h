//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H
#include "Card.h";

class Hand {
public:
    void clear();
    void addCard(Card card);
    int getCount();
    Card getCard(int n);
    Hand getVisible();
    int evaluate();
private:

};


#endif //POKER_HAND_H
