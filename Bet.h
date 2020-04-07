//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_BET_H
#define POKER_BET_H


class Bet {
public:
    Bet(int amount, int player);
    int getPlayer();
    int getAmount();
private:
    int amount;
    int player;
};


#endif //POKER_BET_H
