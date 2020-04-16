//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_BETHISTORY_H
#define POKER_BETHISTORY_H
#include "Bet.h"
#include <vector>
using namespace std;

class BetHistory {
public:
    void clearHistory();
    void addBet(Bet bet);
    int getCount();
    Bet getBet(int n);
private:
    vector<Bet> history;
};


#endif //POKER_BETHISTORY_H
