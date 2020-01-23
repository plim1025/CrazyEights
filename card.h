#ifndef CARD_H
#define CARD_H

using namespace std;

class Card {
  private:
    int rank;
    int suit;
  public:
    Card();
    Card(int init_rank, int init_suit);
    ~Card();
    int get_rank();
    int get_suit();
    void set_rank(int new_rank);
    void set_suit(int new_suit);
    void reset_card();
    bool is_valid_card();
};

#endif