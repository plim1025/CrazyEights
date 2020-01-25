#include <iostream>
#include "card.h"

Card::Card() {
    rank = 0;
    suit = 0;
}

Card::Card(int init_rank, int init_suit) {
    rank = init_rank;
    suit = init_suit;
}

Card::~Card() {
    cout << "Card Destroyed" << endl;
}

int Card::get_rank() {
    return rank;
}

int Card::get_suit() {
    return suit;
}

void Card::set_rank(int new_rank) {
    rank = new_rank;
}

void Card::set_suit(int new_suit) {
    suit = new_suit;
}

void Card::reset_card() {
    rank = -1;
    suit = -1;
}

bool Card::is_valid_card() {
    return !(rank == -1 || suit == -1);
}