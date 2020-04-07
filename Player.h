//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H


#include "Hand.h"
#include "BetHistory.h"

class Player {
public:
    Player(int id, int chips);
    virtual int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) = 0;
    int getID();
    void clearHand();
    void dealCard(Card c);
    Hand getHand();
    void addChips(int chips);
    int getChips();
private:
    Hand hand;
    int id;
    int chips;
};


#endif //POKER_PLAYER_H
