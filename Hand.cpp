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
//TODO
};

int Hand::evaluate() {
//TODO
};

void Hand::setCardVisible(bool visible, int n) {
    hand.at(n).setFaceUp(visible);
}