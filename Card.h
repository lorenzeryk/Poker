//
// Created by erykl on 4/6/2020.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H
#include <string>

using namespace std;
class Card {
public:
    Card(string cardName, int cardValue);
    string getName();
    int getValue();
    bool isFaceUp();
    void setFaceUp(bool isFaceUp);

private:
    string cardName;
    int cardValue;
    bool faceUp;
};


#endif //POKER_CARD_H
