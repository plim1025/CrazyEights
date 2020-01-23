#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#define DECK_SIZE 52

Deck::Deck() {
    for(int i = 0; i < DECK_SIZE; i++) {
        Card new_card = Card();
        cards[i] = new_card;
    }
    n_cards = DECK_SIZE;
}

Deck::Deck(Card init_cards[DECK_SIZE]) {
    for(int i = 0; i < DECK_SIZE; i++)
        cards[i] = init_cards[i];
    n_cards = DECK_SIZE;
}

Deck::~Deck() {}

Card* Deck::get_cards() {
    return cards;
}

int Deck::get_n_cards() {
    return n_cards;
}

void Deck::set_cards(Card* new_cards) {
    for(int i = 0; i < DECK_SIZE; i++)
        cards[i] = new_cards[i];
}

void Deck::set_n_cards(int new_n_cards) {
    n_cards = new_n_cards;
}

void Deck::print_cards() {
    for(int i = 0; i < DECK_SIZE; i++)
        cout << cards[i].get_rank() << " " << cards[i].get_suit() << endl;
}

void Deck::deal_card(Hand hand) {
    int card_index = 0;
    // Find first non-empty card
    for(int i = 0; i < DECK_SIZE; i++) {
        if(cards[i].is_valid_card()) {
            card_index = i;
            break;
        }
    }
    // Add card to given hand
    hand.add_card(cards[card_index]);
    // Take first card off deck
    cards[card_index].reset_card();
    n_cards--;
}