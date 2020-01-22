#include "card.h"

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