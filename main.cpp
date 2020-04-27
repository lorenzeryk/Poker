#include <iostream>
#include "Game.h"

using namespace std;

string playerTypeToString(PlayerType type);

int main() {
    int chipStartingValue = 1000;
    int playerSelect = -1;
    PlayerType player1;
    PlayerType player2;
    bool report;
    int monteCarloGames = -1;

    Game game = Game();
    cout << "Welcome to Blockhead Poker!" << endl;
    cout << "Select the type of player for Player 1" << endl;
    do {
        cout << "Enter 1 for human, enter 2 for the Alpha AI, enter 3 for the Beta AI, or enter 4 for the Gamma AI" << endl;
        cin >> playerSelect;
        if (cin.fail() || playerSelect > 4 || playerSelect < 1) {
            cout << "Input not valid. Please enter a valid option" << endl;
            cin.clear();
            cin.ignore();
        } else break;
    } while (true);

    switch (playerSelect) {
        case 1:
            player1 = HUMAN;
            break;
        case 2:
            player1 = ALPHA;
            break;
        case 3:
            player1 = BETA;
            break;
        case 4:
            player1 = GAMMA;
            break;
    }

    cout << "Select the type of player for Player 2" << endl;
    do {
        cout << "Enter 1 for human, enter 2 for the Alpha AI, enter 3 for the Beta AI, or enter 4 for the Gamma AI" << endl;
        cin >> playerSelect;
        if (cin.fail() || playerSelect > 4 || playerSelect < 1) {
            cout << "Input not valid. Please enter a valid option" << endl;
            cin.clear();
            cin.ignore();
        } else break;
    } while (true);

    switch (playerSelect) {
        case 1:
            player2 = HUMAN;
            break;
        case 2:
            player2 = ALPHA;
            break;
        case 3:
            player2 = BETA;
            break;
        case 4:
            player2 = GAMMA;
            break;
    }

    bool firstInput = true;
    string reportFlagSelect;
    cout << "Do you want the output printed to the console?" << endl;

    do {
        if (!firstInput) {
            cout << "Input not understood. Please enter 'y', 'n', 'yes' or 'no'";
        }
        cin >> reportFlagSelect;
        firstInput = false;
        for (char letter: reportFlagSelect) {
            tolower(letter);
        }
    } while (reportFlagSelect != "y" && reportFlagSelect != "yes" && reportFlagSelect != "n" && reportFlagSelect != "no");

    report = reportFlagSelect == "y" || reportFlagSelect == "yes";

    if (player1 != HUMAN && player2 != HUMAN) {
        cout << "How many games do you want played for the Monte Carlo simulation?" << endl;
        do {
            cin >> monteCarloGames;
            if (cin.fail() || monteCarloGames < 1) {
                cout << "Input not valid. Please enter a number greater than 0" << endl;
                cin.clear();
                cin.ignore();
            } else break;
        } while (true);
    } else monteCarloGames = 1;

    for (int i = 0; i < monteCarloGames; i++) {
        if (game.playGame(player1, player2, chipStartingValue, chipStartingValue, report))break;
    }

    if (monteCarloGames > 1) {
        cout << playerTypeToString(player1) << " won " << game.getPlayer1Wins() << " games" << endl;
        cout << playerTypeToString(player2) << " won " << game.getPlayer2Wins() << " games" << endl;
    }
    return 0;
}

string playerTypeToString(PlayerType type) {
    switch (type) {
        case HUMAN:
            return "Human player";
            break;
        case ALPHA:
            return "Alpha AI";
            break;
        case BETA:
            return "Beta AI";
            break;
        case GAMMA:
            return "Gamma AI";
            break;
        default:
            cout << "Failed to convert PlayerType to text";
            exit(EXIT_FAILURE);
    }
}