#include "card.h"

#ifndef DECK_H
#define DECK_H
#define DECK_SIZE 52

using namespace std;

class Deck {
  private:
    Card cards[DECK_SIZE];
    int n_cards;
  public:
    Deck(Card init_cards[DECK_SIZE]) { // issue is Card wants to call constructor
        for(int i = 0; i < DECK_SIZE; i++)
            cards[i] = init_cards[i];
        n_cards = DECK_SIZE;
    };
    ~Deck() {};
    Card* get_cards();
    int get_n_cards();
    void set_cards(Card *new_cards);
    void set_n_cards(int n_cards);
    //void deal_card(Hand hand);
};

#endif