//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_HUMANPLAYER_H
#define POKER_HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(int id, int chips): Player(id, chips){

    }
    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
        return 0;
    }
};


#endif //POKER_HUMANPLAYER_H
