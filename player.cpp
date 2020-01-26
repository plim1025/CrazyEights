#include <iostream>
#include <cstdlib>
#include "card.h"
#include "hand.h"
#include "player.h"

Player::Player() {
    hand = Hand();
    name = "";
}

Player::Player(const Hand &init_hand, string init_name) {
    hand = init_hand;
    name = init_name;
}

Player::~Player() {
    // cout << "Player destroyed" << endl;
};

Hand& Player::get_hand() {
    return hand;
}

string Player::get_name() {
    return name;
}

void Player::set_hand(const Hand &new_hand) {
    hand = new_hand;
}

void Player::set_name(string new_name) {
    name = new_name;
}

void Player::add_card(const Card &new_card) {
    hand.add_card(new_card);
}

void Player::remove_card(int rank, int suit) {
    hand.remove_card(rank, suit);
}

bool Player::check_hand(int rank, int suit) {
    Card *&cards = hand.get_cards();
    for(int i = 0; i < hand.get_n_cards(); i++) {
        if(cards[i].get_rank() == rank || cards[i].get_suit() == suit)
            return true;
    }
    return false;
}