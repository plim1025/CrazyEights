#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "hand.h"
#define DECK_SIZE 52

using namespace std;

class Deck {
  private:
    Card cards[DECK_SIZE];
    int n_cards;
  public:
    Deck();
    Deck(Card init_cards[DECK_SIZE]);
    ~Deck();
    Card* get_cards();
    int get_n_cards();
    void set_cards(Card *new_cards);
    void set_n_cards(int n_cards);
    void print_cards();
    void deal_card(Hand hand);
};

#endif