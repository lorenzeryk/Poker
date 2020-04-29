//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_GAME_H
#define POKER_GAME_H
#include<ctime>
#include <chrono>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include "PlayerType.h"
#include "HumanPlayer.h"
#include "AlphaPlayer.h"

using namespace std;
class Game {
public:
    bool playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag);
    int getPlayer1Wins();
    int getPlayer2Wins();
private:
    int handsPlayed = 0;
    const int GAME_LENGTH = 20;
    static Player* createPlayer(PlayerType type, int id, int chips);
    Player* player1;
    Player* player2;
    vector<Card> deckOfCards;
    void endGame();
    void shuffleCards(uniform_real_distribution<double> dist, mt19937 mt);
    void createDeckOfCards();
    static void printCards(bool visibleFlag, Player *player);
    static int biddingRound(int turn, Player *players[2], int& pot, bool reportFlag);
    static int checkRoundWinner(Player* players[2]);
    static int checkGameWinner(Player* players[2]);
    int player1Wins = 0;
    int player2Wins = 0;
};


#endif //POKER_GAME_H
