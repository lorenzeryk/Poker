//
// Created by erykl on 4/25/2020.
//

#include "DataTracking.h"
void DataTracking::writeDataToFile() {
    ofstream outputData;

    outputData.open("BlockHeadPokerBeta_VER_1_0.txt", std::ios_base::app);
    if (outputData.is_open()) {

        for (int i = 0; i < roundResult.size(); i++) {
            outputData << roundResult[i] << "," << playerHandScore[i] << "," << opponentHandScore[i] << endl;
        }

    }
    outputData.close();
}

void DataTracking::writeWinnerToFile() {
    ofstream winnerData;
    winnerData.open("WinnerLog.txt", std::ios_base::app);

    if (winnerData.is_open()) {
        for (int i = 0; i < roundResult.size(); i++) {
            winnerData << roundResult[i];
        }
    }
}

void DataTracking::addRoundResult(int ID) {
    roundResult.emplace_back(ID);
}

void DataTracking::addScores(int player1Score, int player2Score) {
    playerHandScore.emplace_back(player1Score);
    opponentHandScore.emplace_back(player2Score);
}