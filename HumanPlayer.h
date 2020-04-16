//
// Created by erykl on 4/6/2020.
//
//TODO
#ifndef POKER_HUMANPLAYER_H
#define POKER_HUMANPLAYER_H
#include "Player.h"
#include <iostream>
using namespace std;

class HumanPlayer : public Player {
public:
    HumanPlayer(int id, int chips): Player(id, chips){
        this->id = id;
        this->chips = chips;
    }
    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot);

private:
    int id;
    int chips;
};

#endif //POKER_HUMANPLAYER_H
