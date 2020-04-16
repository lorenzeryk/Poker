//
// Created by erykl on 4/6/2020.
//

#include "HumanPlayer.h"
int HumanPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canRaise, int pot) {
    int playerBet;

    if (bet2player == 0) {
        cout << "Player " << id + 1 << "'s turn to bet" << endl;
        cout << "Enter '-1' to quit, '0' to call, or a number between '1' and '10' to raise" << endl;
    } else {
        if (canRaise) {
            cout << "Player " << id + 1 << "'s turn to bet" << endl;
            cout << "Enter '-1' to quit, enter '0' to fold, enter '" << bet2player << "' to call, or enter between " << bet2player + 1 << " and 10 to raise"<< endl;
        } else {
            cout << "Player " << id + 1 << "'s turn to bet" << endl;
            cout << "Enter '-1' to quit, enter '0' to fold, or enter " << bet2player << " to call." << endl;
        }
    }

    bool firstRun = true;
    do {
    cin >> playerBet;
    if (!firstRun) {
        cout << "Value entered is not valid. Please enter a valid value" << endl;
        cin >> playerBet;
    }
    firstRun = false;
    } while (playerBet < -1 || playerBet > 10);

    return playerBet;
}