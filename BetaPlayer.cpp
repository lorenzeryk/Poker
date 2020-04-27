//
// Created by erykl on 4/6/2020.
//

#include "BetaPlayer.h"
int BetaPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
    int betaScore = getHand().evaluate();
    int opponentScore = opponent.getVisible().evaluate();
    int averageCardValue = (betaScore + opponentScore) / (getHand().getCount() + opponent.getVisible().getCount());
    int bet = 0;

    if (betaScore > opponentScore) {
        //bet aggression based on how far ahead
        if (betaScore > (opponentScore + static_cast<int>(1.5*averageCardValue))) {
            bet = bet2player + 10; //big lead. Very aggressive play style
        } else if (betaScore > (opponentScore + averageCardValue)) {
            bet = bet2player + rand() % (8-4+1) + 4; //medium lead. Moderately aggressive bet
        } else bet = bet2player + rand() % (4-1+1) + 1; //small lead. Conservative play
    } else { //if behind cut losses and fold
        bet = 0;
    }

    if (bet > (bet2player + 10)) bet = bet2player + 10;
    if (!canRaise) bet = min(bet, bet2player);
    return bet;
}