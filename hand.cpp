#include <iostream>
#include "card.h"
#include "hand.h"

Hand::Hand() {
    cards = nullptr;
    n_cards = 0;
}

Hand::Hand(Card *&init_cards, int init_n_cards) {
    cards = new Card[init_n_cards];
    for(int i = 0; i < init_n_cards; i++) {
        cards[i].set_rank(init_cards[i].get_rank());
        cards[i].set_suit(init_cards[i].get_suit());
    }
    n_cards = init_n_cards;
}

Hand::~Hand() {
    //cout << "Hand destroyed" << endl;
    Card **cards_ptr = &cards;
    delete [] *cards_ptr;
    *cards_ptr = NULL;
}

Card*& Hand::get_cards() {
    return cards;
}

int Hand::get_n_cards() {
    return n_cards;
}

void Hand::set_cards(const Card *&new_cards) {
    for(int i = 0; i < n_cards; i++)
        cards[i] = new_cards[i];
}

void Hand::set_n_cards(int new_n_cards) {
    n_cards = new_n_cards;
}

void Hand::add_card(const Card &new_card) {
    // Create new array 1 size bigger
    Card *new_cards = new Card[n_cards + 1];
    // Copy over values to new array from old
    for(int i = 0; i < n_cards; i++)
        new_cards[i] = cards[i];
    // Add new card to new array
    new_cards[n_cards] = new_card;
    // Delete old array
    Card **cards_ptr = &cards;
    delete [] *cards_ptr;
    *cards_ptr = NULL;
    // Make member variable point to new array
    cards = new_cards;
    // Increase number of cards
    n_cards++;
}

void Hand::remove_card(int rank, int suit) {
    // Find card that user want to remove and set it to null
    bool card_reset = false;
    for(int i = 0; i < n_cards; i++) {
        if(cards[i].get_rank() == rank && cards[i].get_suit() == suit) {
            cards[i].reset_card();
            card_reset = true;
            break;
        }
    }
    if(!card_reset) {
        cout << "Card not found" << endl;
        return;
    }
    // Create new array 1 size smaller
    Card *new_cards = new Card[n_cards - 1];
    // Copy over values to new array from old - check if null and skip if is
    int cards_copied = 0;
    int card_index = 0;
    while(card_index <= n_cards) {
        if(cards[card_index].is_valid_card()) {
            new_cards[cards_copied] = cards[card_index];
            cards_copied++;
        }
        card_index++;
    }
    // Delete old array
    Card **cards_ptr = &cards;
    delete [] *cards_ptr;
    *cards_ptr = NULL;
    // Make member variable point to new array
    cards = new_cards;
    // Lower number of cards in hand
    n_cards--;
}

int Hand::get_suit(int index) {
    return cards[index].get_suit();
}

int Hand::get_rank(int index) {
    return cards[index].get_rank();
}

void Hand::print_hand() {
    cout << "Number of cards: " << n_cards << endl;
    for(int i = 0; i < n_cards; i++)
        cout << "(" << i+1 << ") " << "Rank: " << cards[i].get_string_rank() << ", " << "Suit: " << cards[i].get_string_suit() << endl;
}