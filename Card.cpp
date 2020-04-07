//
// Created by erykl on 4/6/2020.
//

#include "Card.h"
Card::Card(string cardName, int cardValue) {
    this->cardName = cardName;
    this->cardValue = cardValue;
    faceUp;
}

string Card::getName() {
    return cardName;
}

int Card::getValue() {
    return cardValue;
}

bool Card::isFaceUp() {
    return faceUp;
}

void Card::setFaceUp(bool isFaceUp) {
    faceUp = isFaceUp;
}