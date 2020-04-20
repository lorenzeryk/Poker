//
// Created by erykl on 4/6/2020.
//

#include "AlphaPlayer.h"
int AlphaPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
    int delta = getHand().evaluate() - opponent.getVisible().evaluate();
    bool lastRound = false;
    int bet = 0;
    if (getHand().getCount() == 5) lastRound = true;

    if (!lastRound) {
        if (bh.getCount() == 0) {
            if (delta > 10) {
                bet = 10; //raise 10
            } else if (delta > 5) {
                bet = 5; //raise 5
            } else if (delta > 0) {
                bet = 1; //raise 1
            } else {
                bet = 0; //call
            }
        } else {
            int pot_factor = pot / 10;
            if (bet2player == 0) {
                if (delta > (5 - pot_factor)) {
                    bet = 10; //raise 10
                } else if (delta > (0 - pot_factor)) {
                    bet = 1; //raise 1
                } else {
                    bet = 0; //call
                }
            } else if (bet2player < (1 + pot_factor*2)) {
                if (delta > (8 - pot_factor)) {
                    bet = bet2player + 10; //raise 10
                } else if (delta > (-2 - pot_factor)) {
                    bet = bet2player + 1; //raise 1
                } else if (delta > (-4 - pot_factor)) {
                    bet = bet2player; //call
                } else {
                    bet = 0; //fold
                }
            } else {
                if (delta > (10 - pot_factor)) {
                    bet = bet2player + 10; //raise 10
                } else if (delta > (0 - pot_factor)) {
                    bet = bet2player + 1; //raise 1
                } else if (delta > (-2 - pot_factor)) {
                    bet = bet2player; //call
                } else {
                    bet = 0; //fold
                }
            }
        }
    } else {
        if (bh.getCount() == 0) {
            if (delta > 10) {
                bet = 10;  //raise 10
            } else if (delta > 5) {
                bet = 5; //raise 5
            } else {
                bet = 0; //call
            }
        } else {
            int pot_factor = pot / 10;
            if (bet2player == 0) {
                if (delta > (10 - pot_factor)) {
                    bet = 10; //raise 10
                } else {
                    bet = 0; //call
                }
            } else if (bet2player < (1 + pot_factor * 2)) {
                if (delta > (6 - pot_factor)) {
                    bet = bet2player + 10; //raise 10
                } else if (delta > 2) {
                    bet = bet2player; //call
                }
                else {
                    bet = 0; //fold
                }
            } else {
                if (delta > (8 - pot_factor)) {
                    bet = bet2player + 10; //raise 10
                } else if (delta > 4) {
                    bet = bet2player; //call
                } else {
                    bet = 0; //fold
                }
            }
        }
    }
    if (!canRaise) bet = min(bet, bet2player);
    return bet;
}