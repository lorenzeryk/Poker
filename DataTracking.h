//
// Created by erykl on 4/25/2020.
//

#ifndef POKER_DATATRACKING_H
#define POKER_DATATRACKING_H

#include <vector>
#include <fstream>

using namespace std;
class DataTracking {
public:
    void writeDataToFile();
    void addRoundResult(int ID);
    void addScores(int player1Score, int player2Score);
    void writeWinnerToFile();
private:
    vector<int> roundResult;
    vector<int> playerHandScore;
    vector<int> opponentHandScore;
    int playerWins;
    int opponentWins;
};


#endif //POKER_DATATRACKING_H
