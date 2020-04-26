//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_BETAPLAYER_H
#define POKER_BETAPLAYER_H
#include "Player.h"

class BetaPlayer: public Player {
public:
    BetaPlayer(int id, int chips): Player(id, chips){
        this->id = id;
        this->chips = chips;
    }

    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot);

private:
    int id;
    int chips;
};


#endif //POKER_BETAPLAYER_H
