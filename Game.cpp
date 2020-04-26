//
// Created by erykl on 4/6/2020.
//
#include "Game.h"
#include "DataTracking.h"
#include "BetaPlayer.h"

bool Game::playGame(PlayerType p0, PlayerType p1, int &chips0, int &chips1, bool reportFlag) {
    player1 = createPlayer(p0, 0, chips0);
    player2 = createPlayer(p1, 1, chips1);
    Player* players[2] = {player1, player2};
    int randomCardIndex;
    int pot = 0;
    handsPlayed = 0;
    bool quitGame = false;
    DataTracking tracking = DataTracking();
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 100000.0);

    while (handsPlayed < GAME_LENGTH) {
        int biddingRoundReturnValue;
        //set up for round
        shuffleCards(dist, mt);
        player1->clearHand();
        player2->clearHand();

        //deal cards to players
        for (auto & player : players) {
            for (int j = 0; j < 3; j++) {
                randomCardIndex = rand() % deckOfCards.size();
                player->dealCard(deckOfCards.at(randomCardIndex));
                deckOfCards.erase(deckOfCards.begin() + randomCardIndex);
            }
        }

        //set starting player for round and get ante
        int turn;
        if (handsPlayed % 2 == 0) turn = 0;
        else turn = 1;

        //get hand starting chips
        if (reportFlag) cout << "Players giving ante for round. Each player puts in 10 chips" << endl;
        player1->addChips(-10);
        player2->addChips(-10);
        pot += 20;

        do {
            if (reportFlag) {
                printCards(false, player1);
                printCards(false, player2);
                cout << endl << "The pot is currently " << pot << endl << endl;
                cout << "First bidding round" << endl;
            }

            //first bidding round
            biddingRoundReturnValue = biddingRound(turn, players, pot, reportFlag);
            if (biddingRoundReturnValue == -1) {
                //quit game
                quitGame = true;
                break;
            }
            if (biddingRoundReturnValue == 1 || biddingRoundReturnValue == 2) {
                if (reportFlag) cout << "Player " << biddingRoundReturnValue << " folded" << endl << endl;
                break;
            }

            //deal additional to players
            for (auto & player : players) {
                randomCardIndex = rand() % deckOfCards.size();
                player->dealCard(deckOfCards.at(randomCardIndex));
                deckOfCards.erase(deckOfCards.begin() + randomCardIndex);
            }

            if (reportFlag) {
                printCards(false, player1);
                printCards(false, player2);
                cout << endl << "The pot is currently " << pot << endl << endl;
                cout << "Second bidding round" << endl;
            }

            //second bidding round
            biddingRoundReturnValue = biddingRound(turn, players, pot, reportFlag);
            if (biddingRoundReturnValue == -1) {
                //quit game
                quitGame = true;
                break;
            }
            if (biddingRoundReturnValue == 0 || biddingRoundReturnValue == 1 ) {
                if (reportFlag) cout << "Player " << biddingRoundReturnValue << " folded" << endl << endl;
                break;
            }

            //deal last card to players
            for (auto & player : players) {
                randomCardIndex = rand() % deckOfCards.size();
                player->dealCard(deckOfCards.at(randomCardIndex));
                deckOfCards.erase(deckOfCards.begin() + randomCardIndex);
            }

            if (reportFlag) {
                printCards(false, player1);
                printCards(false, player2);
                cout << endl << "The pot is currently " << pot << endl;
                cout << "Last bidding round" << endl;
            }

            //final bidding round
            biddingRoundReturnValue = biddingRound(turn, players, pot, reportFlag);
            if (biddingRoundReturnValue == -1) {
                //quit game
                quitGame = true;
                break;
            }
            if (biddingRoundReturnValue == 0 || biddingRoundReturnValue == 1 ) {
                if (reportFlag) cout << "Player " << biddingRoundReturnValue << " folded" << endl << endl;
                break;
            }


            if (reportFlag) {
                printCards(true, player1);
                printCards(true, player2);
                cout << endl << "The round is over. The pot was " << pot << endl;
            }
            break;
        } while (true);

        //check for round winner
        int winner = checkRoundWinner(players);
        switch (winner) {
            case -1:
                tracking.addRoundResult(0);
                if (reportFlag && !quitGame) cout << "This round was a tie. The pot will carry over to the next round" << endl;
                break;
            case 0:
                tracking.addRoundResult(1);
                if (reportFlag && !quitGame) cout << "Player 1 won this round." << endl;
                player1->addChips(pot);
                pot = 0;
                break;
            case 1:
                tracking.addRoundResult(2);
                if (reportFlag && !quitGame) cout << "Player 2 won this round." << endl;
                player2->addChips(pot);
                pot = 0;
                break;
            default:
                cout << "Error in program";
                exit(EXIT_FAILURE);
                break;
        }
        if (reportFlag) {
            cout << "Player 1 has " << player1->getChips() << " chips." << endl;
            cout << "Player 2 has " << player2->getChips() << " chips." << endl;
        }
        if (quitGame) break;
        handsPlayed++;
        tracking.addScores(player1->getHand().evaluate(), player2->getHand().evaluate());
    }

    //check for game winner
    int winner = checkGameWinner(players);
    switch(winner) {
        case -1:
            if (reportFlag) cout << "The game was a tie" << endl;
            break;
        case 1:
            if (reportFlag) cout << "Player 1 won the game" << endl;
            player1Wins++;
            break;
        case 2:
            if (reportFlag) cout << "Player 2 won the game" << endl;
            player2Wins++;
            break;
        default:
            if (reportFlag) cout << "Error in program";
            exit(EXIT_FAILURE);
            break;
    }
    if ((p0 == ALPHA && p1 == BETA) || (p0 == ALPHA && p1 == ALPHA)) {
        tracking.writeDataToFile();
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
            return new BetaPlayer(id, chips);
        default:
            cout << "Failed to create player";
            exit(EXIT_FAILURE);
    }
}

void Game::endGame() {
    delete player1;
    delete player2;
}

void Game::shuffleCards(uniform_real_distribution<double> dist, mt19937 mt) {
    //clear current deck and remake deck
    deckOfCards.clear();
    createDeckOfCards();

    //shuffle the cards
    for (int i=0; i < deckOfCards.size(); i++) {
        // Random for remaining positions.
        int r = i + (static_cast<int>(dist(mt) * 10000.0) % (52 -i));
        swap(deckOfCards[i], deckOfCards[r]);
    }
}

void Game::createDeckOfCards() {
    //add aces
    for (int i = 0; i < 4; i++) {
        deckOfCards.emplace_back("Ace", 1);
    }

    //add numbered cards
    for (int i = 2; i < 11; i++) {
        for (int j = 0; j < 4; j++) {
            deckOfCards.emplace_back(to_string(i), i);
        }
    }

    //add Jacks
    for (int i = 0; i < 4; i++) {
        deckOfCards.emplace_back("Jack", 10);
    }

    //add Queens
    for (int i = 0; i < 4; i++) {
        deckOfCards.emplace_back("Queen", 10);
    }

    //add Kings
    for (int i = 0; i < 4; i++) {
        deckOfCards.emplace_back("King", 10);
    }
}

void Game::printCards(bool visibleFlag, Player *player) {
    cout << endl << "Player " << player->getID() + 1 << " cards:" << endl;
    for (int j = 0; j < player->getHand().getCount(); j++) {
        if (visibleFlag || player->getHand().getCard(j).isFaceUp()) { //check if card is face up or if all cards should be printed
            cout << player->getHand().getCard(j).getName() + " ";
        } else {
          cout << "X ";
        }
    }
    cout << endl;
}

int Game::biddingRound(int turn, Player *players[2], int& pot, bool reportFlag) {
    BetHistory roundHistory = BetHistory();
    bool player1Call = false;
    bool player2Call = false;
    bool fold = false;
    bool canRaise = true;
    int bet;
    int bet2Player = 0, raises = 0;

    do {
    bet = players[turn]->getBet(players[(turn + 1) % 2]->getHand(), roundHistory, bet2Player, canRaise, pot);

    if (bet == -1) {
        return -1; //quit option selected
    } else if (bet == 0) {
        if (bet2Player != 0) return ((turn + 1) % 2); //player folded
        else {
            //set player that called to true
            if (turn == 0) player1Call = true;
            else player2Call = true;
            pot += bet2Player; //add call to pot
        }
    } else {
        if (roundHistory.getCount() == 0) {
            //add bet
            raises++;
            roundHistory.addBet(Bet(bet, turn));

            //set both call booleans to false
            player1Call = false;
            player2Call = false;
        } else {
            if (bet2Player == bet) { //call
                //set corresponding call boolean to true
                if (turn == 0) player1Call = true;
                else player2Call = true;
            } else { //raise
                raises++;
                roundHistory.addBet(Bet(bet, turn));
                player1Call = false;
                player2Call = false;
            }
        }
    }

    players[turn]->addChips(-bet); //take chips from player

    if (reportFlag) {
        if (bet == bet2Player) cout << "Player " << turn + 1 << " called" << endl;
        if (bet > bet2Player) cout << "Player " << turn + 1 << " raised " << bet - bet2Player << endl;
    }

    turn = (turn + 1) % 2;
    bet2Player = bet - bet2Player; //update bet2Player
    if (raises == 3) canRaise = false; //check if max raises reached
    pot += bet; //update pot
    if (raises == 3 && bet2Player == 0) break; //check if round is over
    } while (!fold && (!player1Call || !player2Call));

    if (reportFlag) cout << "The bidding round is over" << endl;
    return 2;
}

int Game::checkRoundWinner(Player *players[2]) {
    //return ID of player that won
    if (players[0]->getHand().evaluate() > players[1]->getHand().evaluate()) {
        return 0;
    } else if (players[0]->getHand().evaluate() < players[1]->getHand().evaluate()) {
        return 1;
    } else return -1; //tie
}

int Game::checkGameWinner(Player **players) {
    if (players[0]->getChips() > players[1]->getChips()) {
        return 1;
    }
    if (players[1]->getChips() > players[0]->getChips()) {
        return 2;
    }
    else return -1;
}

int Game::getPlayer1Wins() {
    return player1Wins;
}

int Game::getPlayer2Wins() {
    return player2Wins;
}