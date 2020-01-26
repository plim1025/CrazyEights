#ifndef HAND_H
#define HAND_H

#include "card.h"

using namespace std;

class Hand {
  private:
    Card *cards;
    int n_cards;
  public:
    Hand();
    Hand(Card *&init_cards, int init_n_cards);
    ~Hand();
    Card*& get_cards();
    int get_n_cards();
    void set_cards(const Card *&new_cards);
    void set_n_cards(int new_n_cards);
    void add_card(Card &new_card);
    void remove_card(int rank, int suit);
    int get_suit(int index);
    int get_rank(int index);
    void print_hand();
};

#endif