//
// Created by erykl on 4/6/2020.
//

#include "Game.h"

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag) {
    player1 = createPlayer(p0, 0, chips0);
    player2 = createPlayer(p1, 1, chips1);
    Player* players[2] = {player1, player2};
    int randomCardIndex;

    while (handsPlayed < 20) {
        //TODO move to initialization function
        shuffleCards();
        player1->clearHand();
        player2->clearHand();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                randomCardIndex = rand() % deckOfCards.size();
                players[i]->dealCard(deckOfCards.at(randomCardIndex));
                deckOfCards.erase(deckOfCards.begin() + randomCardIndex);
            }
        }

        //set starting player for round
        int turn;
        if (handsPlayed % 2 == 0) turn = 0;
        else turn = 1;

        //TODO add rest of round

        handsPlayed++;
    }

    return true;
}

Player* Game::createPlayer(PlayerType type, int id, int chips) {
    switch(type) {
        case HUMAN:
            return new HumanPlayer(id, chips);
        case ALPHA:
            return new AlphaPlayer(id, chips);
        case BETA:
            break;
    }
}

void Game::endGame() {
    delete player1;
    delete player2;
}

void Game::shuffleCards() {
    deckOfCards.clear();
    createDeckOfCards();

    // Initialize seed randomly
    srand(time(0));
    for (int i=0; i< deckOfCards.size() ;i++) {
        // Random for remaining positions.
        int r = i + (rand() % (52 -i));
        swap(deckOfCards[i], deckOfCards[r]);
    }
}

void Game::createDeckOfCards() {
    //add aces
    for (int i = 0; i < 4; i++) {
        deckOfCards.push_back(Card("Ace", 1));
    }

    //add numbered cards
    for (int i = 2; i < 11; i++) {
        for (int j = 0; j < 4; j++) {
            deckOfCards.push_back(Card(to_string(i), i));
        }
    }

    //add Jacks
    for (int i = 0; i < 4; i++) {
        deckOfCards.push_back(Card("Jack", 10));
    }

    //add Queens
    for (int i = 0; i < 4; i++) {
        deckOfCards.push_back(Card("Queen", 1));
    }

    //add Kings
    for (int i = 0; i < 4; i++) {
        deckOfCards.push_back(Card("Queen", 1));
    }
}
