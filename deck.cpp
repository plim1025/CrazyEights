#include "card.h"
#include "deck.h"
#define DECK_SIZE 52

Card* Deck::get_cards() {
    return cards;
}

int Deck::get_n_cards() {
    return n_cards;
}

void Deck::set_cards(Cards* new_cards) {
    for(int i = 0; i < DECK_SIZE; i++)
        cards[i] = new_cards[i];
}

void Deck:set_n_cards(int new_n_cards) {
    n_cards = new_n_cards;
}

// void Deck::deal_card(Hand hand) {
//     hand.add_card(cards[0]);
//     cards[0] = null;
//     n_cards--;
// }