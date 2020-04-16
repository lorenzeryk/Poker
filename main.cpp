#include <iostream>
#include "Game.h"

using namespace std;
int main() {
    int chipStartingValue = 1000;
    int gameMode = -1;

    cout << "Welcome to Blockhead Poker!" << endl;
    cout << "Enter 0 to play in two player mode. Enter 1 to play against an AI. Enter 2 for a Monte Carlo Simulator" << endl;

    while (gameMode > 1 || gameMode < 0) {
        Game game = Game();
        cin >> gameMode;

        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Please enter a 0, 1, or 2" << endl;
            cin >> gameMode;
        }

        switch (gameMode) {
            case 0:
                if (game.playGame(HUMAN, HUMAN, chipStartingValue, chipStartingValue, true)) break;
            case 1:
                if (game.playGame(HUMAN, ALPHA, chipStartingValue, chipStartingValue, true)) break;
            case 2:
                cout << "Sorry this feature has not been implemented yet. Please enter a 0, 1, or 2" << endl;
                break;
            default:
                cout << "Please enter 0, 1, or 2" << endl;
        }
        cout << "Enter 'y' if you want to play again. Enter anything else if you don't want to play again" << endl;
        string playAgain;
        cin >> playAgain;
        if (playAgain != "y") break;
    }
    return 0;
}