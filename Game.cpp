//
// Created by erykl on 4/6/2020.
//

#include "Game.h"

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag) {
    player1 = createPlayer(p0, 0, chips0);
    player2 = createPlayer(p1, 1, chips1);
    Player* players[2] = {player1, player2};
    int randomCardIndex, biddingRoundReturnValue;
    int pot = 0;

    while (handsPlayed < 20) {
        shuffleCards();
        player1->clearHand();
        player2->clearHand();

        //deal cards to players
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

        cout << "Players giving ante for round. Each player puts in 10 chips" << endl;
        player1->addChips(-10);
        player2->addChips(-10);
        pot += 20;

        do {
            printCards(false, player1);
            printCards(false, player2);
            cout << "The pot is currently " << pot << endl;

            cout << "First bidding round" << endl;
            biddingRoundReturnValue = biddingRound(turn, players, pot);
            if (biddingRoundReturnValue == -1) break;
            if (biddingRoundReturnValue == 1) {
                cout << "Player 1 folded" << endl;
                break;
            }

            //deal cards to players
            for (int i = 0; i < 2; i++) {
                randomCardIndex = rand() % deckOfCards.size();
                players[i]->dealCard(deckOfCards.at(randomCardIndex));
                deckOfCards.erase(deckOfCards.begin() + randomCardIndex);
            }
            printCards(false, player1);
            printCards(false, player2);
            cout << "The pot is currently " << pot << endl;

            cout << "Second bidding round" << endl;
            biddingRoundReturnValue = biddingRound(turn, players, pot);
            if (biddingRoundReturnValue == -1) break;
            if (biddingRoundReturnValue == 1) {
                cout << "Player 1 folded" << endl;
                break;
            }

            for (int i = 0; i < 2; i++) {
                randomCardIndex = rand() % deckOfCards.size();
                players[i]->dealCard(deckOfCards.at(randomCardIndex));
                deckOfCards.erase(deckOfCards.begin() + randomCardIndex);
            }
            printCards(false, player1);
            printCards(false, player2);
            cout << "The pot is currently " << pot << endl;

            cout << "Last bidding round" << endl;
            biddingRoundReturnValue = biddingRound(turn, players, pot);
            if (biddingRoundReturnValue == -1) break;
            if (biddingRoundReturnValue == 1) {
                cout << "Player 1 folded" << endl;
                break;
            }

            printCards(true, player1);
            printCards(true, player2);
            cout << "The round is over. The pot was " << pot << endl;
            break;
        } while (true);

        int winner = checkWinner(players);
        switch (winner) {
            case -1:
                cout << "This round was a tie. The pot will carry over to the next round" << endl;
                break;
            case 0:
                cout << "Player 1 won this round." << endl;
                pot = 0;
                break;
            case 1:
                cout << "Player 2 won this round." << endl;
                pot = 0;
                break;
        }

        if (biddingRoundReturnValue == -1) break;
        handsPlayed++;
    }

    endGame();
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

void Game::printCards(bool visibleFlag, Player *player) {
    cout << "Player " << player->getID() + 1 << " cards:" << endl;
    int a = player->getHand().getCount();
    for (int j = 0; j < player->getHand().getCount(); j++) {
        if (visibleFlag || player->getHand().getCard(j).isFaceUp()) {
            cout << player->getHand().getCard(j).getName() + " ";
        } else {
          cout << "X ";
        }
    }
    cout << endl;
}

int Game::biddingRound(int turn, Player *players[2], int& pot) {
    BetHistory roundHistory = BetHistory();
    bool player1Call = false;
    bool player2Call = false;
    bool fold = false;
    bool canRaise = false;
    int bet;
    int bet2Player = 0, raises = 0;


    do {
    bet = players[turn]->getBet(players[(turn + 1) % 2]->getHand(), roundHistory, bet2Player, canRaise, pot);

    if (bet == -1) {
        return -1;
    } else if (bet == 0) {
        if (canRaise) return 1; //player folded
        else {
            if (turn == 0) player1Call = true;
            else player2Call = true;
            bet2Player = 0;
        }
    } else {
        if (roundHistory.getCount() == 0) {
            canRaise = true;
            raises++;
            roundHistory.addBet(Bet(bet, turn));
            player1Call = false;
            player2Call = false;
            bet2Player = bet;
        } else {
            if (bet2Player == bet) {
                if (turn == 0) player1Call = true;
                else player2Call = true;
                canRaise = false;
                bet2Player = 0;
            } else {
                canRaise = true;
                raises++;
                roundHistory.addBet(Bet(bet, turn));
                player1Call = false;
                player2Call = false;
                bet2Player = bet - bet2Player;
            }
        }
    }

    if (raises == 3) canRaise = false;
    if (raises == 3 && bet2Player == 0) break;
    pot += bet;
    turn = (turn + 1) % 2;
    } while (!fold && (!player1Call || !player2Call));

    return 0;
}

int Game::checkWinner(Player *players[2]) {
    if (players[0]->getHand().evaluate() > players[1]->getHand().evaluate()) {
        return 0;
    } else if (players[0]->getHand().evaluate() < players[1]->getHand().evaluate()) {
        return 1;
    } else return -1; //tie
}