//
// Created by erykl on 4/6/2020.
//
#include "BetHistory.h"
void BetHistory::clearHistory() {
    history.clear();
};

void BetHistory::addBet(Bet bet) {
    history.push_back(bet);
};

int BetHistory::getCount() {
    return history.size();
};

Bet BetHistory::getBet(int n) {
    return history.at(n);
};