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
    Deck(const Card (&init_cards)[DECK_SIZE]);
    ~Deck();
    Card* get_cards();
    int get_n_cards();
    void set_cards(const Card *&new_cards);
    void set_n_cards(int n_cards);
    void print_cards();
    void deal_card(Hand &hand, int num_cards);
    void fill_cards();
    void shuffle_cards();
    void swap_cards(Card *a, Card *b);
};

#endif