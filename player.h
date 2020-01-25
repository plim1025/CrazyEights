#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hand.h"

using namespace std;

class Player {
  private:
    Hand hand;
    string name;
  public:
    Player();
    Player(const Hand &init_hand, string init_name);
    ~Player();
    Hand get_hand();
    string get_name();
    void set_hand(const Hand &new_hand);
    void set_name(string new_name);
    void add_card(const Card &new_card);
    void remove_card(int rank, int suit);
    bool check_hand(int rank, int suit);
    int ask_suit();
};

#endif