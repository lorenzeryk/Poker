//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H
#include "Card.h"
#include <vector>

class Hand {
public:
    void clear();
    void addCard(Card card);
    int getCount();
    Card getCard(int n);
    Hand getVisible();
    int evaluate();
    void setCardVisible(bool visible, int n);
private:
    vector<Card> hand;
};


#endif //POKER_HAND_H
