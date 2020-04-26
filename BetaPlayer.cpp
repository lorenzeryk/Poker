//
// Created by erykl on 4/6/2020.
//

#include "BetaPlayer.h"
int BetaPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
    int betaScore = getHand().evaluate();
    int opponentScore = opponent.getVisible().evaluate();
    int averageCardValue = (betaScore + opponentScore) / (getHand().getCount() + opponent.getVisible().getCount());
    int roundNumber = getHand().getCount() - 2;
    int bet = 0;

    /*
    double probabilityHigherCard;
    int cardsAboveAveragePlayer = 0, cardsAboveAverageOpponent = 0;
    int cardsInDeck = 51 - getHand().getCount() + opponent.getCount();
    for (int i = 0; i < getHand().getCount(); i++) {
        if (getHand().getCard(i).getValue() > averageCardValue) cardsAboveAveragePlayer++;
    }

    for (int i = 0; i < opponent.getCount(); i++) {
        if (opponent.getCard(i).getValue() > averageCardValue) cardsAboveAverageOpponent++;
    }

    probabilityHigherCard = (cardsInDeck - (cardsAboveAveragePlayer + cardsAboveAverageOpponent)) / cardsInDeck;

    if (betaScore > opponentScore) {
        if (probabilityHigherCard > 0.6) {
            bet = bet2player + 4;
        } else if (betaScore > 0.5*(opponentScore + averageCardValue)) {
            //max raise. Take advantage of lead
            bet = bet2player + 8;
        }
        else {
            //call or bet depending on round number
            switch (roundNumber) {
                case 1: //first betting round
                    //aggressive raise
                    bet = bet2player + 10;
                    break;
                case 2: //second betting round
                    //conservative raise
                    bet = bet2player + 3;
                    break;
                case 3: //third betting round
                    //call
                    bet = bet2player;
                    break;
                default:
                    break;
            }
        }
    } else {
        if ((betaScore + 0.5*averageCardValue) > opponentScore) {
            //call or bet small depending on round number
            switch (roundNumber) {
                case 1: //first betting round
                    //medium aggressive bet
                    bet = bet2player + 3;
                    break;
                case 2: //second betting round
                    //very conservative bet
                    bet = bet2player + 1;
                    break;
                case 3: //third betting round
                    //call
                    bet = bet2player;
                    break;
                default:
                    break;
            }
        } else {
            //call or fold
            bet = 0;
        }
    }
    if (bet > (bet2player + 10)) bet = bet2player + 10;
    if (!canRaise) bet = min(bet, bet2player);
    return bet;
     */
/*
    if (betaScore > opponentScore) {
        if (betaScore > (opponentScore + 1.2*averageCardValue)) {
            //max raise. Take advantage of lead
            bet = bet2player + 10; //fine tuned
        }
        else {
            //call or bet depending on round number
            switch (roundNumber) {
                case 1: //first betting round
                    //aggressive raise
                    bet = bet2player + 10; //fine tuned
                    break;
                case 2: //second betting round
                    //conservative raise
                    bet = bet2player + 4; //fine tuned
                    break;
                case 3: //third betting round
                    //call
                    bet = bet2player + 1; //fine tuned
                    break;
                default:
                    break;
            }
        }
    } else {
        if ((betaScore) > opponentScore) {
            //call or bet small depending on round number
            switch (roundNumber) {
                case 1: //first betting round
                    //medium aggressive bet
                    bet = bet2player + 3;
                    break;
                case 2: //second betting round
                    //very conservative bet
                    bet = bet2player + 1;
                    break;
                case 3: //third betting round
                    //call
                    bet = bet2player;
                    break;
                default:
                    break;
            }
        } else {
            //call or fold
            bet = 0;
        }
    }
    if (bet > (bet2player + 10)) bet = bet2player + 10;
    if (!canRaise) bet = min(bet, bet2player);
    return bet;

    if (betaScore > opponentScore) {
        if (betaScore > 0.5*(opponentScore + averageCardValue)) {
            //max raise. Take advantage of lead
            bet = bet2player + 10;
        }
        else {
            //call or bet depending on round number
            switch (roundNumber) {
                case 1: //first betting round
                    //aggressive raise
                    bet = bet2player + 7;
                    break;
                case 2: //second betting round
                    //conservative raise
                    bet = bet2player + 3;
                    break;
                case 3: //third betting round
                    //call
                    bet = bet2player;
                    break;
                default:
                    break;
            }
        }
    } else {
        if ((betaScore + 0.5*averageCardValue) > opponentScore) {
            //call or bet small depending on round number
            switch (roundNumber) {
                case 1: //first betting round
                    //medium aggressive bet
                    bet = bet2player + 3;
                    break;
                case 2: //second betting round
                    //very conservative bet
                    bet = bet2player + 1;
                    break;
                case 3: //third betting round
                    //call
                    bet = bet2player;
                    break;
                default:
                    break;
            }
        } else {
            //call or fold
            bet = 0;
        }
    }
    if (bet > (bet2player + 10)) bet = bet2player + 10;
    if (!canRaise) bet = min(bet, bet2player);
    return bet;
   */

    if (betaScore > (opponentScore + averageCardValue)) bet = bet2player + 10;
    else if (betaScore < (opponentScore + averageCardValue)) bet = 0;
    else bet = bet2player + 4;

    if (bet > (bet2player + 10)) bet = bet2player + 10;
    if (!canRaise) bet = min(bet, bet2player);
    return bet;
}