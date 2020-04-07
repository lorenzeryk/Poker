//
// Created by erykl on 4/6/2020.
//

#include "Player.h"
Player::Player(int id, int chips) {
    this->id = id;
    this->chips = chips;
    hand = Hand();
};

int Player::getID() {
    return id;
};

void Player::clearHand() {
    hand.clear();
};

void Player::dealCard(Card c) {
    if (hand.getCount() == 1) c.setFaceUp(false);
    hand.addCard(c);
};

Hand Player::getHand() {
    return hand;
};

void Player::addChips(int chips) {
    this->chips += chips;
};

int Player::getChips() {
    return chips;
};