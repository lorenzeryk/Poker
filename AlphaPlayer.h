//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_ALPHAPLAYER_H
#define POKER_ALPHAPLAYER_H
#include "Player.h"
#include <iostream>

using namespace std;

class AlphaPlayer : public Player {
public:
    AlphaPlayer(int id, int chips): Player(id, chips){
        this->id = id;
        this->chips = chips;
    }

    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot);

private:
    int id;
    int chips;
};


#endif //POKER_ALPHAPLAYER_H
