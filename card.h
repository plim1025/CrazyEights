#ifndef CARD_H
#define CARD_H

using namespace std;

class Card {
  private:
    int rank;
    int suit;
  public:
    Card(int init_rank, int init_suit) {
        rank = init_rank;
        suit = init_suit;
    };
    ~Card() {};
    int get_rank();
    int get_suit();
    void set_rank(int new_rank);
    void set_suit(int new_suit);
};

#endif