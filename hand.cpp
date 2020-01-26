#include <iostream>
#include "card.h"
#include "hand.h"

Hand::Hand() {
    cards = NULL;
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

void Hand::add_card(Card &new_card) {
    Card **cards_ptr = &cards;
    // Create new array 1 size bigger
    Card *new_cards = new Card[n_cards + 1];
    // Copy over values to new array from old
    for(int i = 0; i < n_cards; i++) {
        new_cards[i].set_rank((*cards_ptr)[i].get_rank());
        new_cards[i].set_suit((*cards_ptr)[i].get_suit());
    }
    // Add new card to new array
    new_cards[n_cards].set_rank(new_card.get_rank());
    new_cards[n_cards].set_suit(new_card.get_suit());
    // Delete old array
    delete [] *cards_ptr;
    *cards_ptr = NULL;
    // Make member variable point to new array
    *cards_ptr = new_cards;
    // Increase number of cards
    n_cards++;
}

void Hand::remove_card(int rank, int suit) {
    Card **cards_ptr = &cards;
    // Create new array 1 size smaller
    Card *new_cards = new Card[n_cards - 1];

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
    // Copy over values to new array from old - check if null and skip if is
    int cards_copied = 0;
    int card_index = 0;
    while(card_index < n_cards) {
        if(cards[card_index].is_valid_card()) {
            new_cards[cards_copied].set_rank((*cards_ptr)[card_index].get_rank());
            new_cards[cards_copied].set_suit((*cards_ptr)[card_index].get_suit());
            cards_copied++;
        }
        card_index++;
    }

    // Delete old array
    delete [] *cards_ptr;
    *cards_ptr = NULL;
    // Make member variable point to new array
    *cards_ptr = new_cards;
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
    cout << endl << "Your hand: " << endl;
    cout << "Number of cards: " << n_cards << endl;
    for(int i = 0; i < n_cards; i++)
        cout << "(" << i+1 << ") " << "Rank: " << cards[i].get_string_rank() << ", " << "Suit: " << cards[i].get_string_suit() << endl;
    cout << endl;
}
