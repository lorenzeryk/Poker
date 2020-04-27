//
// Created by erykl on 4/26/2020.
//

#ifndef POKER_GAMMAPLAYER_H
#define POKER_GAMMAPLAYER_H

#include "Player.h"

class GammaPlayer: public Player {
public:
    GammaPlayer(int id, int chips): Player(id, chips){
        this->id = id;
        this->chips = chips;
    }

    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) override;

private:
    int id;
    int chips;
};


#endif //POKER_GAMMAPLAYER_H
