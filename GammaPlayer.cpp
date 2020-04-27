//
// Created by erykl on 4/26/2020.
//

#include "GammaPlayer.h"
int GammaPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
    int betaScore = getHand().evaluate();
    int opponentScore = opponent.getVisible().evaluate();
    int averageCardValue = (betaScore + opponentScore) / (getHand().getCount() + opponent.getVisible().getCount()); //rough estimate of opponents hidden card
    int bet = 0;

    if (betaScore > (opponentScore + 1.6*averageCardValue)) bet = bet2player + 10; //high probability of lead so play aggressive
    else bet = 0; //most likely losing so cut losses and fold

    if (bet > (bet2player + 10)) bet = bet2player + 10;
    if (!canRaise) bet = min(bet, bet2player);
    return bet;
}