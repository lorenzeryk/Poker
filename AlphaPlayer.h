//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_ALPHAPLAYER_H
#define POKER_ALPHAPLAYER_H
#include "Player.h"
//TODO Alpha Rules
class AlphaPlayer : public Player {
public:
    AlphaPlayer(int id, int chips): Player(id, chips){

    }

    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
        return 0;
    }
};


#endif //POKER_ALPHAPLAYER_H
