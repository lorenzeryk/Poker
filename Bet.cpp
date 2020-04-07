//
// Created by erykl on 4/6/2020.
//

#include "Bet.h"
Bet::Bet(int amount, int player) {
    this->amount = amount;
    this->player = player;
}

int Bet::getAmount() {
    return amount;
}

int Bet::getPlayer() {
    return player;
}