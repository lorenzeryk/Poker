//
// Created by erykl on 4/6/2020.
//

#include "Hand.h"
void Hand::clear() {
    hand.clear();
};

void Hand::addCard(Card card) {
    hand.push_back(card);
};
int Hand::getCount() {
    return hand.size();
};

Card Hand::getCard(int n) {
    return hand.at(n);
};

Hand Hand::getVisible() {
    Hand returnHand = Hand();
    for (Card card: hand) {
        if (card.isFaceUp()) returnHand.addCard(card);
    }
    return returnHand;
};

int Hand::evaluate() {
    int value = 0;
    for (Card card: hand) {
        value+= card.getValue();
    }
    return value;
};

void Hand::setCardVisible(bool visible, int n) {
    hand.at(n).setFaceUp(visible);
}