//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_GAME_H
#define POKER_GAME_H
#include<ctime>
#include <vector>
#include <iostream>
#include "PlayerType.h"
#include "HumanPlayer.h"
#include "AlphaPlayer.h"

using namespace std;
class Game {
public:
    bool playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag);

private:
    int handsPlayed = 0;
    const int GAME_LENGTH = 20;
    Player* createPlayer(PlayerType type, int id, int chips);
    Player* player1;
    Player* player2;
    vector<Card> deckOfCards;
    void endGame();
    void shuffleCards();
    void createDeckOfCards();
    void printCards(bool visibleFlag, Player *player);
    int biddingRound(int turn, Player *players[2], int& pot, bool reportFlag);
    int checkRoundWinner(Player* players[2]);
    int checkGameWinner(Player* players[2]);
};


#endif //POKER_GAME_H
